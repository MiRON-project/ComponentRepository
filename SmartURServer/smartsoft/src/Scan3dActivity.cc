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
#include "Scan3dActivity.hh"
#include "SmartURServer.hh"

#include <iostream>

Scan3dActivity::Scan3dActivity(SmartACE::SmartComponent *comp) 
:	Scan3dActivityCore(comp)
{
	std::cout << "constructor Scan3dActivity\n";
}
Scan3dActivity::~Scan3dActivity() 
{
	std::cout << "destructor Scan3dActivity\n";
}


void Scan3dActivity::on_requestScan3dSendServer(const CommManipulatorObjects::CommManipulatorRequestScan3d &input)
{
	// upcall triggered from InputPort requestScan3dSendServer
	// - use a local mutex here, because this upcal is called asynchroneously from outside of this task
	// - do not use longer blocking calls here since this upcall blocks the InputPort requestScan3dSendServer
	// - if you need to implement a long-running procedure, do so within the on_execute() method and in
	//   there, use the method requestScan3dSendServerGetUpdate(input) to get a copy of the input object
}

int Scan3dActivity::on_entry()
{
	// do initialization procedures here, which are called once, each time the task is started
	// it is possible to return != 0 (e.g. when initialization fails) then the task is not executed further
	return 0;
}
int Scan3dActivity::on_execute()
{
	// this method is called from an outside loop,
	// hence, NEVER use an infinite loop (like "while(1)") here inside!!!
	// also do not use blocking calls which do not result from smartsoft kernel
	
	// to get the incoming data, use this methods:
	Smart::StatusCode status;
	CommManipulatorObjects::CommManipulatorRequestScan3d requestScan3dSendServerObject;
	status = this->requestScan3dSendServerGetUpdate(requestScan3dSendServerObject);
	if(status != Smart::SMART_OK) {
		std::cerr << status << std::endl;
		// return 0;
	} else {
		std::cout << "received: " << requestScan3dSendServerObject << std::endl;
	}

	std::cout << "Hello from Scan3dActivity " << std::endl;

	// it is possible to return != 0 (e.g. when the task detects errors), then the outer loop breaks and the task stops
	return 0;
}
int Scan3dActivity::on_exit()
{
	// use this method to clean-up resources which are initialized in on_entry() and needs to be freed before the on_execute() can be called again
	return 0;
}
