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
#ifndef _SPEECHSENDHANDLER_CORE_HH
#define _SPEECHSENDHANDLER_CORE_HH

#include <aceSmartSoft.hh>

// include the main input-handler interface
#include "SpeechSendServiceInUpcallInterface.hh"
// include all other input interfaces (if any)

// include all interaction-observer interfaces
#include <SpeechSendHandlerObserverInterface.hh>

class SpeechSendHandlerCore
:	public Smart::InputTaskTrigger<DomainSpeech::CommSpeechOutputMessage>
,	public SpeechSendServiceInUpcallInterface
{
private:
	Smart::StatusCode updateStatus;
	DomainSpeech::CommSpeechOutputMessage lastUpdate;
	
	
	virtual void updateAllCommObjects();
	
	// internal input handling method
	virtual void handle_input(const DomainSpeech::CommSpeechOutputMessage& input) {
		this->updateAllCommObjects();
		// call the input handler method (which has to be implemented in derived classes)
		this->on_SpeechSendServiceIn(input);
		// notify all attached interaction observers
		this->notify_all_interaction_observers();
		// call implementation of base class
		Smart::InputTaskTrigger<DomainSpeech::CommSpeechOutputMessage>::handle_input(input);
	}
	
/**
 * Implementation of the Subject part of an InteractionObserver
 */
private:
	std::mutex interaction_observers_mutex;
	std::list<SpeechSendHandlerObserverInterface*> interaction_observers;
protected:
	void notify_all_interaction_observers();
public:
	void attach_interaction_observer(SpeechSendHandlerObserverInterface *observer);
	void detach_interaction_observer(SpeechSendHandlerObserverInterface *observer);
	
protected:

public:
	SpeechSendHandlerCore(
		Smart::InputSubject<DomainSpeech::CommSpeechOutputMessage> *subject,
		const int &prescaleFactor=1);
	virtual ~SpeechSendHandlerCore();
};
#endif
