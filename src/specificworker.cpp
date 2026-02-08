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
		
		// Example statemachine:
		/***
		//Your definition for the statesmachine (if you dont want use a execute function, use nullptr)
		states["CustomState"] = std::make_unique<GRAFCETStep>("CustomState", period, 
															std::bind(&SpecificWorker::customLoop, this),  // Cyclic function
															std::bind(&SpecificWorker::customEnter, this), // On-enter function
															std::bind(&SpecificWorker::customExit, this)); // On-exit function

		//Add your definition of transitions (addTransition(originOfSignal, signal, dstState))
		states["CustomState"]->addTransition(states["CustomState"].get(), SIGNAL(entered()), states["OtherState"].get());
		states["Compute"]->addTransition(this, SIGNAL(customSignal()), states["CustomState"].get()); //Define your signal in the .h file under the "Signals" section.

		//Add your custom state
		statemachine.addState(states["CustomState"].get());
		***/

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
	std::cout << "Destroying SpecificWorker" << std::endl;
}


void SpecificWorker::initialize()
{
    std::cout << "initialize worker" << std::endl;

	// Viewer
	viewer = new AbstractGraphicViewer(this->frame, params.GRID_MAX_DIM);
	auto [r, e] = viewer->add_robot(params.ROBOT_WIDTH, params.ROBOT_LENGTH, 0, 100, QColor("Blue"));
	robot_draw = r;

	show ();

    //initializeCODE

    /////////GET PARAMS, OPEND DEVICES....////////
    //int period = configLoader.get<int>("Period.Compute") //NOTE: If you want get period of compute use getPeriod("compute")
    //std::string device = configLoader.get<std::string>("Device.name") 

}



void SpecificWorker::compute()
{
	RoboCompWebots2Robocomp::ObjectPose pose;
	try
	{
		pose = this->webots2robocomp_proxy->getObjectPose("shadow");
	}
	catch (const Ice::Exception &e){std::cout<<e.what()<<std::endl; return;}
	double yaw = yawFromQuaternion(pose.orientation.w, pose.orientation.x, pose.orientation.y, pose.orientation.z);

	// 2. Update robot_pose_display (modifies
	update_pose(pose, yaw);

	// 3. Update visual representation of the robot
	robot_draw->setPos(robot_pose_display.translation().x(),
					   robot_pose_display.translation().y());
	robot_draw->setRotation((obtain_rotation()*180 / M_PI)); //Hay que usar la rotación en grados

	// 4. Draw lidar points
	RoboCompLidar3D::TPoints data = filtro_datos();
	draw_lidar(data, &viewer->scene);
}


void SpecificWorker::draw_lidar(const RoboCompLidar3D::TPoints &filtered_points, QGraphicsScene *scene)
{
	static std::vector<QGraphicsItem*> draw_points;
	for (const auto &p : draw_points)
	{
		scene->removeItem(p);
		delete p;
	}
	draw_points.clear();

	const QColor color("LightGreen");
	const QPen pen(color, 10);
	//const QBrush brush(color, Qt::SolidPattern);
	for (const auto &p : filtered_points)
	{
		Eigen::Vector2f worldP = transform_to_world(p);

		const auto dp = scene->addRect(-25, -25, 50, 50, pen);
		dp->setPos(worldP.x(), worldP.y());
		draw_points.push_back(dp);   // add to the list of points to be deleted next time
	}
}

// Devuelve el yaw (rotación alrededor del eje Z) en radianes
double SpecificWorker::yawFromQuaternion(double w, double x, double y, double z) {

	//TODO: El quaternion tiene que estar normalizado, si no lo está, descomentar este código

	// double norm = std::sqrt(w*w + x*x + y*y + z*z);
	// w /= norm; x /= norm; y /= norm; z /= norm;

	double siny_cosp = 2.0 * (w * z + x * y);
	double cosy_cosp = 1.0 - 2.0 * (y * y + z * z);

	return std::atan2(siny_cosp, cosy_cosp);

}

void SpecificWorker::update_pose(RoboCompWebots2Robocomp::ObjectPose pose, double yaw) {
	this->robot_pose_display.translation() = Eigen::Vector2f(pose.position.x, pose.position.z);
	this->robot_pose_display.linear() = Eigen::Rotation2Df(yaw).toRotationMatrix();
}

Eigen::Vector2f SpecificWorker::transform_to_world(const RoboCompLidar3D::TPoint &local_point)
{
	// Creamos un vector Eigen con los datos del Lidar (pasando a metros) TODO: Tengo que dividir por 1000?
	Eigen::Vector2f p(local_point.x, local_point.y);

	// Aplicamos la transformación completa (rotación + traslación)
	return robot_pose_display * p;
}

float SpecificWorker::obtain_rotation() {
	//Extraemos la rotacion, necesario para actualizar robot_draw:
	Eigen::Rotation2Df rotation;
	rotation.fromRotationMatrix(robot_pose_display.linear());

	return rotation.angle();
}

RoboCompLidar3D::TPoints SpecificWorker::filtro_datos()
{
	RoboCompLidar3D::TData  data;
	try
	{
		data =  lidar3d_proxy->getLidarData("bpearl", 0, 2*M_PI, 1); //para mayor precision (puedo comparar ejemplos de ejecucion entre este y 0.1f round en la docu)
		//qInfo() << "Size: "<<data.points.size();

	}
	catch (const Ice::Exception &e){ std::cout<<e.what()<<std::endl; return {};}
	return data.points;
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
// From the RoboCompCamera360RGB you can call this methods:
// RoboCompCamera360RGB::TImage this->camera360rgb_proxy->getROI(int cx, int cy, int sx, int sy, int roiwidth, int roiheight)

/**************************************/
// From the RoboCompCamera360RGB you can use this types:
// RoboCompCamera360RGB::TRoi
// RoboCompCamera360RGB::TImage

/**************************************/
// From the RoboCompLidar3D you can call this methods:
// RoboCompLidar3D::TColorCloudData this->lidar3d_proxy->getColorCloudData()
// RoboCompLidar3D::TData this->lidar3d_proxy->getLidarData(string name, float start, float len, int decimationDegreeFactor)
// RoboCompLidar3D::TDataImage this->lidar3d_proxy->getLidarDataArrayProyectedInImage(string name)
// RoboCompLidar3D::TDataCategory this->lidar3d_proxy->getLidarDataByCategory(TCategories categories, long timestamp)
// RoboCompLidar3D::TData this->lidar3d_proxy->getLidarDataProyectedInImage(string name)
// RoboCompLidar3D::TData this->lidar3d_proxy->getLidarDataWithThreshold2d(string name, float distance, int decimationDegreeFactor)

/**************************************/
// From the RoboCompLidar3D you can use this types:
// RoboCompLidar3D::TPoint
// RoboCompLidar3D::TDataImage
// RoboCompLidar3D::TData
// RoboCompLidar3D::TDataCategory
// RoboCompLidar3D::TColorCloudData

/**************************************/
// From the RoboCompOmniRobot you can call this methods:
// RoboCompOmniRobot::void this->omnirobot_proxy->correctOdometer(int x, int z, float alpha)
// RoboCompOmniRobot::void this->omnirobot_proxy->getBasePose(int x, int z, float alpha)
// RoboCompOmniRobot::void this->omnirobot_proxy->getBaseState(RoboCompGenericBase::TBaseState state)
// RoboCompOmniRobot::void this->omnirobot_proxy->resetOdometer()
// RoboCompOmniRobot::void this->omnirobot_proxy->setOdometer(RoboCompGenericBase::TBaseState state)
// RoboCompOmniRobot::void this->omnirobot_proxy->setOdometerPose(int x, int z, float alpha)
// RoboCompOmniRobot::void this->omnirobot_proxy->setSpeedBase(float advx, float advz, float rot)
// RoboCompOmniRobot::void this->omnirobot_proxy->stopBase()

/**************************************/
// From the RoboCompOmniRobot you can use this types:
// RoboCompOmniRobot::TMechParams

