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
#ifndef _SMARTJOYSTICKNAVIGATION_HH
#define _SMARTJOYSTICKNAVIGATION_HH

#include <map>
#include <iostream>
#include "aceSmartSoft.hh"
#include "smartQueryServerTaskTrigger_T.h"
#include "SmartJoystickNavigationCore.hh"

#include "SmartJoystickNavigationPortFactoryInterface.hh"
#include "SmartJoystickNavigationExtension.hh"

// forward declarations
class SmartJoystickNavigationPortFactoryInterface;
class SmartJoystickNavigationExtension;

// includes for OpcUaBackendComponentGeneratorExtension

// includes for PlainOpcUaSmartJoystickNavigationExtension
// include plain OPC UA device clients
// include plain OPC UA status servers

// includes for SmartJoystickNavigationROSExtension


// include communication objects
#include <CommBasicObjects/CommJoystick.hh>
#include <CommBasicObjects/CommJoystickACE.hh>
#include <CommBasicObjects/CommNavigationVelocity.hh>
#include <CommBasicObjects/CommNavigationVelocityACE.hh>

// include tasks
#include "JoystickNavTask.hh"
// include UpcallManagers
#include "JoystickServiceInUpcallManager.hh"

// include input-handler(s)
// include request-handler(s)

// include handler
#include "CompHandler.hh"

#include "ParameterStateStruct.hh"
#include "ParameterUpdateHandler.hh"

#include "SmartStateChangeHandler.hh"

#define COMP SmartJoystickNavigation::instance()

class SmartJoystickNavigation : public SmartJoystickNavigationCore {
private:
	static SmartJoystickNavigation *_smartJoystickNavigation;
	
	// constructor
	SmartJoystickNavigation();
	
	// copy-constructor
	SmartJoystickNavigation(const SmartJoystickNavigation& cc);
	
	// destructor
	~SmartJoystickNavigation() { };
	
	// load parameter from ini file
	void loadParameter(int argc, char* argv[]);
	
	// instantiate comp-handler
	CompHandler compHandler;
	
	// helper method that maps a string-name to an according TaskTriggerSubject
	Smart::TaskTriggerSubject* getInputTaskTriggerFromString(const std::string &client);
	
	// internal map storing the different port-creation factories (that internally map to specific middleware implementations)
	std::map<std::string, SmartJoystickNavigationPortFactoryInterface*> portFactoryRegistry;
	
	// internal map storing various extensions of this component class
	std::map<std::string, SmartJoystickNavigationExtension*> componentExtensionRegistry;
	
public:
	ParameterStateStruct getGlobalState() const
	{
		return paramHandler.getGlobalState();
	}
	
	ParameterStateStruct getParameters() const
	{
		return paramHandler.getGlobalState();
	}
	
	// define tasks
	Smart::TaskTriggerSubject* joystickNavTaskTrigger;
	JoystickNavTask *joystickNavTask;
	
	// define input-ports
	// InputPort JoystickServiceIn
	Smart::IPushClientPattern<CommBasicObjects::CommJoystick> *joystickServiceIn;
	Smart::InputTaskTrigger<CommBasicObjects::CommJoystick> *joystickServiceInInputTaskTrigger;
	JoystickServiceInUpcallManager *joystickServiceInUpcallManager;
	
	// define request-ports
	
	// define input-handler
	
	// define output-ports
	Smart::ISendClientPattern<CommBasicObjects::CommNavigationVelocity> *navVelServiceOut;
	
	// define answer-ports
	
	// define request-handlers
	
	// definitions of OpcUaBackendComponentGeneratorExtension
	
	// definitions of PlainOpcUaSmartJoystickNavigationExtension
	
	// definitions of SmartJoystickNavigationROSExtension
	
	
	// define default slave ports
	SmartACE::StateSlave *stateSlave;
	SmartStateChangeHandler *stateChangeHandler;
	SmartACE::WiringSlave *wiringSlave;
	ParamUpdateHandler paramHandler;
	SmartACE::ParameterSlave *param;
	
	
	/// this method is used to register different PortFactory classes (one for each supported middleware framework)
	void addPortFactory(const std::string &name, SmartJoystickNavigationPortFactoryInterface *portFactory);
	
	SmartACE::SmartComponent* getComponentImpl();
	
	/// this method is used to register different component-extension classes
	void addExtension(SmartJoystickNavigationExtension *extension);
	
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
	
	Smart::StatusCode connectJoystickServiceIn(const std::string &serverName, const std::string &serviceName);
	Smart::StatusCode connectNavVelServiceOut(const std::string &serverName, const std::string &serviceName);

	// return singleton instance
	static SmartJoystickNavigation* instance()
	{
		if(_smartJoystickNavigation == 0) {
			_smartJoystickNavigation = new SmartJoystickNavigation();
		}
		return _smartJoystickNavigation;
	}
	
	static void deleteInstance() {
		if(_smartJoystickNavigation != 0) {
			delete _smartJoystickNavigation;
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
		struct JoystickNavTask_struct {
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
		} joystickNavTask;
		
		//--- upcall parameter ---
		
		//--- server port parameter ---
	
		//--- client port parameter ---
		struct JoystickServiceIn_struct {
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} joystickServiceIn;
		struct NavVelServiceOut_struct {
			bool initialConnect;
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} navVelServiceOut;
		
		// -- parameters for OpcUaBackendComponentGeneratorExtension
		
		// -- parameters for PlainOpcUaSmartJoystickNavigationExtension
		
		// -- parameters for SmartJoystickNavigationROSExtension
		
	} connections;
};
#endif
