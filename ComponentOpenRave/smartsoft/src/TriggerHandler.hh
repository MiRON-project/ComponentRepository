//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Service Robotics Research Center
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// This file is generated once. Modify this file to your needs. 
// If you want the toolchain to re-generate this file, please 
// delete it before running the code generator.
//--------------------------------------------------------------------------
#ifndef _TRIGGERHANDLER_HH
#define _TRIGGERHANDLER_HH

#include "TriggerHandlerCore.hh"

class TriggerHandler: public TriggerHandlerCore 
{
public:
	TriggerHandler() {  }
	virtual ~TriggerHandler() {  }
	
	// trigger user methods
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_CONSTRAINED_PATH(const double &fromHeight, const double &toHeight, const double &fromDepth, const double &toDepth, const double &fromSide, const double &toSide, const double &fromAzimuth, const double &toAzimuth, const double &fromElevation, const double &toElevation, const double &fromRoll, const double &toRoll);
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_ENV_CLEAR();
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_ENV_LOAD_FILE(const int &fileID);
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_ENV_LOAD_OBJECTRECOGNITION(const int &envID);
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_ENV_SAVE_FILE();
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_GRASPING_CENTERED(const double &fromHeight, const double &toHeight, const double &fromDepth, const double &toDepth, const double &fromSide, const double &toSide, const double &fromAzimuth, const double &toAzimuth, const double &fromElevation, const double &toElevation, const double &fromRoll, const double &toRoll);
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_GRASPING_NONE();
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_GRASPING_SIMPLE(const double &fromHeight, const double &toHeight, const double &fromDepth, const double &toDepth, const double &fromSide, const double &toSide, const double &fromAzimuth, const double &toAzimuth, const double &fromElevation, const double &toElevation, const double &fromRoll, const double &toRoll);
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_NORMAL_PATH();
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_OBJ_ADD(const int &objectID);
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_OBJ_COMPUTEGRASPTABLE(const int &objectID);
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_OBJ_DELETE(const int &objectID);
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_OBJ_MOVE(const int &objectID, const double &x, const double &y, const double &z, const double &yaw, const double &pitch, const double &roll);
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_PLANNING_GRASPOBJ(const int &objectID);
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_PLANNING_RELEASEOBJ(const int &objectID);
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_PLAN_FURNITURE_MANIPUATION_TASK(const PLAN_FURNITURE_MANIPUATION_TASKType::modeType &mode, const unsigned int &furnitureIdentifier, const unsigned int &doorIdentifier, const double &openAmount);
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_PLAN_PATH_TARGET_JOINT_ANGLES(const std::list<double> &angles);
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_PLAN_PATH_TARGET_TCP_POSE(const double &x, const double &y, const double &z, const double &azimuth, const double &elevation, const double &roll);
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_SIMULATION_PLAN_ALL();
	virtual void handleCommManipulationPlannerObjects_ManipulationPlannerParameter_SIMULATION_TEST_IK_ONLY();
};

#endif // _TRIGGERHANDLER_HH
