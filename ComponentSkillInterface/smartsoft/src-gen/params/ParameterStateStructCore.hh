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
#ifndef _PARAMETERSTATESTRUCTCORE_HH
#define _PARAMETERSTATESTRUCTCORE_HH

#include "aceSmartSoft.hh"

#include <iostream>

// forward declaration (in order to define validateCOMMIT(ParameterStateStruct) which is implemented in derived class)
class ParameterStateStruct;

class ParameterStateStructCore
{
	friend class ParamUpdateHandler;
public:
	
		///////////////////////////////////////////
		// Internal params
		///////////////////////////////////////////
		
		/**
		 * Definition of Parameter Settings
		 */
		class SettingsType 
		{
			friend class ParamUpdateHandler;
			public:
			/**
			 * Wrapper class for Enum communicationType
			 */
			class communicationTypeType {
			public:
				enum ENUM_communicationType {
					ENUM_VALUE_UNDEFINED = 0,
					socket = 1,
					ZeroMQ = 2
				};
				
				// default constructor
				communicationTypeType() { 
					value = ENUM_VALUE_UNDEFINED;
				}
				
				// copy constructor for enum type
				communicationTypeType(ENUM_communicationType e) {
					value = e;
				}
				
				// copy constructor for String type
				communicationTypeType(const std::string &literal) {
					from_string(literal);
				}
				
				// from_string assignment operator
				communicationTypeType& operator = (const std::string &literal) {
					from_string(literal);
					return *this;
				}
				
				// ENUM operator
				operator ENUM_communicationType() const {
					return value;
				}
				
				// String operator
				operator std::string() const {
					return to_string();
				}
				
				// compare operator
				bool operator == (const ENUM_communicationType t) const {
					return this->value == t;
				}
				
				std::string to_string() const {
					std::string result = "";
					switch (value) {
						case ZeroMQ:
							result = "ZeroMQ";
							break;
						case socket:
							result = "socket";
							break;
						default:
							result = "ENUM_VALUE_UNDEFINED";
							break;
					};
					return result;
				}
				
				void from_string(const std::string &literal) {
					if(literal == "socket") {
						value = socket;
					} else if(literal == "ZeroMQ") {
						value = ZeroMQ;
					} else {
						value = ENUM_VALUE_UNDEFINED;
					}
				}
				
				// helper method to easily implement output stream
				void to_ostream(std::ostream &os = std::cout) const {
					os << to_string();
				}
			private:
				ENUM_communicationType value;
			};
			
		protected:
			/**
			 * here are the member definitions
			 */
			SettingsType::communicationTypeType communicationType;
			std::string ip;
			unsigned int port;
			unsigned int socket_timeout_s;
			bool use_socket_timeout;
			bool verbose;
		
		public:
			// default constructor
			SettingsType() {
				communicationType = SettingsType::communicationTypeType::ZeroMQ;
				ip = "127.0.0.1";
				port = 5557;
				socket_timeout_s = 5;
				use_socket_timeout = false;
				verbose = false;
			}
		
			/**
			 * here are the public getters
			 */
			inline SettingsType::communicationTypeType getCommunicationType() const { return communicationType; }
			inline std::string getIp() const { return ip; }
			inline unsigned int getPort() const { return port; }
			inline unsigned int getSocket_timeout_s() const { return socket_timeout_s; }
			inline bool getUse_socket_timeout() const { return use_socket_timeout; }
			inline bool getVerbose() const { return verbose; }
			
			void to_ostream(std::ostream &os = std::cout) const
			{
				os << "Settings(";
				os << "communicationType = " << communicationType << ", ";
				os << "ip = " << ip << ", ";
				os << "port = " << port << ", ";
				os << "socket_timeout_s = " << socket_timeout_s << ", ";
				os << "use_socket_timeout = " << use_socket_timeout << ", ";
				os << "verbose = " << verbose << ", ";
				os << ")\n";
			}
			
		}; // end class SettingsType
		
	
		///////////////////////////////////////////
		// External params
		///////////////////////////////////////////
		
	
		///////////////////////////////////////////
		// Instance params
		///////////////////////////////////////////
		
	
protected:

	// Internal params
	SettingsType Settings;
	
	// External params
	
	// Instance params (encapsulated in a wrapper class for each instantiated parameter repository)
	

	void setContent(const ParameterStateStructCore &commit) {
		// External params
	
	}

	// special trigger method (user upcall) called before updating parameter global state
	virtual SmartACE::ParamResponseType handleCOMMIT(const ParameterStateStruct &commitState) = 0;
public:
	ParameterStateStructCore() {  }
	virtual ~ParameterStateStructCore() {  }
	
	// internal param getters
	SettingsType getSettings() const {
		return Settings;
	}
	
	// external param getters
	
	// repo wrapper class getter(s)
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const
	{
		// Internal params
		Settings.to_ostream(os);
		
		// External params
		
		// Instance params (encapsulated in a wrapper class for each instantiated parameter repository)
	}
};

#endif
