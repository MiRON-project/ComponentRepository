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
#include "SmartLaserLMS200Server.hh"
#include "smartTimedTaskTrigger.h"
//FIXME: implement logging
//#include "smartGlobalLogger.hh"


// constructor
SmartLaserLMS200Server::SmartLaserLMS200Server()
{
	std::cout << "constructor of SmartLaserLMS200Server\n";
	
	component = NULL;
	
	// set all pointer members to NULL
	baseStateIn = NULL;
	baseStateInInputTaskTrigger = NULL;
	baseStateInUpcallManager = NULL;
	//coordinationPort = NULL;
	laserQueryServiceAnsw = NULL;
	laserQueryServiceAnswInputTaskTrigger = NULL;
	laserQueryServiceAnswHandler = NULL;
	laserScanOut = NULL;
	laserTask = NULL;
	laserTaskTrigger = NULL;
	//smartLaserLMS200ServerParams = NULL;
	stateChangeHandler = NULL;
	stateSlave = NULL;
	wiringSlave = NULL;
	param = NULL;
	
	
	// set default ini parameter values
	connections.component.name = "SmartLaserLMS200Server";
	connections.component.initialComponentMode = "Neutral";
	connections.component.defaultScheduler = "DEFAULT";
	connections.component.useLogger = false;
	
	connections.laserQueryServiceAnsw.serviceName = "LaserQueryServiceAnsw";
	connections.laserScanOut.serviceName = "LaserScanOut";
	connections.baseStateIn.initialConnect = false;
	connections.baseStateIn.wiringName = "BaseStateIn";
	connections.baseStateIn.serverName = "unknown";
	connections.baseStateIn.serviceName = "unknown";
	connections.baseStateIn.interval = 1;
	// scheduling default parameters
	connections.laserTask.scheduler = "DEFAULT";
	connections.laserTask.priority = -1;
	connections.laserTask.cpuAffinity = -1;
}



/**
 * Notify the component that setup/initialization is finished.
 * You may call this function from anywhere in the component.
 *
 * Set component's internal lifecycle state automaton (if any) into 
 * Alive mode (from here on the component is ready to provide its services)
 */
void SmartLaserLMS200Server::setStartupFinished() {
	stateSlave->setWaitState("Alive");
	std::cout << "ComponentDefinition initialization/startup finished." << std::endl;
}


Smart::StatusCode SmartLaserLMS200Server::connectBaseStateIn(const std::string &serverName, const std::string &serviceName) {
	Smart::StatusCode status;
	
	if(connections.baseStateIn.initialConnect == false) {
		return Smart::SMART_OK;
	}
	std::cout << "connecting to: " << serverName << "; " << serviceName << std::endl;
	status = baseStateIn->connect(serverName, serviceName);
	while(status != Smart::SMART_OK)
	{
		ACE_OS::sleep(ACE_Time_Value(0,500000));
		status = COMP->baseStateIn->connect(serverName, serviceName);
	}
	std::cout << "connected.\n";
	baseStateIn->subscribe(connections.baseStateIn.interval);
	return status;
}


/**
 * First connect ALL client ports contained in this component, then start all services:
 * activate state, push, etc...
 */
Smart::StatusCode SmartLaserLMS200Server::connectAndStartAllServices() {
	Smart::StatusCode status = Smart::SMART_OK;
	
	status = connectBaseStateIn(connections.baseStateIn.serverName, connections.baseStateIn.serviceName);
	if(status != Smart::SMART_OK) return status;
	return status;
}

/**
 * Start all tasks contained in this component.
 */
void SmartLaserLMS200Server::startAllTasks() {
	// start task LaserTask
	if(connections.laserTask.scheduler != "DEFAULT") {
		ACE_Sched_Params laserTask_SchedParams(ACE_SCHED_OTHER, ACE_THR_PRI_OTHER_DEF);
		if(connections.laserTask.scheduler == "FIFO") {
			laserTask_SchedParams.policy(ACE_SCHED_FIFO);
			laserTask_SchedParams.priority(ACE_THR_PRI_FIFO_MIN);
		} else if(connections.laserTask.scheduler == "RR") {
			laserTask_SchedParams.policy(ACE_SCHED_RR);
			laserTask_SchedParams.priority(ACE_THR_PRI_RR_MIN);
		}
		laserTask->start(laserTask_SchedParams, connections.laserTask.cpuAffinity);
	} else {
		laserTask->start();
	}
}

/**
 * Start all timers contained in this component
 */
void SmartLaserLMS200Server::startAllTimers() {
}


Smart::TaskTriggerSubject* SmartLaserLMS200Server::getInputTaskTriggerFromString(const std::string &client)
{
	if(client == "BaseStateIn") return baseStateInInputTaskTrigger;
	
	return NULL;
}


void SmartLaserLMS200Server::init(int argc, char *argv[])
{
	try {
		Smart::StatusCode status;
		
		// load initial parameters from ini-file (if found)
		loadParameter(argc, argv);
		
		// print out the actual parameters which are used to initialize the component
		std::cout << " \nComponentDefinition Initial-Parameters:\n" << COMP->getGlobalState() << std::endl;
		if(connections.component.defaultScheduler != "DEFAULT") {
			ACE_Sched_Params sched_params(ACE_SCHED_OTHER, ACE_THR_PRI_OTHER_DEF);
			if(connections.component.defaultScheduler == "FIFO") {
				sched_params.policy(ACE_SCHED_FIFO);
				sched_params.priority(ACE_THR_PRI_FIFO_MIN);
			} else if(connections.component.defaultScheduler == "RR") {
				sched_params.policy(ACE_SCHED_RR);
				sched_params.priority(ACE_THR_PRI_RR_MIN);
			}
			// create new instance of the SmartSoft component with customized scheuling parameters 
			component = new SmartLaserLMS200ServerImpl(connections.component.name, argc, argv, sched_params);
		} else {
			// create new instance of the SmartSoft component
			component = new SmartLaserLMS200ServerImpl(connections.component.name, argc, argv);
		}
		
		
		std::cout << "ComponentDefinition SmartLaserLMS200Server is named " << connections.component.name << std::endl;
		
		if(connections.component.useLogger == true) {
			//FIXME: use logging
			//Smart::LOGGER->openLogFileInFolder("data/"+connections.component.name);
			//Smart::LOGGER->startLogging();
		}

		// create event-test handlers (if needed)
		
		// create server ports
		// TODO: set minCycleTime from Ini-file
		laserQueryServiceAnsw = new SmartACE::QueryServer<CommBasicObjects::CommVoid, CommBasicObjects::CommMobileLaserScan>(component, connections.laserQueryServiceAnsw.serviceName);
		laserQueryServiceAnswInputTaskTrigger = new Smart::QueryServerTaskTrigger<CommBasicObjects::CommVoid, CommBasicObjects::CommMobileLaserScan,SmartACE::QueryId>(laserQueryServiceAnsw);
		laserScanOut = new SmartACE::PushServer<CommBasicObjects::CommMobileLaserScan>(component, connections.laserScanOut.serviceName);
		
		// create client ports
		baseStateIn = new SmartACE::PushClient<CommBasicObjects::CommBaseState>(component);
		
		// create InputTaskTriggers and UpcallManagers
		baseStateInInputTaskTrigger = new Smart::InputTaskTrigger<CommBasicObjects::CommBaseState>(baseStateIn);
		baseStateInUpcallManager = new BaseStateInUpcallManager(baseStateIn);
		
		// create input-handler
		
		// create request-handlers
		laserQueryServiceAnswHandler = new LaserQueryServiceAnswHandler(laserQueryServiceAnsw);
		
		
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
		dynamic_cast<SmartACE::PushClient<CommBasicObjects::CommBaseState>*>(baseStateIn)->add(wiringSlave, connections.baseStateIn.wiringName);
		
		// create parameter slave
		param = new SmartACE::ParameterSlave(component, &paramHandler);
		
		
		// create Task LaserTask
		laserTask = new LaserTask(component);
		// configure input-links
		baseStateInUpcallManager->attach(laserTask);
		// configure task-trigger (if task is configurable)
		
		
		// link observers with subjects
		laserTask->attach_interaction_observer(laserQueryServiceAnswHandler);
	} catch (const std::exception &ex) {
		std::cerr << "Uncaught std exception" << ex.what() << std::endl;
	} catch (...) {
		std::cerr << "Uncaught exception" << std::endl;
	}
}

// run the component
void SmartLaserLMS200Server::run()
{
	compHandler.onStartup();
	
	
	// coponent will now start running and will continue (block in the run method) until it is commanded to shutdown (i.e. by a SIGINT signal)
	component->run();
	// component was signalled to shutdown
	// 1) signall all tasks to shutdown as well (and give them 2 seconds time to cooperate)
	// if time exceeds, component is killed without further clean-up
	component->closeAllAssociatedTasks(2);
	
	if(connections.component.useLogger == true) {
		//FIXME: use logging
		//Smart::LOGGER->stopLogging();
	}
	
	compHandler.onShutdown();
	
	
	// unlink all observers
	laserTask->detach_interaction_observer(laserQueryServiceAnswHandler);
	
	// destroy all task instances
	// unlink all UpcallManagers
	baseStateInUpcallManager->detach(laserTask);
	// unlink the TaskTrigger
	laserTaskTrigger->detach(laserTask);
	delete laserTask;

	// destroy all input-handler

	// destroy InputTaskTriggers and UpcallManagers
	delete baseStateInInputTaskTrigger;
	delete baseStateInUpcallManager;

	// destroy client ports
	delete baseStateIn;

	// destroy server ports
	delete laserQueryServiceAnsw;
	delete laserQueryServiceAnswInputTaskTrigger;
	delete laserScanOut;
	// destroy event-test handlers (if needed)
	
	// destroy request-handlers
	delete laserQueryServiceAnswHandler;
	

	delete stateSlave;
	// destroy state-change-handler
	delete stateChangeHandler;
	
	// destroy all master/slave ports
	delete wiringSlave;
	delete param;
	

	// clean-up component's internally used resources (internally used communication middleware) 
	component->cleanUpComponentResources();
	
	
	// finally delete the component itself
	delete component;
}

void SmartLaserLMS200Server::loadParameter(int argc, char *argv[])
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
		} else if(parameter.searchFile("SmartLaserLMS200Server.ini", parameterfile)) {
			parameterFileFound = true;
			std::cout << "load SmartLaserLMS200Server.ini parameter file\n";
			parameter.addFile(parameterfile);
		} else {
			std::cout << "WARNING: SmartLaserLMS200Server.ini parameter file not found! (using default values or command line arguments)\n";
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
		
		// load parameters for client BaseStateIn
		parameter.getBoolean("BaseStateIn", "initialConnect", connections.baseStateIn.initialConnect);
		parameter.getString("BaseStateIn", "serviceName", connections.baseStateIn.serviceName);
		parameter.getString("BaseStateIn", "serverName", connections.baseStateIn.serverName);
		parameter.getString("BaseStateIn", "wiringName", connections.baseStateIn.wiringName);
		parameter.getInteger("BaseStateIn", "interval", connections.baseStateIn.interval);
		
		
		// load parameters for server LaserQueryServiceAnsw
		parameter.getString("LaserQueryServiceAnsw", "serviceName", connections.laserQueryServiceAnsw.serviceName);
		// load parameters for server LaserScanOut
		parameter.getString("LaserScanOut", "serviceName", connections.laserScanOut.serviceName);
		
		// load parameters for task LaserTask
		if(parameter.checkIfParameterExists("LaserTask", "scheduler")) {
			parameter.getString("LaserTask", "scheduler", connections.laserTask.scheduler);
		}
		if(parameter.checkIfParameterExists("LaserTask", "priority")) {
			parameter.getInteger("LaserTask", "priority", connections.laserTask.priority);
		}
		if(parameter.checkIfParameterExists("LaserTask", "cpuAffinity")) {
			parameter.getInteger("LaserTask", "cpuAffinity", connections.laserTask.cpuAffinity);
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
