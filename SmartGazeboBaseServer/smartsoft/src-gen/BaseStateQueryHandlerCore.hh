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
#ifndef _BASESTATEQUERYHANDLER_CORE_HH
#define _BASESTATEQUERYHANDLER_CORE_HH
		
#include "aceSmartSoft.hh"

#include <CommBasicObjects/CommBaseState.hh>
#include <CommBasicObjects/CommVoid.hh>

// include the input interfaces (if any)

// include all interaction-observer interfaces
#include <BaseStateQueryHandlerObserverInterface.hh>
#include <BaseStateTaskObserverInterface.hh>

class BaseStateQueryHandlerCore 
:	public Smart::IQueryServerHandler<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState, SmartACE::QueryId>
,	public Smart::TaskTriggerSubject
,	public BaseStateTaskObserverInterface
{
private:

	virtual void updateAllCommObjects();

/**
 * Implementation of the Subject part of an InteractionObserver
 */
private:
	std::mutex interaction_observers_mutex;
	std::list<BaseStateQueryHandlerObserverInterface*> interaction_observers;
protected:
	void notify_all_interaction_observers();
public:
	void attach_interaction_observer(BaseStateQueryHandlerObserverInterface *observer);
	void detach_interaction_observer(BaseStateQueryHandlerObserverInterface *observer);

protected:
	// overload this method in derived classes!
	virtual void on_update_from(const BaseStateTask* subject) {
		// no-op
	}
	
public:
	BaseStateQueryHandlerCore(Smart::IQueryServerPattern<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState, SmartACE::QueryId>* server);
	virtual ~BaseStateQueryHandlerCore();
	//virtual void handleQuery(const SmartACE::QueryId &id, const CommBasicObjects::CommVoid& request);
};
#endif
