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

#include "SmartCdlServerAcePortFactory.hh"

// create a static instance of the default AcePortFactory
static SmartCdlServerAcePortFactory acePortFactory;

SmartCdlServerAcePortFactory::SmartCdlServerAcePortFactory()
{  
	componentImpl = 0;
	SmartCdlServer::instance()->addPortFactory("ACE_SmartSoft", this);
}

SmartCdlServerAcePortFactory::~SmartCdlServerAcePortFactory()
{  }

void SmartCdlServerAcePortFactory::initialize(SmartCdlServer *component, int argc, char* argv[])
{
	if(component->connections.component.defaultScheduler != "DEFAULT") {
		ACE_Sched_Params sched_params(ACE_SCHED_OTHER, ACE_THR_PRI_OTHER_DEF);
		if(component->connections.component.defaultScheduler == "FIFO") {
			sched_params.policy(ACE_SCHED_FIFO);
			sched_params.priority(ACE_THR_PRI_FIFO_MIN);
		} else if(component->connections.component.defaultScheduler == "RR") {
			sched_params.policy(ACE_SCHED_RR);
			sched_params.priority(ACE_THR_PRI_RR_MIN);
		}
		// create new instance of the SmartSoft component with customized scheuling parameters 
		componentImpl = new SmartCdlServerImpl(component->connections.component.name, argc, argv, sched_params);
	} else {
		// create new instance of the SmartSoft component
		componentImpl = new SmartCdlServerImpl(component->connections.component.name, argc, argv);
	}
}

int SmartCdlServerAcePortFactory::onStartup()
{
	return componentImpl->startComponentInfrastructure();
}

Smart::IPushClientPattern<CommBasicObjects::CommMobileLaserScan> * SmartCdlServerAcePortFactory::createLaserClient2()
{
	return new SmartACE::PushClient<CommBasicObjects::CommMobileLaserScan>(componentImpl);
}

Smart::IPushClientPattern<CommBasicObjects::CommBaseState> * SmartCdlServerAcePortFactory::createBaseStateClient()
{
	return new SmartACE::PushClient<CommBasicObjects::CommBaseState>(componentImpl);
}

Smart::ISendClientPattern<CommBasicObjects::CommNavigationVelocity> * SmartCdlServerAcePortFactory::createNavVelSendClient()
{
	return new SmartACE::SendClient<CommBasicObjects::CommNavigationVelocity>(componentImpl);
}

Smart::IPushClientPattern<CommBasicObjects::CommMobileIRScan> * SmartCdlServerAcePortFactory::createIRClient()
{
	return new SmartACE::PushClient<CommBasicObjects::CommMobileIRScan>(componentImpl);
}

Smart::IPushClientPattern<CommNavigationObjects::CommPlannerGoal> * SmartCdlServerAcePortFactory::createPlannerClient()
{
	return new SmartACE::PushClient<CommNavigationObjects::CommPlannerGoal>(componentImpl);
}

Smart::IPushClientPattern<CommRobotinoObjects::CommPathNavigationGoal> * SmartCdlServerAcePortFactory::createPathNavigationGoalClient()
{
	return new SmartACE::PushClient<CommRobotinoObjects::CommPathNavigationGoal>(componentImpl);
}

Smart::IPushClientPattern<CommBasicObjects::CommMobileLaserScan> * SmartCdlServerAcePortFactory::createLaserClient()
{
	return new SmartACE::PushClient<CommBasicObjects::CommMobileLaserScan>(componentImpl);
}

Smart::IPushClientPattern<CommTrackingObjects::CommTrackingGoal> * SmartCdlServerAcePortFactory::createTrackingClient()
{
	return new SmartACE::PushClient<CommTrackingObjects::CommTrackingGoal>(componentImpl);
}


Smart::IEventServerPattern<CommNavigationObjects::CommCdlRobotBlockedEventParameter, CommNavigationObjects::CommCdlRobotBlockedEventResult, CommNavigationObjects::CommCdlRobotBlockedState,SmartACE::EventId> * SmartCdlServerAcePortFactory::createRobotBlockedEventServer(const std::string &serviceName, Smart::IEventTestHandler<CommNavigationObjects::CommCdlRobotBlockedEventParameter, CommNavigationObjects::CommCdlRobotBlockedEventResult, CommNavigationObjects::CommCdlRobotBlockedState> *robotBlockedEventServerEventTestHandler)
{
	return new SmartACE::EventServer<CommNavigationObjects::CommCdlRobotBlockedEventParameter, CommNavigationObjects::CommCdlRobotBlockedEventResult, CommNavigationObjects::CommCdlRobotBlockedState>(componentImpl, serviceName, robotBlockedEventServerEventTestHandler);
}

Smart::ISendServerPattern<CommBasicObjects::CommNavigationVelocity> * SmartCdlServerAcePortFactory::createNavVelSendServer(const std::string &serviceName)
{
	return new SmartACE::SendServer<CommBasicObjects::CommNavigationVelocity>(componentImpl, serviceName);
}

Smart::IEventServerPattern<CommNavigationObjects::CommCdlGoalEventParameter, CommNavigationObjects::CommCdlGoalEventResult, CommNavigationObjects::CdlGoalEventState,SmartACE::EventId> * SmartCdlServerAcePortFactory::createGoalEventServer(const std::string &serviceName, Smart::IEventTestHandler<CommNavigationObjects::CommCdlGoalEventParameter, CommNavigationObjects::CommCdlGoalEventResult, CommNavigationObjects::CdlGoalEventState> *goalEventServerEventTestHandler)
{
	return new SmartACE::EventServer<CommNavigationObjects::CommCdlGoalEventParameter, CommNavigationObjects::CommCdlGoalEventResult, CommNavigationObjects::CdlGoalEventState>(componentImpl, serviceName, goalEventServerEventTestHandler);
}


SmartACE::SmartComponent* SmartCdlServerAcePortFactory::getComponentImpl()
{
	return componentImpl;
}

int SmartCdlServerAcePortFactory::onShutdown(const std::chrono::steady_clock::duration &timeoutTime)
{
	componentImpl->stopComponentInfrastructure(timeoutTime);
	return 0;
}

void SmartCdlServerAcePortFactory::destroy()
{
	// clean-up component's internally used resources (internally used communication middleware) 
	componentImpl->cleanUpComponentResources();
	delete componentImpl;
}
