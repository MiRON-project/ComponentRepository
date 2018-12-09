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
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------
#ifndef _SMARTMAPPERGRIDMAP_HH
#define _SMARTMAPPERGRIDMAP_HH

#include <map>
#include <iostream>
#include "aceSmartSoft.hh"
#include "smartQueryServerTaskTrigger_T.h"
#include "SmartMapperGridMapCore.hh"

#include "SmartMapperGridMapPortFactoryInterface.hh"
#include "SmartMapperGridMapExtension.hh"

// forward declarations
class SmartMapperGridMapPortFactoryInterface;
class SmartMapperGridMapExtension;

// includes for SmartMapperGridMapROSExtension

// includes for SeRoNetSDKComponentGeneratorExtension

// includes for PlainOpcUaSmartMapperGridMapExtension
// include plain OPC UA device clients
// include plain OPC UA status servers


// include communication objects
#include <CommNavigationObjects/CommGridMap.hh>
#include <CommNavigationObjects/CommGridMapACE.hh>
#include <CommNavigationObjects/CommGridMapRequest.hh>
#include <CommNavigationObjects/CommGridMapRequestACE.hh>
#include <CommBasicObjects/CommMobileLaserScan.hh>
#include <CommBasicObjects/CommMobileLaserScanACE.hh>

// include tasks
#include "CurMapTask.hh"
#include "LtmMapTask.hh"
// include UpcallManagers
#include "LaserServiceInUpcallManager.hh"

// include input-handler
// include input-handler
#include "CurrQueryServerHandler.hh"
#include "LtmQueryServerHandler.hh"

// include handler
#include "CompHandler.hh"

#include "ParameterStateStruct.hh"
#include "ParameterUpdateHandler.hh"

#include "SmartStateChangeHandler.hh"

#define COMP SmartMapperGridMap::instance()

class SmartMapperGridMap : public SmartMapperGridMapCore {
private:
	static SmartMapperGridMap *_smartMapperGridMap;
	
	// constructor
	SmartMapperGridMap();
	
	// copy-constructor
	SmartMapperGridMap(const SmartMapperGridMap& cc);
	
	// destructor
	~SmartMapperGridMap() { };
	
	// load parameter from ini file
	void loadParameter(int argc, char* argv[]);
	
	// instantiate comp-handler
	CompHandler compHandler;
	
	// helper method that maps a string-name to an according TaskTriggerSubject
	Smart::TaskTriggerSubject* getInputTaskTriggerFromString(const std::string &client);
	
	// internal map storing the different port-creation factories (that internally map to specific middleware implementations)
	std::map<std::string, SmartMapperGridMapPortFactoryInterface*> portFactoryRegistry;
	
	// internal map storing various extensions of this component class
	std::map<std::string, SmartMapperGridMapExtension*> componentExtensionRegistry;
	
public:
	ParameterStateStruct getGlobalState() const
	{
		return paramHandler.getGlobalState();
	}
	
	// define tasks
	Smart::TaskTriggerSubject* curMapTaskTrigger;
	CurMapTask *curMapTask;
	Smart::TaskTriggerSubject* ltmMapTaskTrigger;
	LtmMapTask *ltmMapTask;
	
	// define input-ports
	// InputPort LaserServiceIn
	Smart::IPushClientPattern<CommBasicObjects::CommMobileLaserScan> *laserServiceIn;
	Smart::InputTaskTrigger<CommBasicObjects::CommMobileLaserScan> *laserServiceInInputTaskTrigger;
	LaserServiceInUpcallManager *laserServiceInUpcallManager;
	
	// define request-ports
	
	// define input-handler
	
	// define output-ports
	Smart::IPushServerPattern<CommNavigationObjects::CommGridMap> *currMapOut;
	
	// define answer-ports
	Smart::IQueryServerPattern<CommNavigationObjects::CommGridMapRequest, CommNavigationObjects::CommGridMap,SmartACE::QueryId> *currQueryServer;
	Smart::QueryServerTaskTrigger<CommNavigationObjects::CommGridMapRequest, CommNavigationObjects::CommGridMap,SmartACE::QueryId> *currQueryServerInputTaskTrigger;
	Smart::IQueryServerPattern<CommNavigationObjects::CommGridMapRequest, CommNavigationObjects::CommGridMap,SmartACE::QueryId> *ltmQueryServer;
	Smart::QueryServerTaskTrigger<CommNavigationObjects::CommGridMapRequest, CommNavigationObjects::CommGridMap,SmartACE::QueryId> *ltmQueryServerInputTaskTrigger;
	
	// define request-handlers
	CurrQueryServerHandler *currQueryServerHandler;
	LtmQueryServerHandler *ltmQueryServerHandler;
	
	// definitions of SmartMapperGridMapROSExtension
	
	// definitions of SeRoNetSDKComponentGeneratorExtension
	
	// definitions of PlainOpcUaSmartMapperGridMapExtension
	
	
	// define default slave ports
	SmartACE::StateSlave *stateSlave;
	SmartStateChangeHandler *stateChangeHandler;
	SmartACE::WiringSlave *wiringSlave;
	ParamUpdateHandler paramHandler;
	SmartACE::ParameterSlave *param;
	
	
	/// this method is used to register different PortFactory classes (one for each supported middleware framework)
	void addPortFactory(const std::string &name, SmartMapperGridMapPortFactoryInterface *portFactory);
	
	/// this method is used to register different component-extension classes
	void addExtension(SmartMapperGridMapExtension *extension);
	
	/// this method allows to access the registered component-extensions (automatically converting to the actuall implementation type)
	template <typename T>
	T* getExtension(const std::string &name) {
		auto it = componentExtensionRegistry.find(name);
		if(it != componentExtensionRegistry.end()) {
			return dynamic_cast<T*>(it->second);
		}
		return 0;
	}
	
	/// initialize component's internal members
	void init(int argc, char *argv[]);
	
	/// execute the component's infrastructure
	void run();
	
	/// clean-up component's resources
	void fini();
	
	/// call this method to set the overall component into the Alive state (i.e. component is then ready to operate)
	void setStartupFinished();
	
	/// connect all component's client ports
	Smart::StatusCode connectAndStartAllServices();
	
	/// start all assocuated Activities
	void startAllTasks();
	
	/// start all associated timers
	void startAllTimers();
	
	Smart::StatusCode connectLaserServiceIn(const std::string &serverName, const std::string &serviceName);

	// return singleton instance
	static SmartMapperGridMap* instance()
	{
		if(_smartMapperGridMap == 0) {
			_smartMapperGridMap = new SmartMapperGridMap();
		}
		return _smartMapperGridMap;
	}
	
	static void deleteInstance() {
		if(_smartMapperGridMap != 0) {
			delete _smartMapperGridMap;
		}
	}
	
	// connections parameter
	struct connections_struct
	{
		// component struct
		struct component_struct
		{
			// the name of the component
			std::string name;
			std::string initialComponentMode;
			std::string defaultScheduler;
			bool useLogger;
		} component;
		
		//--- task parameter ---
		struct CurMapTask_struct {
			double minActFreq;
			double maxActFreq;
			std::string trigger;
			// only one of the following two params is 
			// actually used at run-time according 
			// to the system config model
			double periodicActFreq;
			// or
			std::string inPortRef;
			int prescale;
			// scheduling parameters
			std::string scheduler;
			int priority;
			int cpuAffinity;
		} curMapTask;
		struct LtmMapTask_struct {
			double minActFreq;
			double maxActFreq;
			std::string trigger;
			// only one of the following two params is 
			// actually used at run-time according 
			// to the system config model
			double periodicActFreq;
			// or
			std::string inPortRef;
			int prescale;
			// scheduling parameters
			std::string scheduler;
			int priority;
			int cpuAffinity;
		} ltmMapTask;
		
		//--- upcall parameter ---
		
		//--- server port parameter ---
		struct CurrMapOut_struct {
				std::string serviceName;
				std::string roboticMiddleware;
		} currMapOut;
		struct CurrQueryServer_struct {
				std::string serviceName;
				std::string roboticMiddleware;
		} currQueryServer;
		struct LtmQueryServer_struct {
				std::string serviceName;
				std::string roboticMiddleware;
		} ltmQueryServer;
	
		//--- client port parameter ---
		struct LaserServiceIn_struct {
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} laserServiceIn;
		
		// -- parameters for SmartMapperGridMapROSExtension
		
		// -- parameters for SeRoNetSDKComponentGeneratorExtension
		
		// -- parameters for PlainOpcUaSmartMapperGridMapExtension
		
	} connections;
};
#endif
