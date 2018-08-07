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
#include "GMappingTaskCore.hh"
#include "GMappingTask.hh"
#include "SmartGMapping.hh"

//FIXME: use logging
//#include "smartGlobalLogger.hh"

// include observers

void GMappingTaskCore::notify_all_interaction_observers() {
	std::unique_lock<std::mutex> lock(interaction_observers_mutex);
	// try dynamically down-casting this class to the derived class 
	// (we can do it safely here as we exactly know the derived class)
	if(const GMappingTask* gMappingTask = dynamic_cast<const GMappingTask*>(this)) {
		for(auto it=interaction_observers.begin(); it!=interaction_observers.end(); it++) {
			(*it)->on_update_from(gMappingTask);
		}
	}
}

void GMappingTaskCore::attach_interaction_observer(GMappingTaskObserverInterface *observer) {
	std::unique_lock<std::mutex> lock(interaction_observers_mutex);
	interaction_observers.push_back(observer);
}

void GMappingTaskCore::detach_interaction_observer(GMappingTaskObserverInterface *observer) {
	std::unique_lock<std::mutex> lock(interaction_observers_mutex);
	interaction_observers.remove(observer);
}

int GMappingTaskCore::execute_protected_region()
{
	if(useDefaultState) {
		Smart::StatusCode status = COMP->stateSlave->acquire("active");
		if(status != Smart::SMART_OK) {
			std::cerr << "GMappingTaskCore: ERROR acquiring state active: " << status << std::endl;
			return 0;
		}
	}
	
	// update of comm-objects must be within the protected region to prevent aged comm-object values
	this->updateAllCommObjects();
	
	if(useLogging == true) {
		//FIXME: use logging
		//Smart::LOGGER->log(taskLoggingId, getCurrentUpdateCount(), getPreviousCommObjId());
	}
	
	// this is the user code (should not internally use the state-pattern any more)
	int retval = this->on_execute();
	
	// notify all attached interaction observers
	this->notify_all_interaction_observers();
	
	// inform all associated tasks about a new update
	this->trigger_all_tasks();
	
	// increment current currentUpdateCount for the next iteration
	currentUpdateCount++;
	
	if(useDefaultState) {
		COMP->stateSlave->release("active");
	}
	return retval;
}


void GMappingTaskCore::updateAllCommObjects()
{
	laserServiceInStatus = COMP->laserServiceInInputTaskTrigger->getUpdate(laserServiceInObject);
}


// this method is meant to be used in derived classes
Smart::StatusCode GMappingTaskCore::currGridMapPushServiceOutPut(CommNavigationObjects::CommGridMap &currGridMapPushServiceOutDataObject)
{
	Smart::StatusCode result = COMP->currGridMapPushServiceOut->put(currGridMapPushServiceOutDataObject);
	if(useLogging == true) {
		//FIXME: use logging
		//Smart::LOGGER->log(pushLoggingId+1, getCurrentUpdateCount(), getPreviousCommObjId());
	}
	return result;
}
// this method is meant to be used in derived classes
Smart::StatusCode GMappingTaskCore::localizationUpdateServiceOutPut(CommBasicObjects::CommBasePositionUpdate &localizationUpdateServiceOutDataObject)
{
	Smart::StatusCode result = COMP->localizationUpdateServiceOut->send(localizationUpdateServiceOutDataObject);
	if(useLogging == true) {
		//FIXME: use logging
		//Smart::LOGGER->log(pushLoggingId+1, getCurrentUpdateCount(), getPreviousCommObjId());
	}
	return result;
}

void GMappingTaskCore::triggerLogEntry(const int& idOffset)
{
	if(useLogging == true) {
		int logId = taskLoggingId + 2*2 + idOffset;
		//FIXME: use logging
		//Smart::LOGGER->log(logId, getCurrentUpdateCount(), getPreviousCommObjId());
	}
}

int GMappingTaskCore::getPreviousCommObjId()
{
	// this method needs to be overloaded and implemented in derived classes
	return 0;
}
