CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "$ENV{SMART_PACKAGE_PATH}/ComponentRepository/.git")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
        RESULT_VARIABLE GIT_SUBMOD_RESULT)
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
        message(FATAL_ERROR "git submodule update --init failed, please checkout submodules manually")
    endif()
endif()

FIND_FILE(SMART_MACROS SmartMacros2.cmake PATHS $ENV{SMART_ROOT_ACE}/CMakeMacros /opt/smartSoftAce/CMakeMacros)
INCLUDE(${SMART_MACROS})

SMART_ADD_PACKAGE(SmartAmcl)
SMART_ADD_PACKAGE(SmartCdlServer)
SMART_ADD_PACKAGE(SmartGazeboBaseServer)
SMART_ADD_PACKAGE(SmartJoystickNavigation)
SMART_ADD_PACKAGE(SmartJoystickServer)
SMART_ADD_PACKAGE(SmartMapperGridMap)
SMART_ADD_PACKAGE(SmartPlannerBreadthFirstSearch)
SMART_ADD_PACKAGE(SmartRobotConsole)
SMART_ADD_PACKAGE(AROSYS-Components)
