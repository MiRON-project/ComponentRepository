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

#include "ComponentKinectV2ServerOpcUaBackendPortFactory.hh"

// include all potentially required pattern implementations
#include <SeRoNetSDK/SeRoNet/OPCUA/Client/PushClient.hpp>
#include <SeRoNetSDK/SeRoNet/OPCUA/Client/EventClient.hpp>
#include <SeRoNetSDK/SeRoNet/OPCUA/Client/QClientOPCUA.hpp>
#include <SeRoNetSDK/SeRoNet/OPCUA/Client/SendClient.hpp>
#include <SeRoNetSDK/SeRoNet/OPCUA/Client/QueryClient.hpp>

#include <SeRoNetSDK/SeRoNet/OPCUA/Server/PushServer.hpp>
#include <SeRoNetSDK/SeRoNet/OPCUA/Server/EventServer.hpp>
#include <SeRoNetSDK/SeRoNet/OPCUA/Server/SendServer.hpp>
#include <SeRoNetSDK/SeRoNet/OPCUA/Server/QueryServer.hpp>

// include referenced CommunicationObject SeRoNetSDK self description implementations
#include "CommBasicObjectsOpcUa/CommBaseStateOpcUa.hh"
#include "CommBasicObjectsOpcUa/CommDevicePoseStateOpcUa.hh"
#include "CommBasicObjectsOpcUa/CommVoidOpcUa.hh"
#include "DomainVisionOpcUa/CommRGBDImageOpcUa.hh"
#include "DomainVisionOpcUa/CommVideoImageOpcUa.hh"

// create a static instance of the OpcUaBackendPortFactory
static ComponentKinectV2ServerOpcUaBackendPortFactory OpcUaBackendPortFactory;

ComponentKinectV2ServerOpcUaBackendPortFactory::ComponentKinectV2ServerOpcUaBackendPortFactory()
{  
	componentImpl = 0;
	ComponentKinectV2Server::instance()->addPortFactory("OpcUa_SeRoNet", this);
}

ComponentKinectV2ServerOpcUaBackendPortFactory::~ComponentKinectV2ServerOpcUaBackendPortFactory()
{  }

void ComponentKinectV2ServerOpcUaBackendPortFactory::initialize(ComponentKinectV2Server *component, int argc, char* argv[])
{
	componentImpl = new SeRoNet::Utils::Component(component->connections.component.name);
}

int ComponentKinectV2ServerOpcUaBackendPortFactory::onStartup()
{
	if (!component_thread.joinable()) {
    	component_thread = std::thread(&ComponentKinectV2ServerOpcUaBackendPortFactory::task_execution, this);
    	return 0;
    }
	return -1;
}

Smart::IPushClientPattern<CommBasicObjects::CommBaseState> * ComponentKinectV2ServerOpcUaBackendPortFactory::createBasePushTimedClient()
{
	return new SeRoNet::OPCUA::Client::PushClient<CommBasicObjects::CommBaseState>(componentImpl);
}

Smart::IPushClientPattern<CommBasicObjects::CommDevicePoseState> * ComponentKinectV2ServerOpcUaBackendPortFactory::createPtuPosePushNewestClient()
{
	return new SeRoNet::OPCUA::Client::PushClient<CommBasicObjects::CommDevicePoseState>(componentImpl);
}


Smart::IPushServerPattern<DomainVision::CommVideoImage> * ComponentKinectV2ServerOpcUaBackendPortFactory::createColorImagePushNewestServer(const std::string &serviceName)
{
	return new SeRoNet::OPCUA::Server::PushServer<DomainVision::CommVideoImage>(componentImpl, serviceName);
}

Smart::IQueryServerPattern<CommBasicObjects::CommVoid, DomainVision::CommVideoImage> * ComponentKinectV2ServerOpcUaBackendPortFactory::createColorImageQueryServer(const std::string &serviceName)
{
	return new SeRoNet::OPCUA::Server::QueryServer<CommBasicObjects::CommVoid, DomainVision::CommVideoImage>(componentImpl, serviceName);
}

Smart::IPushServerPattern<DomainVision::CommRGBDImage> * ComponentKinectV2ServerOpcUaBackendPortFactory::createImagePushNewestServer(const std::string &serviceName)
{
	return new SeRoNet::OPCUA::Server::PushServer<DomainVision::CommRGBDImage>(componentImpl, serviceName);
}

Smart::IQueryServerPattern<CommBasicObjects::CommVoid, DomainVision::CommRGBDImage> * ComponentKinectV2ServerOpcUaBackendPortFactory::createImageQueryV2Server(const std::string &serviceName)
{
	return new SeRoNet::OPCUA::Server::QueryServer<CommBasicObjects::CommVoid, DomainVision::CommRGBDImage>(componentImpl, serviceName);
}


int ComponentKinectV2ServerOpcUaBackendPortFactory::task_execution()
{
	componentImpl->run();
	return 0;
}

int ComponentKinectV2ServerOpcUaBackendPortFactory::onShutdown(const std::chrono::steady_clock::duration &timeoutTime)
{
	// stop component-internal infrastructure
	componentImpl->stopRunning();
	// wait on component thread to exit
	if (component_thread.joinable()) {
		// FIXME: don't wait infinetly (use timeoutTime here)
    	component_thread.join();
    }
	return 0;
}

void ComponentKinectV2ServerOpcUaBackendPortFactory::destroy()
{
	// clean-up component's internally used resources
	delete componentImpl;
}
