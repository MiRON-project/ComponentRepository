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
#ifndef _LASERTASK_HH
#define _LASERTASK_HH

#include "LaserTaskCore.hh"
	
class LaserTask  : public LaserTaskCore
{
private:
	int counter;
public:
	LaserTask(SmartACE::SmartComponent *comp);
	virtual ~LaserTask();
	
	virtual int on_entry();
	virtual int on_execute();
	virtual int on_exit();
};

#endif
