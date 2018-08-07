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
#ifndef _LTMQUERYSERVERHANDLER_CORE_HH
#define _LTMQUERYSERVERHANDLER_CORE_HH
		
#include "aceSmartSoft.hh"

#include <CommNavigationObjects/CommGridMap.hh>
#include <CommNavigationObjects/CommGridMapRequest.hh>

// include the input interfaces (if any)

// include all interaction-observer interfaces
#include <LtmQueryServerHandlerObserverInterface.hh>
#include <LtmMapTaskObserverInterface.hh>

class LtmQueryServerHandlerCore 
:	public Smart::IQueryServerHandler<CommNavigationObjects::CommGridMapRequest, CommNavigationObjects::CommGridMap, SmartACE::QueryId>
,	public Smart::TaskTriggerSubject
,	public LtmMapTaskObserverInterface
{
private:

	virtual void updateAllCommObjects();

/**
 * Implementation of the Subject part of an InteractionObserver
 */
private:
	std::mutex interaction_observers_mutex;
	std::list<LtmQueryServerHandlerObserverInterface*> interaction_observers;
protected:
	void notify_all_interaction_observers();
public:
	void attach_interaction_observer(LtmQueryServerHandlerObserverInterface *observer);
	void detach_interaction_observer(LtmQueryServerHandlerObserverInterface *observer);

protected:
	// overload this method in derived classes!
	virtual void on_update_from(const LtmMapTask* subject) {
		// no-op
	}
	
public:
	LtmQueryServerHandlerCore(Smart::IQueryServerPattern<CommNavigationObjects::CommGridMapRequest, CommNavigationObjects::CommGridMap, SmartACE::QueryId>* server);
	virtual ~LtmQueryServerHandlerCore();
	//virtual void handleQuery(const SmartACE::QueryId &id, const CommNavigationObjects::CommGridMapRequest& request);
};
#endif
