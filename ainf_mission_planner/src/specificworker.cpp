 /*
 *    Copyright (C) 2026 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "specificworker.h"
#include <algorithm>
#include <limits>
#include <QtMath>
#include <QSettings>

using json = nlohmann::json;

SpecificWorker::SpecificWorker(const ConfigLoader& configLoader, TuplePrx tprx, bool startup_check) : GenericWorker(configLoader, tprx)
{
	this->startup_check_flag = startup_check;
	if(this->startup_check_flag)
	{
		this->startup_check();
	}
	else
	{
		#ifdef HIBERNATION_ENABLED
			hibernationChecker.start(500);
		#endif
		
		statemachine.setChildMode(QState::ExclusiveStates);
		statemachine.start();

		auto error = statemachine.errorString();
		if (error.length() > 0){
			qWarning() << error;
			throw error;
		}
	}
}

SpecificWorker::~SpecificWorker()
{
	QSettings settings("robocomp", "ainf_mission_planner");
	settings.setValue("window/geometry", this->saveGeometry());
	std::cout << "Destroying SpecificWorker" << std::endl;
}


void SpecificWorker::initialize()
{
    std::cout << "initialize worker" << std::endl;

	viewer = new AbstractGraphicViewer(this->frame, QRectF(-8, -8, 16, 16), true);
	viewer->add_robot(0.46f, 0.48f, 0.0f, 0.2f, QColor("Blue"));
	viewer->show();
	connect(viewer, &AbstractGraphicViewer::new_mouse_coordinates, this, &SpecificWorker::slot_new_target);

	connect(pushButton_startFollow, &QPushButton::clicked, this, [this]()
	{
		if(not has_target)
		{
			qWarning() << "No target selected. Shift+Right click on the map first.";
			return;
		}
		try
		{
			navigator_proxy->gotoPoint(last_target);
			qInfo() << "Path following started toward" << last_target.x << last_target.y;
		}
		catch(const Ice::Exception &e)
		{
			qWarning() << "Error starting path following:" << e.what();
		}
	});

	connect(pushButton_stopFollow, &QPushButton::clicked, this, [this]()
	{
		try
		{
			navigator_proxy->stop();
			qInfo() << "Path following stopped";
		}
		catch(const Ice::Exception &e)
		{
			qWarning() << "Error stopping path following:" << e.what();
		}
	});

	connect(pushButton_resumeFollow, &QPushButton::clicked, this, [this]()
	{
		try
		{
			navigator_proxy->resume();
			qInfo() << "Path following resumed";
		}
		catch(const Ice::Exception &e)
		{
			qWarning() << "Error resuming path following:" << e.what();
		}
	});

	//connect(object_prompt, &QTextEdit::textChanged, this, &SpecificWorker::on_text_change);
	connect(object_prompt, &QLineEdit::returnPressed, this, &SpecificWorker::on_text_change);

	QSettings settings("robocomp", "ainf_mission_planner");
	if(settings.contains("window/geometry"))
		this->restoreGeometry(settings.value("window/geometry").toByteArray());

	try
	{
		const auto map_data = navigator_proxy->getLayout();

		auto draw_polyline = [this](const RoboCompNavigator::TLayout &polyline, const QPen &pen)
		{
			if(polyline.size() < 2)
				return;

			for(size_t i = 0; i < polyline.size() - 1; ++i)
			{
				const auto &p1 = polyline[i];
				const auto &p2 = polyline[i + 1];
				viewer->scene.addLine(QLineF(p1.x, p1.y, p2.x, p2.y), pen);
			}
			const auto &first = polyline.front();
			const auto &last = polyline.back();
			viewer->scene.addLine(QLineF(last.x, last.y, first.x, first.y), pen);
		};

		draw_polyline(map_data.layout, QPen(QColor("magenta"), 0.16));

		for(size_t i = 0; i < map_data.objects.size(); ++i)
		{
			const auto &obj = map_data.objects[i];
			const QColor object_color = QColor::fromHsv(static_cast<int>((i * 47) % 360), 210, 230);

			if(obj.layout.size() >= 3)
			{
				QPolygonF polygon;
				polygon.reserve(static_cast<int>(obj.layout.size()));
				for(const auto &point : obj.layout)
					polygon << QPointF(point.x, point.y);

				viewer->scene.addPolygon(polygon,
				                         QPen(object_color, 0.07),
				                         QBrush(object_color, Qt::SolidPattern));
			}
			else
			{
				draw_polyline(obj.layout, QPen(object_color, 0.07));
			}

			if(not obj.layout.empty())
			{
				const auto &p = obj.layout.front();
				auto *text = viewer->scene.addText(QString::fromStdString(obj.name));
				QFont font = text->font();
				font.setBold(true);
				text->setFont(font);
				text->setDefaultTextColor(QColor("black"));
				text->setTransform(QTransform::fromScale(0.012, -0.012));
				text->setPos(p.x, p.y);
				text->setZValue(120);
			}
		}

		if(not map_data.layout.empty())
		{
			float min_x = std::numeric_limits<float>::max();
			float max_x = std::numeric_limits<float>::lowest();
			float min_y = std::numeric_limits<float>::max();
			float max_y = std::numeric_limits<float>::lowest();

			for(const auto &p : map_data.layout)
			{
				min_x = std::min(min_x, p.x);
				max_x = std::max(max_x, p.x);
				min_y = std::min(min_y, p.y);
				max_y = std::max(max_y, p.y);
			}

			auto *legend = viewer->scene.addText("Room: magenta (thick) | Objects: unique filled colors");
			legend->setDefaultTextColor(QColor("darkBlue"));
			legend->setTransform(QTransform::fromScale(0.02, -0.02));
			legend->setPos(min_x, max_y + 0.15f);

			viewer->fitToScene(QRectF(min_x, min_y, max_x - min_x, max_y - min_y));
		}
	}
	catch(const Ice::Exception &e)
	{
		qWarning() << "Error requesting map from Navigator:" << e.what();
	}

    /////////GET PARAMS, OPEND DEVICES....////////
    //int period = configLoader.get<int>("Period.Compute") //NOTE: If you want get period of compute use getPeriod("compute")
    //std::string device = configLoader.get<std::string>("Device.name") 

}

json SpecificWorker::getJson()
{
	// 1. Initialize as an object, not an array
	json j = json::object();

	RoboCompNavigator::TObjects objetos = navigator_proxy->getLayout().objects;
	for (const auto &obj : objetos) // Use const auto& to avoid unnecessary copies
	{
		// 2. Initialize the entry for this object as an array
		j[obj.name] = json::array();

		for (const auto &p : obj.layout)
		{
			// 3. Now you can push coordinates into that specific object's array
			j[obj.name].push_back({ {"x", p.x}, {"y", p.y} });
		}
	}

	return j;
}



void SpecificWorker::compute()
{
	if(viewer == nullptr or viewer->robot_poly() == nullptr)
		return;

	try
	{
		const auto pose = navigator_proxy->getRobotPose();
		viewer->robot_poly()->setPos(pose.x, pose.y);
		viewer->robot_poly()->setRotation(qRadiansToDegrees(pose.r));
		if(not planned_path_points.empty())
			redraw_planned_path(RoboCompNavigator::TPoint{pose.x, pose.y});
		label_robotCoordsValue->setText(QString("x=%1  y=%2  θ=%3")
		                               .arg(pose.x, 0, 'f', 2)
		                               .arg(pose.y, 0, 'f', 2)
		                               .arg(pose.r, 0, 'f', 2));

	}
	catch(const Ice::Exception &e) { qWarning() << "Error requesting robot pose from Navigator:" << e.what(); }	
	try
	{
		auto status = navigator_proxy->getStatus();
		QString state_text = "UNKNOWN";
		switch(status.state)
		{
			case RoboCompNavigator::NavigationState::IDLE: state_text = "IDLE";
				process_mission_list();
				break;
			case RoboCompNavigator::NavigationState::NAVIGATING: state_text = "NAVIGATING";
				navigated = true;
				break;
			case RoboCompNavigator::NavigationState::PAUSED: state_text = "PAUSED"; break;
			case RoboCompNavigator::NavigationState::REACHED: state_text = "REACHED"; break;
			case RoboCompNavigator::NavigationState::BLOCKED: state_text = "BLOCKED"; break;
			case RoboCompNavigator::NavigationState::ERROR: state_text = "ERROR"; break;
		}
		if(not status.statusMessage.empty())
		{
			state_text += QString(" (%1)").arg(QString::fromStdString(status.statusMessage));
		}
		label_missionStatusValue->setText(state_text);

		label_distanceToTargetValue->setText(QString::number(status.distanceToTarget, 'f', 2));
		label_etaValue->setText(QString::number(status.estimatedTime, 'f', 2));
		label_currentSpeedValue->setText(QString::number(status.currentSpeed, 'f', 2));
	}
	catch(const Ice::Exception &e)
	{
		qWarning() << "Error requesting mission status from Navigator:" << e.what();
		if(label_missionStatusValue->text().isEmpty())
			label_missionStatusValue->setText("IDLE");
		label_distanceToTargetValue->setText("--");
		label_etaValue->setText("--");
		label_currentSpeedValue->setText("--");
	}
}

////////////////////////////////////////////////////////////////////////////////


void SpecificWorker::on_text_change()
{
	json j = getJson();
	std::string json_string = j.dump();

	qInfo() << "CAJA DE TEXTO" << object_prompt->text();

	std::string sistema = "Eres un controlador de robot. Te vamos a dar una lista de objetos con sus coordenadas. "
	"Vas a recibir unas coordenadas o el nombre aproximado de un objeto y tienes que devolver "
	"SOLO el nombre del objeto, o de los objetos, más próximos a esas coordenadas o nombre. Devolverás más de un objeto en caso de que se te pida "
	"un recorrido que pase por varios puntos. En caso de devolver una lista de IDs, devuelvelos separados por ;"
	"Adicionalmente, es posible que se te pida que, tras llegar a un objeto, el robot haga alguna acción. En tal caso, concatena al final"
	"de cada ID, una letra que indique la acción a realizar (separada del resto del ID con '-'). De momento, las acciones que hay disponibles son:"
	"Hacer una foto -> concatena '-f' al final del nombre del objeto"
	"Esas son todas las acciones. A continuación la lista de objetos"
    "Lista de objetos: " + json_string + " Responde SOLO el ID o los IDs separados por ; y la letra de la accion correspondiente concatenada al final de cada ID";
	std::string prompt = object_prompt->text().toStdString();
	ollama_thread = std::async(std::launch::async, [this, prompt, sistema]() {

		ollama::request req("gpt-oss:120b-cloud", sistema + prompt, nullptr, false);
		// Realizamos la generación
		ollama::response respuesta;
		try {
			respuesta = ollama::generate(req);
		}
		catch (const std::exception& e){qCritical()<<"Error en el hilo de Ollama: "<<e.what();}

		std::string respuestaStr = respuesta.as_simple_string();
		interpret_ollama_output_string(respuestaStr);
	});

}

void SpecificWorker::interpret_ollama_output_string(std::string& respuestaStr) {

	std::cout << "Destino del robot: " << respuestaStr << std::endl;
	// Limpieza previa: Ollama suele meter saltos de línea al principio/final
	respuestaStr.erase(0, respuestaStr.find_first_not_of(" \n\r\t"));
	respuestaStr.erase(respuestaStr.find_last_not_of(" \n\r\t") + 1);

	if (respuestaStr.empty()) {
		qWarning() << "Ollama devolvió una respuesta vacía";
		return;
	}

	auto split_view = respuestaStr | std::views::split(';');
	for (auto&& part: split_view) {
		std::string s(part.begin(), part.end());
		if (!s.empty()) {
			qDebug()<<"Meto en pending missions lo siguiente: "<<QString::fromStdString(s);
			process_mission(s);
		}
	}
	//qInfo()<<"Cola de misiones cargada con: "<<pending_missions.size()<<" misiones";
}

void SpecificWorker::process_mission(std::string& mission) {
	char target = '-';
	size_t i = mission.find(target);
	std::list<char> actions_todo;
	if (i!=std::string::npos) {
		qDebug()<<"Hay misiones adicionales tras llegar";
		while (i < mission.length()) {
			switch (mission.at(i)) {
				case 'f':
					try{
						actions_todo.push_back(mission.at(i));
					}catch (const Ice::Exception& e){qInfo()<<e.what();}
					break;
				default:
					break;
			}
			mission.erase(i, 1);
		}
		qDebug()<<"El string que queda es: "<<QString::fromStdString(mission);
	}
	else{
		qDebug()<<"No hay misiones adicionales tras llegar al punto";
	}
	//navigator_proxy->gotoObject(mission);
	missions_list.push_back({mission, actions_todo});
}

void SpecificWorker::save_image(const RoboCompImageSegmentation::TImage& datos_imagen, const std::string& nombre_archivo) {

	// 1. Crear el cv::Mat apuntando a los datos de la estructura
	// CV_8UC3 es para imágenes RGB (8 bits, Unsigned, 3 Canales)
	// Si la imagen es en escala de grises, usa CV_8UC1
	cv::Mat img_opencv(
		datos_imagen.height,
		datos_imagen.width,
		CV_8UC3,
		(void*)datos_imagen.image.data()
	);

	// 2. IMPORTANTE: OpenCV usa BGR por defecto, RoboComp suele usar RGB.
	// Si los colores salen invertidos (caras azules), necesitas convertirlo:
	cv::Mat img_bgr;
	cv::cvtColor(img_opencv, img_bgr, cv::COLOR_RGB2BGR);

	// 3. Guardar en disco (el formato se decide por la extensión: .jpg, .png, etc.)
	bool resultado = cv::imwrite(nombre_archivo, img_bgr);

	if(resultado) {
		std::cout << "Imagen guardada con éxito: " << nombre_archivo << std::endl;
	} else {
		std::cerr << "Error al guardar la imagen." << std::endl;
	}
}

void SpecificWorker::process_mission_list() {
	RoboCompImageSegmentation::TData data;
	std::string path = "/home/xeihtt/Rob-Avanzada/images/"; //Path donde guardaremos la imagen

	if (navigated) {
		navigated = false;
		if (!missions_list.empty()) { //Si la lista de misiones no esta vacia pero estoy IDLE es porque tengo una pendiente
			Mission mision_acabada = missions_list.front();
			missions_list.pop_front();
			std::string nombre_sucio = mision_acabada.target; //Nos hacemos una copia del nombre
			for (const auto& c: mision_acabada.actions) { //Procesamos las acciones tras llegar
				switch (c) {
					case 'f':
						try{
							RoboCompNavigator::TObject target = this->getTargetObject(nombre_sucio, navigator_proxy->getLayout().objects);
							bool res = this->alignRobotWithTarget(target);
							while (res) {
								res = this->alignRobotWithTarget(target);
							}

							qDebug()<<"Haciendo foto...";
							data = this->imagesegmentation_proxy->getAll(false);
							if (data.image.image.empty())
								qDebug()<<"Esta vacia la foto";

							nombre_sucio.erase(std::remove(nombre_sucio.begin(), nombre_sucio.end(), ' '), nombre_sucio.end());
							save_image(data.image, path+nombre_sucio+".jpg"); //Por defecto las guardamos con extension jpg

						}catch (const Ice::Exception& e){qInfo()<<e.what();}
						break;
					default:
						break;
				}
			}
			if (!missions_list.empty()) {
				Mission siguiente = missions_list.front();
				navigator_proxy->gotoObject(siguiente.target);
			}
		}
	}
	else if (!missions_list.empty()) {
		Mission siguiente = missions_list.front();
		navigator_proxy->gotoObject(siguiente.target);
	}


}

RoboCompNavigator::TObject SpecificWorker::getTargetObject
(const std::string& obj, const RoboCompNavigator::TObjects& objects) {
	for (const RoboCompNavigator::TObject& o: objects) {
		qDebug()<<"El objeto actual es: "<<QString::fromStdString(o.name);
		if (o.name == obj){
			qDebug()<<"Bingo! objeto: "<<QString::fromStdString(obj)<< " encontrado";
			return o;
		}
	}
}

bool SpecificWorker::alignRobotWithTarget(const RoboCompNavigator::TObject& target) {
    if (target.layout.empty()) return false;

    // 1. Obtener la pose actual del robot
    const auto pose = navigator_proxy->getRobotPose(); // x, y en mm o m, r en rad

    // 2. Centroide en coordenadas del mundo

	Eigen::Vector2f suma = Eigen::Vector2f::Zero();
	for (const auto& p : target.layout) {
		suma+=Eigen::Vector2f(p.x, p.y);
	}
	Eigen::Vector2f world_centroid = suma / static_cast<float>(target.layout.size());

    // 3. Crear la transformación usando Eigen de forma estricta
    // Isometry2f combina rotación y traslación en una matriz 3x3 interna
    Eigen::Isometry2f robot_in_world = Eigen::Isometry2f::Identity();
    robot_in_world.translate(Eigen::Vector2f(pose.x, pose.y));
    robot_in_world.rotate(Eigen::Rotation2Df(pose.r));

    // Queremos el punto del mundo expresado DESDE el robot (World -> Local)
    Eigen::Vector2f local_centroid = robot_in_world.inverse() * world_centroid;

    // 4. Calcular el error angular
    // atan2(y, x) devuelve el ángulo hacia el punto.
    // Si el punto está a la izquierda, y es positivo -> ángulo positivo -> giro izquierda.
    float error_angulo = std::atan2(local_centroid.x(), local_centroid.y());
	qDebug()<<"El error calculado es: "<<error_angulo;
	qDebug()<<"El punto centroide calculado es: "<<world_centroid.x()<<"///"<<world_centroid.y();

    // 5. Control
    const float TOLERANCIA = 0.05f; // ~3 grados
    if (std::abs(error_angulo) > TOLERANCIA) {
       // Control P: Limitamos la velocidad máxima para evitar oscilaciones
       float v_angular = error_angulo * 0.6f;

       // Saturación de velocidad (ajusta según tu robot)
       v_angular = std::clamp(v_angular, -0.5f, 0.5f);

       this->omnirobot_proxy->setSpeedBase(0, 0, v_angular);
       return true; // Sigue necesitando alineación
    } else {
       this->omnirobot_proxy->setSpeedBase(0, 0, 0);
       return false; // Ya está alineado
    }
}

std::string SpecificWorker::gemma_process_image(const std::string& path, const std::string& obj) {

	std::string sistema =
	"ACTÚA COMO UN SENSOR DE ENCUADRE PARA UN ROBOT.\n"
	"Tu prioridad absoluta es que el objeto [" + obj + "] esté CENTRADO HORIZONTALMENTE.\n\n"

	"JERARQUÍA DE DECISIÓN (Sigue este orden):\n"
	"1. ¿El objeto está cortado por el borde IZQUIERDO? -> Responde 'LEFT'.\n"
	"2. ¿El objeto está cortado por el borde DERECHO? -> Responde 'RIGHT'.\n"
	"3. ¿El objeto está muy desplazado a un lado (aunque no esté cortado)? -> Responde 'LEFT' o 'RIGHT' según corresponda.\n"
	"4. ¿El objeto está centrado pero se ve muy pequeño? -> Responde 'ADVANCE'.\n"
	"5. ¿El objeto está centrado y ocupa la mayor parte de la imagen sin cortarse? -> Responde 'STOP'.\n\n"

	"REGLA DE ORO: No respondas 'ADVANCE' si el objeto no está primero centrado.\n"
	"RESPUESTA: Solo una palabra (LEFT, RIGHT, ADVANCE, BACK o STOP).";
	std::string prompt = "¿Qué acciones tendría que realizar el robot para que el objeto: "+ obj + " de esta imagen salga entero?";
	std::future<std::string> ollama_future = std::async(std::launch::async, [this, sistema, prompt, path]() {
		try {
			qDebug() << "1. Iniciando proceso...";
			ollama::image img = ollama::image::from_file(path);

			std::vector<ollama::image> images_vec = { img };

			qDebug() << "2. Construyendo request...";
			ollama::request req("gemma4:31b-cloud", sistema + "\n" + prompt, nullptr, false);
			req["images"]= images_vec;

			qDebug() << "3. Generando (esperando a la nube)...";
			ollama::response respuesta = ollama::generate(req);
			std::string respuestaStr = respuesta.as_simple_string();

			qDebug()<<"La respuesta recibida es: ";
			qDebug()<<QString::fromStdString(respuestaStr);

			process_gemma_output(respuestaStr);
			return respuestaStr;
		}
		catch (const std::exception& e) {
			qCritical() << "EXCEPCIÓN CAPTURADA:" << e.what();
			return std::string("ERROR");
		}
		catch (...) {
			qCritical() << "Fallo masivo (Segmentation Fault o similar)";
			return std::string("ERROR");
		}
	});

	return ollama_future.get();
}

void SpecificWorker::process_gemma_output(const std::string& res) {
	if (res == "LEFT") {
		this->omnirobot_proxy->setSpeedBase(0, 0, -0.5);
	} else if (res == "RIGHT") {
		this->omnirobot_proxy->setSpeedBase(0, 0, 0.5);
	} else if (res == "ADVANCE") {
		this->omnirobot_proxy->setSpeedBase(0, 500, 0);
	} else if (res == "BACK") {
		this->omnirobot_proxy->setSpeedBase(0, -500, 0);
	} else {
		qDebug() << "Error: La respuesta de Gemma no es válida:" << res.c_str();
	}
}

//Funcion auxiliar para pasar la imagen a Base64
std::string SpecificWorker::base64_encode(const std::vector<unsigned char>& data) {
	static const char sEncodingTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	std::string out;
	int val = 0, valb = -6;
	for (unsigned char c : data) {
		val = (val << 8) + c;
		valb += 8;
		while (valb >= 0) {
			out.push_back(sEncodingTable[(val >> valb) & 0x3F]);
			valb -= 6;
		}
	}
	if (valb > -6) out.push_back(sEncodingTable[((val << 8) >> (valb + 8)) & 0x3F]);
	while (out.size() % 4) out.push_back('=');
	return out;
}


void SpecificWorker::slot_new_target(QPointF target)
{
	if(viewer == nullptr)
		return;

	try
	{
		const auto pose = navigator_proxy->getRobotPose();
		RoboCompNavigator::TPoint source{pose.x, pose.y};
		RoboCompNavigator::TPoint destination{static_cast<float>(target.x()), static_cast<float>(target.y())};
		last_target = destination;
		has_target = true;

		constexpr float safety = 0.25f;
		const auto result = navigator_proxy->getPath(source, destination, safety);

		if(not result.valid)
		{
			qWarning() << "Path request failed:" << QString::fromStdString(result.errorMsg);
			return;
		}

		if(result.path.size() < 2)
		{
			qWarning() << "Path request returned an empty or single-point path";
			planned_path_points.clear();
			return;
		}

		planned_path_points = result.path;
		redraw_planned_path(source);

		qInfo() << "Path planned with" << result.path.size() << "points";
	}
	catch(const Ice::Exception &e)
	{
		qWarning() << "Error requesting path to clicked target:" << e.what();
	}
}

void SpecificWorker::redraw_planned_path(const RoboCompNavigator::TPoint &current_source)
{
	if(viewer == nullptr)
		return;

	for(auto *item : planned_path_items)
	{
		viewer->scene.removeItem(item);
		delete item;
	}
	planned_path_items.clear();

	if(planned_path_points.size() < 2)
		return;

	QPen path_pen(QColor("orange"), 0.09);
	RoboCompNavigator::TPoint p1 = current_source;
	const auto &p2_first = planned_path_points[1];
	auto *first_segment = viewer->scene.addLine(QLineF(p1.x, p1.y, p2_first.x, p2_first.y), path_pen);
	first_segment->setZValue(200);
	planned_path_items.push_back(first_segment);

	for(size_t i = 1; i < planned_path_points.size() - 1; ++i)
	{
		const auto &p1_mid = planned_path_points[i];
		const auto &p2_mid = planned_path_points[i + 1];
		auto *segment = viewer->scene.addLine(QLineF(p1_mid.x, p1_mid.y, p2_mid.x, p2_mid.y), path_pen);
		segment->setZValue(200);
		planned_path_items.push_back(segment);
	}

	auto *start_marker = viewer->scene.addEllipse(current_source.x - 0.08, current_source.y - 0.08, 0.16, 0.16,
	                                             QPen(QColor("darkOrange"), 0.03),
	                                             QBrush(QColor("darkOrange"), Qt::SolidPattern));
	start_marker->setZValue(210);
	planned_path_items.push_back(start_marker);

	const auto &goal = planned_path_points.back();
	auto *goal_marker = viewer->scene.addEllipse(goal.x - 0.09, goal.y - 0.09, 0.18, 0.18,
	                                            QPen(QColor("red"), 0.03),
	                                            QBrush(QColor("red"), Qt::SolidPattern));
	goal_marker->setZValue(210);
	planned_path_items.push_back(goal_marker);
}

void SpecificWorker::emergency()
{
    std::cout << "Emergency worker" << std::endl;
    //emergencyCODE
    //
    //if (SUCCESSFUL) //The componet is safe for continue
    //  emmit goToRestore()
}



//Execute one when exiting to emergencyState
void SpecificWorker::restore()
{
    std::cout << "Restore worker" << std::endl;
    //restoreCODE
    //Restore emergency component

}


int SpecificWorker::startup_check()
{
	std::cout << "Startup check" << std::endl;
	QTimer::singleShot(200, QCoreApplication::instance(), SLOT(quit()));
	return 0;
}



/**************************************/
// From the RoboCompNavigator you can call this methods:
// RoboCompNavigator::LayoutData this->navigator_proxy->getLayout()
// RoboCompNavigator::Result this->navigator_proxy->getPath(TPoint source, TPoint target, float safety)
// RoboCompNavigator::TPoint this->navigator_proxy->gotoObject(string object)
// RoboCompNavigator::TPoint this->navigator_proxy->gotoPoint(TPoint target)
// RoboCompNavigator::void this->navigator_proxy->resume()
// RoboCompNavigator::void this->navigator_proxy->stop()

/**************************************/
// From the RoboCompNavigator you can use this types:
// RoboCompNavigator::TPoint
// RoboCompNavigator::Result
// RoboCompNavigator::Pose
// RoboCompNavigator::NavigationStatus
// RoboCompNavigator::TObject
// RoboCompNavigator::LayoutData
