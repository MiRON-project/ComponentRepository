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
#ifndef _CURMAPCLIENT_UPCALL_MANAGER_HH
#define _CURMAPCLIENT_UPCALL_MANAGER_HH

#include <list>
#include "aceSmartSoft.hh"
#include "CurMapClientUpcallInterface.hh"

/** CurMapClientUpcallManager connects input-handling with Upcall propagation
 *
 * This class implements an InputHandler for the InputPort CurMapClient and propagates the handling 
 * of incoming data to all associated (i.e. attached) Upcalls.
 */
class CurMapClientUpcallManager
:	public Smart::IInputHandler<CommNavigationObjects::CommGridMap>
{
private:
	// list of associated updalls
	std::list<CurMapClientUpcallInterface*> upcalls;

	// call the on_CurMapClient of all the attached CurMapClientUpcallInterfaces
	void notify_upcalls(const CommNavigationObjects::CommGridMap &input);
	
protected:
	virtual void handle_input(const CommNavigationObjects::CommGridMap &input) {
		// relay input-handling to all attached CurMapClientUpcallInterfaces
		this->notify_upcalls(input);
	}
public:
	CurMapClientUpcallManager(
		Smart::InputSubject<CommNavigationObjects::CommGridMap> *subject,
		const int &prescaleFactor=1
	);
	virtual ~CurMapClientUpcallManager();
	
	void attach(CurMapClientUpcallInterface *upcall);
	void detach(CurMapClientUpcallInterface *upcall);
};

#endif
