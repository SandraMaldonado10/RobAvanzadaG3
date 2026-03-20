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

/**
	\brief
	@author authorname
*/



#ifndef SPECIFICWORKER_H
#define SPECIFICWORKER_H


// If you want to reduce the period automatically due to lack of use, you must uncomment the following line
//#define HIBERNATION_ENABLED

#include <genericworker.h>
#include "abstract_graphic_viewer/abstract_graphic_viewer.h"
#include <vector>
#include "ollama.hpp"
#include <future>
#include <iostream>
#include <string>
#include <vector>
#include <ranges>
#include <string_view>
#include <queue>
#include <ctype.h>
#include <opencv2/opencv.hpp>
/**
 * \brief Class SpecificWorker implements the core functionality of the component.
 */

struct Mission{
	std::string target; //Destino al que el robot tiene que ir
	std::list<char> actions; //Accion(es) que el robot tiene que realizar tras llegar al target
};


class SpecificWorker : public GenericWorker
{
Q_OBJECT
public:
    /**
     * \brief Constructor for SpecificWorker.
     * \param configLoader Configuration loader for the component.
     * \param tprx Tuple of proxies required for the component.
     * \param startup_check Indicates whether to perform startup checks.
     */
	SpecificWorker(const ConfigLoader& configLoader, TuplePrx tprx, bool startup_check);

	/**
     * \brief Destructor for SpecificWorker.
     */
	~SpecificWorker();


public slots:

	/**
	 * \brief Initializes the worker one time.
	 */
	void initialize();

	/**
	 * \brief Main compute loop of the worker.
	 */
	void compute();

	/**
	 * \brief Handles the emergency state loop.
	 */
	void emergency();

	/**
	 * \brief Restores the component from an emergency state.
	 */
	void restore();

    /**
     * \brief Performs startup checks for the component.
     * \return An integer representing the result of the checks.
     */
	int startup_check();

private:

	/**
     * \brief Flag indicating whether startup checks are enabled.
     */
	bool startup_check_flag;
	AbstractGraphicViewer *viewer = nullptr;
	std::vector<QGraphicsItem*> planned_path_items;
	RoboCompNavigator::TPath planned_path_points;
	RoboCompNavigator::TPoint last_target{0.f, 0.f};
	bool has_target = false;
	std::future<void> ollama_thread; // Variable para "guardar" el hilo
	bool navigated = false;

	std::list<Mission> missions_list;

	//std::queue<std::string> pending_missions; //Missions son sitios a los que ir + acciones que realizar una vez llega
	//std::queue<char> pending_actions; //Actions son acciones que hacer una vez el robot llega al sitio (por ejemplo, hacer una foto)

	void redraw_planned_path(const RoboCompNavigator::TPoint &current_source);

	using json = nlohmann::json;

	json getJson();

	void on_text_change();
	void interpret_ollama_output_string(std::string& ollamaOutput);
	void process_mission(std::string& mission);
	void process_mission_list(); //Procesa la lista de acciones (debe llamarse cuando el robot está IDLE)
	void save_image(const RoboCompImageSegmentation::TImage& datos_imagen, const std::string& nombre_archivo);

private slots:
	void slot_new_target(QPointF target);

signals:
	//void customSignal();
};

#endif
