CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

FIND_PACKAGE(Open62541Cpp QUIET)
FIND_PACKAGE(SeRoNetSDK QUIET)

IF(SeRoNetSDK_FOUND)
	SET(CMAKE_CXX_STANDARD 14)
	INCLUDE_DIRECTORIES(${CMAKE_CURRENT_LIST_DIR})
	SET(SERONET_SDK_SRCS "${CMAKE_CURRENT_LIST_DIR}/SmartJoystickServerSeRoNetSDKPortFactory.cc")
ENDIF(SeRoNetSDK_FOUND)
