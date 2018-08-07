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
#ifndef _JOYSTICKNAVTASK_CORE_HH
#define _JOYSTICKNAVTASK_CORE_HH
	
#include "aceSmartSoft.hh"

// include upcall interface
#include "JoystickServiceInUpcallInterface.hh"

// include communication-objects for output ports
#include <CommBasicObjects/CommNavigationVelocity.hh>

// include all interaction-observer interfaces
#include <JoystickNavTaskObserverInterface.hh>
	
class JoystickNavTaskCore
:	public SmartACE::ManagedTask
,	public Smart::TaskTriggerSubject
,	public JoystickServiceInUpcallInterface
{
private:
	bool useDefaultState; 
	bool useLogging;
	int taskLoggingId;
	unsigned int currentUpdateCount;
	
	Smart::StatusCode joystickServiceInStatus;
	CommBasicObjects::CommJoystick joystickServiceInObject;
	
protected:
	virtual int execute_protected_region();
	
	virtual void updateAllCommObjects();
	
	virtual int getPreviousCommObjId();
	
	void triggerLogEntry(const int& idOffset);
	
	
	// overload and implement this method in derived classes to immediately get all incoming updates from JoystickServiceIn (as soon as they arrive)
	virtual void on_JoystickServiceIn(const CommBasicObjects::CommJoystick &input) {
		// no-op
	}
	
	// this method can be safely used from the thread in derived classes
	inline Smart::StatusCode joystickServiceInGetUpdate(CommBasicObjects::CommJoystick &joystickServiceInObject) const
	{
		// copy local object buffer and return the last status code
		joystickServiceInObject = this->joystickServiceInObject;
		return joystickServiceInStatus;
	}
	
	// this method is meant to be used in derived classes
	Smart::StatusCode navVelServiceOutPut(CommBasicObjects::CommNavigationVelocity &navVelServiceOutDataObject);
	
/**
 * Implementation of the Subject part of an InteractionObserver
 */
private:
	std::mutex interaction_observers_mutex;
	std::list<JoystickNavTaskObserverInterface*> interaction_observers;
protected:
	void notify_all_interaction_observers();
public:
	void attach_interaction_observer(JoystickNavTaskObserverInterface *observer);
	void detach_interaction_observer(JoystickNavTaskObserverInterface *observer);

public:
	JoystickNavTaskCore(Smart::IComponent *comp, const bool &useDefaultState=true)
	:	SmartACE::ManagedTask(comp)
	,	useDefaultState(useDefaultState)
	,	useLogging(false)
	,	taskLoggingId(0)
	,	currentUpdateCount(0)
	,	joystickServiceInStatus(Smart::SMART_DISCONNECTED)
	,	joystickServiceInObject()
	{  }
	virtual ~JoystickNavTaskCore()
	{  }
	
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
