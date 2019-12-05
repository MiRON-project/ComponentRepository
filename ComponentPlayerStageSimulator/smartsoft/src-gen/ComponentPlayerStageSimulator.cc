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
#include "ComponentPlayerStageSimulator.hh"
#include "smartTimedTaskTrigger.h"
//FIXME: implement logging
//#include "smartGlobalLogger.hh"

// the ace port-factory is used as a default port-mapping
#include "ComponentPlayerStageSimulatorAcePortFactory.hh"

#include "BatteryEventServiceOutEventTestHandler.hh"

// initialize static singleton pointer to zero
ComponentPlayerStageSimulator* ComponentPlayerStageSimulator::_componentPlayerStageSimulator = 0;

// constructor
ComponentPlayerStageSimulator::ComponentPlayerStageSimulator()
{
	std::cout << "constructor of ComponentPlayerStageSimulator\n";
	
	// set all pointer members to NULL
	baseStateAnswerer = NULL;
	baseStateAnswererInputTaskTrigger = NULL;
	baseStateQueryHandler = NULL;
	baseStateServiceOut = NULL;
	batteryEventServiceOut = NULL;
	batteryEventServiceOutEventTestHandler = nullptr; 
	batteryEventTask = NULL;
	batteryEventTaskTrigger = NULL;
	//componentPlayerStageSimulatorParams = NULL;
	//coordinationPort = NULL;
	laserServiceOut = NULL;
	localizationUpdateHandler = NULL;
	localizationUpdateServiceIn = NULL;
	localizationUpdateServiceInInputTaskTrigger = NULL;
	localizationUpdateServiceInUpcallManager = NULL;
	navigationVelocityHandler = NULL;
	navigationVelocityServiceIn = NULL;
	navigationVelocityServiceInInputTaskTrigger = NULL;
	navigationVelocityServiceInUpcallManager = NULL;
	playerTask = NULL;
	playerTaskTrigger = NULL;
	stateChangeHandler = NULL;
	stateSlave = NULL;
	wiringSlave = NULL;
	param = NULL;
	
	// set default ini parameter values
	connections.component.name = "ComponentPlayerStageSimulator";
	connections.component.initialComponentMode = "Neutral";
	connections.component.defaultScheduler = "DEFAULT";
	connections.component.useLogger = false;
	
	connections.baseStateAnswerer.serviceName = "BaseStateAnswerer";
	connections.baseStateAnswerer.roboticMiddleware = "ACE_SmartSoft";
	connections.baseStateServiceOut.serviceName = "BaseStateServiceOut";
	connections.baseStateServiceOut.roboticMiddleware = "ACE_SmartSoft";
	connections.batteryEventServiceOut.serviceName = "BatteryEventServiceOut";
	connections.batteryEventServiceOut.roboticMiddleware = "ACE_SmartSoft";
	connections.laserServiceOut.serviceName = "LaserServiceOut";
	connections.laserServiceOut.roboticMiddleware = "ACE_SmartSoft";
	connections.localizationUpdateServiceIn.serviceName = "LocalizationUpdateServiceIn";
	connections.localizationUpdateServiceIn.roboticMiddleware = "ACE_SmartSoft";
	connections.navigationVelocityServiceIn.serviceName = "NavigationVelocityServiceIn";
	connections.navigationVelocityServiceIn.roboticMiddleware = "ACE_SmartSoft";
	connections.batteryEventTask.minActFreq = 0.0;
	connections.batteryEventTask.maxActFreq = 0.0;
	// scheduling default parameters
	connections.batteryEventTask.scheduler = "DEFAULT";
	connections.batteryEventTask.priority = -1;
	connections.batteryEventTask.cpuAffinity = -1;
	connections.playerTask.minActFreq = 0.0;
	connections.playerTask.maxActFreq = 0.0;
	// scheduling default parameters
	connections.playerTask.scheduler = "DEFAULT";
	connections.playerTask.priority = -1;
	connections.playerTask.cpuAffinity = -1;
	connections.localizationUpdateHandler.prescale = 1;
	connections.navigationVelocityHandler.prescale = 1;
	
	// initialize members of ComponentPlayerStageSimulatorROSExtension
	
	// initialize members of OpcUaBackendComponentGeneratorExtension
	
	// initialize members of PlainOpcUaComponentPlayerStageSimulatorExtension
	
}

void ComponentPlayerStageSimulator::addPortFactory(const std::string &name, ComponentPlayerStageSimulatorPortFactoryInterface *portFactory)
{
	portFactoryRegistry[name] = portFactory;
}

void ComponentPlayerStageSimulator::addExtension(ComponentPlayerStageSimulatorExtension *extension)
{
	componentExtensionRegistry[extension->getName()] = extension;
}

SmartACE::SmartComponent* ComponentPlayerStageSimulator::getComponentImpl()
{
	return dynamic_cast<ComponentPlayerStageSimulatorAcePortFactory*>(portFactoryRegistry["ACE_SmartSoft"])->getComponentImpl();
}

/**
 * Notify the component that setup/initialization is finished.
 * You may call this function from anywhere in the component.
 *
 * Set component's internal lifecycle state automaton (if any) into 
 * Alive mode (from here on the component is ready to provide its services)
 */
void ComponentPlayerStageSimulator::setStartupFinished() {
	stateSlave->setWaitState("Alive");
	std::cout << "ComponentDefinition initialization/startup finished." << std::endl;
}




/**
 * First connect ALL client ports contained in this component, then start all services:
 * activate state, push, etc...
 */
Smart::StatusCode ComponentPlayerStageSimulator::connectAndStartAllServices() {
	Smart::StatusCode status = Smart::SMART_OK;
	
	return status;
}

/**
 * Start all tasks contained in this component.
 */
void ComponentPlayerStageSimulator::startAllTasks() {
	// start task BatteryEventTask
	if(connections.batteryEventTask.scheduler != "DEFAULT") {
		ACE_Sched_Params batteryEventTask_SchedParams(ACE_SCHED_OTHER, ACE_THR_PRI_OTHER_DEF);
		if(connections.batteryEventTask.scheduler == "FIFO") {
			batteryEventTask_SchedParams.policy(ACE_SCHED_FIFO);
			batteryEventTask_SchedParams.priority(ACE_THR_PRI_FIFO_MIN);
		} else if(connections.batteryEventTask.scheduler == "RR") {
			batteryEventTask_SchedParams.policy(ACE_SCHED_RR);
			batteryEventTask_SchedParams.priority(ACE_THR_PRI_RR_MIN);
		}
		batteryEventTask->start(batteryEventTask_SchedParams, connections.batteryEventTask.cpuAffinity);
	} else {
		batteryEventTask->start();
	}
	// start task PlayerTask
	if(connections.playerTask.scheduler != "DEFAULT") {
		ACE_Sched_Params playerTask_SchedParams(ACE_SCHED_OTHER, ACE_THR_PRI_OTHER_DEF);
		if(connections.playerTask.scheduler == "FIFO") {
			playerTask_SchedParams.policy(ACE_SCHED_FIFO);
			playerTask_SchedParams.priority(ACE_THR_PRI_FIFO_MIN);
		} else if(connections.playerTask.scheduler == "RR") {
			playerTask_SchedParams.policy(ACE_SCHED_RR);
			playerTask_SchedParams.priority(ACE_THR_PRI_RR_MIN);
		}
		playerTask->start(playerTask_SchedParams, connections.playerTask.cpuAffinity);
	} else {
		playerTask->start();
	}
}

/**
 * Start all timers contained in this component
 */
void ComponentPlayerStageSimulator::startAllTimers() {
}


Smart::TaskTriggerSubject* ComponentPlayerStageSimulator::getInputTaskTriggerFromString(const std::string &client)
{
	if(client == "LocalizationUpdateServiceIn") return localizationUpdateServiceInInputTaskTrigger;
	if(client == "NavigationVelocityServiceIn") return navigationVelocityServiceInInputTaskTrigger;
	
	return NULL;
}


void ComponentPlayerStageSimulator::init(int argc, char *argv[])
{
	try {
		Smart::StatusCode status;
		
		// load initial parameters from ini-file (if found)
		loadParameter(argc, argv);
		
		// print out the actual parameters which are used to initialize the component
		std::cout << " \nComponentDefinition Initial-Parameters:\n" << COMP->getParameters() << std::endl;
		
		// initializations of ComponentPlayerStageSimulatorROSExtension
		
		// initializations of OpcUaBackendComponentGeneratorExtension
		
		// initializations of PlainOpcUaComponentPlayerStageSimulatorExtension
		
		
		// initialize all registered port-factories
		for(auto portFactory = portFactoryRegistry.begin(); portFactory != portFactoryRegistry.end(); portFactory++) 
		{
			portFactory->second->initialize(this, argc, argv);
		}
		
		// initialize all registered component-extensions
		for(auto extension = componentExtensionRegistry.begin(); extension != componentExtensionRegistry.end(); extension++) 
		{
			extension->second->initialize(this, argc, argv);
		}
		
		ComponentPlayerStageSimulatorPortFactoryInterface *acePortFactory = portFactoryRegistry["ACE_SmartSoft"];
		if(acePortFactory == 0) {
			std::cerr << "ERROR: acePortFactory NOT instantiated -> exit(-1)" << std::endl;
			exit(-1);
		}
		
		// this pointer is used for backwards compatibility (deprecated: should be removed as soon as all patterns, including coordination, are moved to port-factory)
		SmartACE::SmartComponent *component = dynamic_cast<ComponentPlayerStageSimulatorAcePortFactory*>(acePortFactory)->getComponentImpl();
		
		std::cout << "ComponentDefinition ComponentPlayerStageSimulator is named " << connections.component.name << std::endl;
		
		if(connections.component.useLogger == true) {
			//FIXME: use logging
			//Smart::LOGGER->openLogFileInFolder("data/"+connections.component.name);
			//Smart::LOGGER->startLogging();
		}

		// create event-test handlers (if needed)
		batteryEventServiceOutEventTestHandler = std::make_shared<BatteryEventServiceOutEventTestHandler>();
		
		// create server ports
		// TODO: set minCycleTime from Ini-file
		baseStateAnswerer = portFactoryRegistry[connections.baseStateAnswerer.roboticMiddleware]->createBaseStateAnswerer(connections.baseStateAnswerer.serviceName);
		baseStateAnswererInputTaskTrigger = new Smart::QueryServerTaskTrigger<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState>(baseStateAnswerer);
		baseStateServiceOut = portFactoryRegistry[connections.baseStateServiceOut.roboticMiddleware]->createBaseStateServiceOut(connections.baseStateServiceOut.serviceName);
		batteryEventServiceOutEventTestHandler = std::make_shared<BatteryEventServiceOutEventTestHandler>();
		batteryEventServiceOut = portFactoryRegistry[connections.batteryEventServiceOut.roboticMiddleware]->createBatteryEventServiceOut(connections.batteryEventServiceOut.serviceName, batteryEventServiceOutEventTestHandler);
		laserServiceOut = portFactoryRegistry[connections.laserServiceOut.roboticMiddleware]->createLaserServiceOut(connections.laserServiceOut.serviceName);
		localizationUpdateServiceIn = portFactoryRegistry[connections.localizationUpdateServiceIn.roboticMiddleware]->createLocalizationUpdateServiceIn(connections.localizationUpdateServiceIn.serviceName);
		navigationVelocityServiceIn = portFactoryRegistry[connections.navigationVelocityServiceIn.roboticMiddleware]->createNavigationVelocityServiceIn(connections.navigationVelocityServiceIn.serviceName);
		
		// create client ports
		
		// create InputTaskTriggers and UpcallManagers
		localizationUpdateServiceInInputTaskTrigger = new Smart::InputTaskTrigger<CommBasicObjects::CommBasePositionUpdate>(localizationUpdateServiceIn);
		localizationUpdateServiceInUpcallManager = new LocalizationUpdateServiceInUpcallManager(localizationUpdateServiceIn);
		navigationVelocityServiceInInputTaskTrigger = new Smart::InputTaskTrigger<CommBasicObjects::CommNavigationVelocity>(navigationVelocityServiceIn);
		navigationVelocityServiceInUpcallManager = new NavigationVelocityServiceInUpcallManager(navigationVelocityServiceIn);
		
		// create input-handler
		localizationUpdateHandler = new LocalizationUpdateHandler(localizationUpdateServiceIn, connections.localizationUpdateHandler.prescale);
		navigationVelocityHandler = new NavigationVelocityHandler(navigationVelocityServiceIn, connections.navigationVelocityHandler.prescale);
		
		// create request-handlers
		baseStateQueryHandler = new BaseStateQueryHandler(baseStateAnswerer);
		
		// create state pattern
		stateChangeHandler = new SmartStateChangeHandler();
		stateSlave = new SmartACE::StateSlave(component, stateChangeHandler);
		status = stateSlave->setUpInitialState(connections.component.initialComponentMode);
		if (status != Smart::SMART_OK) std::cerr << status << "; failed setting initial ComponentMode: " << connections.component.initialComponentMode << std::endl;
		// activate state slave
		status = stateSlave->activate();
		if(status != Smart::SMART_OK) std::cerr << "ERROR: activate state" << std::endl;
		
		wiringSlave = new SmartACE::WiringSlave(component);
		// add client port to wiring slave
		
		// create parameter slave
		param = new SmartACE::ParameterSlave(component, &paramHandler);
		
		
		// create Task BatteryEventTask
		batteryEventTask = new BatteryEventTask(component);
		// configure input-links
		// configure task-trigger (if task is configurable)
		if(connections.batteryEventTask.trigger == "PeriodicTimer") {
			// create PeriodicTimerTrigger
			int microseconds = 1000*1000 / connections.batteryEventTask.periodicActFreq;
			if(microseconds > 0) {
				Smart::TimedTaskTrigger *triggerPtr = new Smart::TimedTaskTrigger();
				triggerPtr->attach(batteryEventTask);
				component->getTimerManager()->scheduleTimer(triggerPtr, (void *) 0, std::chrono::microseconds(microseconds), std::chrono::microseconds(microseconds));
				// store trigger in class member
				batteryEventTaskTrigger = triggerPtr;
			} else {
				std::cerr << "ERROR: could not set-up Timer with cycle-time " << microseconds << " as activation source for Task BatteryEventTask" << std::endl;
			}
		} else if(connections.batteryEventTask.trigger == "DataTriggered") {
			batteryEventTaskTrigger = getInputTaskTriggerFromString(connections.batteryEventTask.inPortRef);
			if(batteryEventTaskTrigger != NULL) {
				batteryEventTaskTrigger->attach(batteryEventTask, connections.batteryEventTask.prescale);
			} else {
				std::cerr << "ERROR: could not set-up InPort " << connections.batteryEventTask.inPortRef << " as activation source for Task BatteryEventTask" << std::endl;
			}
		} 
		
		// create Task PlayerTask
		playerTask = new PlayerTask(component);
		// configure input-links
		// configure task-trigger (if task is configurable)
		if(connections.playerTask.trigger == "PeriodicTimer") {
			// create PeriodicTimerTrigger
			int microseconds = 1000*1000 / connections.playerTask.periodicActFreq;
			if(microseconds > 0) {
				Smart::TimedTaskTrigger *triggerPtr = new Smart::TimedTaskTrigger();
				triggerPtr->attach(playerTask);
				component->getTimerManager()->scheduleTimer(triggerPtr, (void *) 0, std::chrono::microseconds(microseconds), std::chrono::microseconds(microseconds));
				// store trigger in class member
				playerTaskTrigger = triggerPtr;
			} else {
				std::cerr << "ERROR: could not set-up Timer with cycle-time " << microseconds << " as activation source for Task PlayerTask" << std::endl;
			}
		} else if(connections.playerTask.trigger == "DataTriggered") {
			playerTaskTrigger = getInputTaskTriggerFromString(connections.playerTask.inPortRef);
			if(playerTaskTrigger != NULL) {
				playerTaskTrigger->attach(playerTask, connections.playerTask.prescale);
			} else {
				std::cerr << "ERROR: could not set-up InPort " << connections.playerTask.inPortRef << " as activation source for Task PlayerTask" << std::endl;
			}
		} 
		
		
		// link observers with subjects
	} catch (const std::exception &ex) {
		std::cerr << "Uncaught std exception" << ex.what() << std::endl;
	} catch (...) {
		std::cerr << "Uncaught exception" << std::endl;
	}
}

// run the component
void ComponentPlayerStageSimulator::run()
{
	stateSlave->acquire("init");
	// startup all registered port-factories
	for(auto portFactory = portFactoryRegistry.begin(); portFactory != portFactoryRegistry.end(); portFactory++) 
	{
		portFactory->second->onStartup();
	}
	
	// startup all registered component-extensions
	for(auto extension = componentExtensionRegistry.begin(); extension != componentExtensionRegistry.end(); extension++) 
	{
		extension->second->onStartup();
	}
	stateSlave->release("init");
	
	// do not call this handler within the init state (see above) as this handler internally calls setStartupFinished() (this should be fixed in future)
	compHandler.onStartup();
	
	// this call blocks until the component is commanded to shutdown
	stateSlave->acquire("shutdown");
	
	// shutdown all registered component-extensions
	for(auto extension = componentExtensionRegistry.begin(); extension != componentExtensionRegistry.end(); extension++) 
	{
		extension->second->onShutdown();
	}
	
	// shutdown all registered port-factories
	for(auto portFactory = portFactoryRegistry.begin(); portFactory != portFactoryRegistry.end(); portFactory++) 
	{
		portFactory->second->onShutdown();
	}
	
	if(connections.component.useLogger == true) {
		//FIXME: use logging
		//Smart::LOGGER->stopLogging();
	}
	
	compHandler.onShutdown();
	
	stateSlave->release("shutdown");
}

// clean-up component's resources
void ComponentPlayerStageSimulator::fini()
{
	// unlink all observers
	
	// destroy all task instances
	// unlink all UpcallManagers
	// unlink the TaskTrigger
	if(batteryEventTaskTrigger != NULL){
		batteryEventTaskTrigger->detach(batteryEventTask);
		delete batteryEventTask;
	}
	// unlink all UpcallManagers
	// unlink the TaskTrigger
	if(playerTaskTrigger != NULL){
		playerTaskTrigger->detach(playerTask);
		delete playerTask;
	}

	// destroy all input-handler
	delete localizationUpdateHandler;
	delete navigationVelocityHandler;

	// destroy InputTaskTriggers and UpcallManagers
	delete localizationUpdateServiceInInputTaskTrigger;
	delete localizationUpdateServiceInUpcallManager;
	delete navigationVelocityServiceInInputTaskTrigger;
	delete navigationVelocityServiceInUpcallManager;

	// destroy client ports

	// destroy server ports
	delete baseStateAnswerer;
	delete baseStateAnswererInputTaskTrigger;
	delete baseStateServiceOut;
	delete batteryEventServiceOut;
	delete laserServiceOut;
	delete localizationUpdateServiceIn;
	delete navigationVelocityServiceIn;
	// destroy event-test handlers (if needed)
	batteryEventServiceOutEventTestHandler;
	
	// destroy request-handlers
	delete baseStateQueryHandler;
	
	delete stateSlave;
	// destroy state-change-handler
	delete stateChangeHandler;
	
	// destroy all master/slave ports
	delete wiringSlave;
	delete param;
	

	// destroy all registered component-extensions
	for(auto extension = componentExtensionRegistry.begin(); extension != componentExtensionRegistry.end(); extension++) 
	{
		extension->second->destroy();
	}

	// destroy all registered port-factories
	for(auto portFactory = portFactoryRegistry.begin(); portFactory != portFactoryRegistry.end(); portFactory++) 
	{
		portFactory->second->destroy();
	}
	
	// destruction of ComponentPlayerStageSimulatorROSExtension
	
	// destruction of OpcUaBackendComponentGeneratorExtension
	
	// destruction of PlainOpcUaComponentPlayerStageSimulatorExtension
	
}

void ComponentPlayerStageSimulator::loadParameter(int argc, char *argv[])
{
	/*
	 Parameters can be specified via command line --filename=<filename> or -f <filename>

	 With this parameter present:
	   - The component will look for the file in the current working directory,
	     a path relative to the current directory or any absolute path
	   - The component will use the default values if the file cannot be found

	 With this parameter absent:
	   - <Name of Component>.ini will be read from current working directory, if found there
	   - $SMART_ROOT/etc/<Name of Component>.ini will be read otherwise
	   - Default values will be used if neither found in working directory or /etc
	 */
	SmartACE::SmartIniParameter parameter;
	std::ifstream parameterfile;
	bool parameterFileFound = false;

	// load parameters
	try
	{
		// if paramfile is given as argument
		if(parameter.tryAddFileFromArgs(argc,argv,"filename", 'f'))
		{
			parameterFileFound = true;
			std::cout << "parameter file is loaded from an argv argument \n";
		} else if(parameter.searchFile("ComponentPlayerStageSimulator.ini", parameterfile)) {
			parameterFileFound = true;
			std::cout << "load ComponentPlayerStageSimulator.ini parameter file\n";
			parameter.addFile(parameterfile);
		} else {
			std::cout << "WARNING: ComponentPlayerStageSimulator.ini parameter file not found! (using default values or command line arguments)\n";
		}
		
		// add command line arguments to allow overwriting of parameters
		// from file
		parameter.addCommandLineArgs(argc,argv,"component");
		
		// initialize the naming service using the command line parameters parsed in the
		// SmartIniParameter class. The naming service parameters are expected to be in
		// the "component" parameter group.
		SmartACE::NAMING::instance()->checkForHelpArg(argc,argv);
		if(parameterFileFound) 
		{
			if(SmartACE::NAMING::instance()->init(parameter.getAllParametersFromGroup("component")) != 0) {
				// initialization of naming service failed
				throw std::logic_error( "<NamingService> Service initialization failed!\nPossible causes could be:\n-> Erroneous configuration.\n-> Naming service not reachable.\n" );
			}
		} else {
			if(SmartACE::NAMING::instance()->init(argc, argv) != 0) {
				// initialization of naming service failed
				throw std::logic_error( "<NamingService> Service initialization failed!\nPossible causes could be:\n-> Erroneous configuration.\n-> Naming service not reachable.\n" );
			}
		}
			
		// print all known parameters
		// parameter.print();
		
		//--- server port // client port // other parameter ---
		// load parameter
		parameter.getString("component", "name", connections.component.name);
		parameter.getString("component", "initialComponentMode", connections.component.initialComponentMode);
		if(parameter.checkIfParameterExists("component", "defaultScheduler")) {
			parameter.getString("component", "defaultScheduler", connections.component.defaultScheduler);
		}
		if(parameter.checkIfParameterExists("component", "useLogger")) {
			parameter.getBoolean("component", "useLogger", connections.component.useLogger);
		}
		
		
		// load parameters for server BaseStateAnswerer
		parameter.getString("BaseStateAnswerer", "serviceName", connections.baseStateAnswerer.serviceName);
		if(parameter.checkIfParameterExists("BaseStateAnswerer", "roboticMiddleware")) {
			parameter.getString("BaseStateAnswerer", "roboticMiddleware", connections.baseStateAnswerer.roboticMiddleware);
		}
		// load parameters for server BaseStateServiceOut
		parameter.getString("BaseStateServiceOut", "serviceName", connections.baseStateServiceOut.serviceName);
		if(parameter.checkIfParameterExists("BaseStateServiceOut", "roboticMiddleware")) {
			parameter.getString("BaseStateServiceOut", "roboticMiddleware", connections.baseStateServiceOut.roboticMiddleware);
		}
		// load parameters for server BatteryEventServiceOut
		parameter.getString("BatteryEventServiceOut", "serviceName", connections.batteryEventServiceOut.serviceName);
		if(parameter.checkIfParameterExists("BatteryEventServiceOut", "roboticMiddleware")) {
			parameter.getString("BatteryEventServiceOut", "roboticMiddleware", connections.batteryEventServiceOut.roboticMiddleware);
		}
		// load parameters for server LaserServiceOut
		parameter.getString("LaserServiceOut", "serviceName", connections.laserServiceOut.serviceName);
		if(parameter.checkIfParameterExists("LaserServiceOut", "roboticMiddleware")) {
			parameter.getString("LaserServiceOut", "roboticMiddleware", connections.laserServiceOut.roboticMiddleware);
		}
		// load parameters for server LocalizationUpdateServiceIn
		parameter.getString("LocalizationUpdateServiceIn", "serviceName", connections.localizationUpdateServiceIn.serviceName);
		if(parameter.checkIfParameterExists("LocalizationUpdateServiceIn", "roboticMiddleware")) {
			parameter.getString("LocalizationUpdateServiceIn", "roboticMiddleware", connections.localizationUpdateServiceIn.roboticMiddleware);
		}
		// load parameters for server NavigationVelocityServiceIn
		parameter.getString("NavigationVelocityServiceIn", "serviceName", connections.navigationVelocityServiceIn.serviceName);
		if(parameter.checkIfParameterExists("NavigationVelocityServiceIn", "roboticMiddleware")) {
			parameter.getString("NavigationVelocityServiceIn", "roboticMiddleware", connections.navigationVelocityServiceIn.roboticMiddleware);
		}
		
		// load parameters for task BatteryEventTask
		parameter.getDouble("BatteryEventTask", "minActFreqHz", connections.batteryEventTask.minActFreq);
		parameter.getDouble("BatteryEventTask", "maxActFreqHz", connections.batteryEventTask.maxActFreq);
		parameter.getString("BatteryEventTask", "triggerType", connections.batteryEventTask.trigger);
		if(connections.batteryEventTask.trigger == "PeriodicTimer") {
			parameter.getDouble("BatteryEventTask", "periodicActFreqHz", connections.batteryEventTask.periodicActFreq);
		} else if(connections.batteryEventTask.trigger == "DataTriggered") {
			parameter.getString("BatteryEventTask", "inPortRef", connections.batteryEventTask.inPortRef);
			parameter.getInteger("BatteryEventTask", "prescale", connections.batteryEventTask.prescale);
		}
		if(parameter.checkIfParameterExists("BatteryEventTask", "scheduler")) {
			parameter.getString("BatteryEventTask", "scheduler", connections.batteryEventTask.scheduler);
		}
		if(parameter.checkIfParameterExists("BatteryEventTask", "priority")) {
			parameter.getInteger("BatteryEventTask", "priority", connections.batteryEventTask.priority);
		}
		if(parameter.checkIfParameterExists("BatteryEventTask", "cpuAffinity")) {
			parameter.getInteger("BatteryEventTask", "cpuAffinity", connections.batteryEventTask.cpuAffinity);
		}
		// load parameters for task PlayerTask
		parameter.getDouble("PlayerTask", "minActFreqHz", connections.playerTask.minActFreq);
		parameter.getDouble("PlayerTask", "maxActFreqHz", connections.playerTask.maxActFreq);
		parameter.getString("PlayerTask", "triggerType", connections.playerTask.trigger);
		if(connections.playerTask.trigger == "PeriodicTimer") {
			parameter.getDouble("PlayerTask", "periodicActFreqHz", connections.playerTask.periodicActFreq);
		} else if(connections.playerTask.trigger == "DataTriggered") {
			parameter.getString("PlayerTask", "inPortRef", connections.playerTask.inPortRef);
			parameter.getInteger("PlayerTask", "prescale", connections.playerTask.prescale);
		}
		if(parameter.checkIfParameterExists("PlayerTask", "scheduler")) {
			parameter.getString("PlayerTask", "scheduler", connections.playerTask.scheduler);
		}
		if(parameter.checkIfParameterExists("PlayerTask", "priority")) {
			parameter.getInteger("PlayerTask", "priority", connections.playerTask.priority);
		}
		if(parameter.checkIfParameterExists("PlayerTask", "cpuAffinity")) {
			parameter.getInteger("PlayerTask", "cpuAffinity", connections.playerTask.cpuAffinity);
		}
		if(parameter.checkIfParameterExists("LocalizationUpdateHandler", "prescale")) {
			parameter.getInteger("LocalizationUpdateHandler", "prescale", connections.localizationUpdateHandler.prescale);
		}
		if(parameter.checkIfParameterExists("NavigationVelocityHandler", "prescale")) {
			parameter.getInteger("NavigationVelocityHandler", "prescale", connections.navigationVelocityHandler.prescale);
		}
		
		// load parameters for ComponentPlayerStageSimulatorROSExtension
		
		// load parameters for OpcUaBackendComponentGeneratorExtension
		
		// load parameters for PlainOpcUaComponentPlayerStageSimulatorExtension
		
		
		// load parameters for all registered component-extensions
		for(auto extension = componentExtensionRegistry.begin(); extension != componentExtensionRegistry.end(); extension++) 
		{
			extension->second->loadParameters(parameter);
		}
		
		paramHandler.loadParameter(parameter);
	
	} catch (const SmartACE::IniParameterError & e) {
		std::cerr << e.what() << std::endl;
	} catch (const std::exception &ex) {
		std::cerr << "Uncaught std::exception: " << ex.what() << std::endl;
	} catch (...) {
		std::cerr << "Uncaught exception" << std::endl;
	}
}
