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
#ifndef _LASERTASK_CORE_HH
#define _LASERTASK_CORE_HH
	
#include "aceSmartSoft.hh"

// include upcall interface
#include "BaseStateInUpcallInterface.hh"

// include communication-objects for output ports
#include <CommBasicObjects/CommMobileLaserScan.hh>

// include all interaction-observer interfaces
#include <LaserTaskObserverInterface.hh>


class LaserTaskCore
:	public SmartACE::ManagedTask
,	public Smart::TaskTriggerSubject
,	public BaseStateInUpcallInterface
{
private:
	bool useDefaultState; 
	bool useLogging;
	int taskLoggingId;
	unsigned int currentUpdateCount;
	
	Smart::StatusCode baseStateInStatus;
	CommBasicObjects::CommBaseState baseStateInObject;
	
	
protected:
	virtual int execute_protected_region();
	
	virtual void updateAllCommObjects();
	
	virtual int getPreviousCommObjId();
	
	void triggerLogEntry(const int& idOffset);
	
	
	// overload and implement this method in derived classes to immediately get all incoming updates from BaseStateIn (as soon as they arrive)
	virtual void on_BaseStateIn(const CommBasicObjects::CommBaseState &input) {
		// no-op
	}
	
	// this method can be safely used from the thread in derived classes
	inline Smart::StatusCode baseStateInGetUpdate(CommBasicObjects::CommBaseState &baseStateInObject) const
	{
		// copy local object buffer and return the last status code
		baseStateInObject = this->baseStateInObject;
		return baseStateInStatus;
	}
	
	// this method is meant to be used in derived classes
	Smart::StatusCode laserScanOutPut(CommBasicObjects::CommMobileLaserScan &laserScanOutDataObject);
	
	
/**
 * Implementation of the Subject part of an InteractionObserver
 */
private:
	std::mutex interaction_observers_mutex;
	std::list<LaserTaskObserverInterface*> interaction_observers;
protected:
	void notify_all_interaction_observers();
public:
	void attach_interaction_observer(LaserTaskObserverInterface *observer);
	void detach_interaction_observer(LaserTaskObserverInterface *observer);

public:
	LaserTaskCore(Smart::IComponent *comp, const bool &useDefaultState=true);
	virtual ~LaserTaskCore();
	
	inline void setUpLogging(const int &taskNbr, const bool &useLogging=true) {
		this->taskLoggingId = taskNbr;
		this->useLogging = useLogging;
	}
	
	inline bool isLoggingActive() const {
		return useLogging;
	}
	
	inline int getLoggingID() const {
		return taskLoggingId;
	}
	
	inline int getCurrentUpdateCount() const {
		return currentUpdateCount;
	}
	
};
#endif
