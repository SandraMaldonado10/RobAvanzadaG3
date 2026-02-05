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
#include <grid2d/grid.h>
#include "abstract_graphic_viewer/abstract_graphic_viewer.h"

/**
 * \brief Class SpecificWorker implements the core functionality of the component.
 */
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

	//Obtener los datos del LiDAR
	RoboCompLidar3D::TPoints filtro_datos();

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

	void draw_lidar (const RoboCompLidar3D::TPoints &filtered_points, QGraphicsScene *scene);

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

	struct Params
	{
		float ROBOT_WIDTH = 460;  // mm
		float ROBOT_LENGTH = 480;  // mm
		float MAX_ADV_SPEED = 1000; // mm/s
		float MAX_ROT_SPEED = 1; // rad/s
		float MAX_SIDE_SPEED = 50; // mm/s
		float MAX_TRANSLATION = 500; // mm/s
		float MAX_ROTATION = 0.2;
		float STOP_THRESHOLD = 700; // mm
		float ADVANCE_THRESHOLD = ROBOT_WIDTH * 3; // mm
		float LIDAR_FRONT_SECTION = 0.2; // rads, aprox 12 degrees
		// wall
		float LIDAR_RIGHT_SIDE_SECTION = M_PI/3; // rads, 90 degrees
		float LIDAR_LEFT_SIDE_SECTION = -M_PI/3; // rads, 90 degrees
		float WALL_MIN_DISTANCE = ROBOT_WIDTH*1.2;
		// match error correction
		float MATCH_ERROR_SIGMA = 150.f; // mm
		float DOOR_REACHED_DIST = 300.f;
		std::string LIDAR_NAME_LOW = "bpearl";
		std::string LIDAR_NAME_HIGH = "helios";
		QRectF GRID_MAX_DIM{-5000, 2500, 10000, -5000};

		// relocalization
		float RELOCAL_CENTER_EPS = 300.f;    // mm: stop when |mean| < eps
		float RELOCAL_KP = 0.002f;           // gain to convert mean (mm) -> speed (magnitude)
		float RELOCAL_MAX_ADV = 300.f;       // mm/s cap while re-centering
		float RELOCAL_MAX_SIDE = 300.f;      // mm/s cap while re-centering
		float RELOCAL_ROT_SPEED = 0.3f;     // rad/s while aligning
		float RELOCAL_DELTA = 5.0f * M_PI/180.f; // small probe angle in radians
		float RELOCAL_MATCH_MAX_DIST = 2000.f;   // mm for Hungarian gating
		float RELOCAL_DONE_COST = 500.f;
		float RELOCAL_DONE_MATCH_MAX_ERROR = 1000.f;

	};
	Params params;

	// viewer
	AbstractGraphicViewer *viewer;
	QGraphicsPolygonItem *robot_draw, *robot_room_draw;

signals:
	//void customSignal();
};

#endif
