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

#ifndef SMARTOBJECTRECOGNITION_OPC_UA_BACKEND_PORTFACTORY_HH_
#define SMARTOBJECTRECOGNITION_OPC_UA_BACKEND_PORTFACTORY_HH_

// include the main component-definition class
#include "SmartObjectRecognitionPortFactoryInterface.hh"

#include <thread>
#include <chrono>

// include SeRoNetSDK library
#include <SeRoNetSDK/SeRoNet/Utils/Task.hpp>
#include <SeRoNetSDK/SeRoNet/Utils/Component.hpp>

class SmartObjectRecognitionOpcUaBackendPortFactory: public SmartObjectRecognitionPortFactoryInterface
{
private:
	// internal component instance
	SeRoNet::Utils::Component *componentImpl;
	
	// component thread
	std::thread component_thread;
	
	// internal component thread method
	int task_execution();
public:
	SmartObjectRecognitionOpcUaBackendPortFactory();
	virtual ~SmartObjectRecognitionOpcUaBackendPortFactory();

	virtual void initialize(SmartObjectRecognition *component, int argc, char* argv[]) override;
	virtual int onStartup() override;

	virtual Smart::IQueryClientPattern<CommManipulatorObjects::CommManipulatorId, DomainVision::Comm3dPointCloud> * createPointCloudQueryServiceReq() override;
	virtual Smart::IQueryClientPattern<CommBasicObjects::CommVoid, DomainVision::CommRGBDImage> * createRGBDImageQueryServiceReq() override;
	virtual Smart::IQueryClientPattern<CommBasicObjects::CommVoid, DomainVision::CommVideoImage> * createRGBImageQueryServiceReq() override;
	
	virtual Smart::IQueryServerPattern<CommObjectRecognitionObjects::CommObjectRecognitionId, CommObjectRecognitionObjects::CommObjectRecognitionEnvironment> * createEnvironmentQueryServiceAnsw(const std::string &serviceName) override;
	virtual Smart::IEventServerPattern<CommBasicObjects::CommVoid, CommObjectRecognitionObjects::CommObjectRecognitionEventResult, CommObjectRecognitionObjects::CommObjectRecognitionEventState> * createObjectEventServiceOut(const std::string &serviceName, std::shared_ptr<Smart::IEventTestHandler<CommBasicObjects::CommVoid, CommObjectRecognitionObjects::CommObjectRecognitionEventResult, CommObjectRecognitionObjects::CommObjectRecognitionEventState>> objectEventServiceOutEventTestHandler) override;
	virtual Smart::IQueryServerPattern<CommObjectRecognitionObjects::CommObjectRecognitionId, CommObjectRecognitionObjects::CommObjectRecognitionObjectProperties> * createObjectQueryServiceAnsw(const std::string &serviceName) override;
	
	virtual int onShutdown(const std::chrono::steady_clock::duration &timeoutTime=std::chrono::seconds(2)) override;
	virtual void destroy() override;
};

#endif /* SMARTOBJECTRECOGNITION_SERONET_SDK_PORTFACTORY_HH_ */
