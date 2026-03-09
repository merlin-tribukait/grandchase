# AgentServer CMakeLists.txt

set(AGENTSERVER_SOURCES
    stdafx.cpp
    stdafx.h
    AgentServer.cpp
    AgentServer.h
    WAgentServer.cpp
    WAgentServer.h
    WAgentServerDlg.cpp
    WAgentServerDlg.h
    AGConnector.cpp
    AGConnector.h
    AGDBLayer.cpp
    AGDBLayer.h
    AGDBThread.cpp
    AGDBThread.h
    AGDBThreadHelper.cpp
    AGDBThreadHelper.h
    Agent.cpp
    Agent.h
    Agit.cpp
    Agit.h
    AgitManager.cpp
    AgitManager.h
    AGNetLayer.cpp
    AGNetLayer.h
    AGProxy.cpp
    AGProxy.h
    AGSimLayer.cpp
    AGSimLayer.h
    AGSlave.cpp
    AGSlave.h
    SwitchUserSID.cpp
    SwitchUserSID.h
)

# Collect all source files
file(GLOB_RECURSE AGENTSERVER_ALL_SOURCES 
    "*.cpp"
    "*.h"
)

add_executable(AgentServer WIN32 ${AGENTSERVER_ALL_SOURCES})

target_include_directories(AgentServer PRIVATE
    ${COMMON_INCLUDES}
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(AgentServer PRIVATE
    ServerCommon
    ${COMMON_LIBS}
)

target_compile_definitions(AgentServer PRIVATE
    WIN32
    _WINDOWS
    UNICODE
    _UNICODE
)

if(PLATFORM_X64)
    target_compile_definitions(AgentServer PRIVATE WIN64)
else()
    target_compile_definitions(AgentServer PRIVATE _USE_32BIT_TIME_T)
endif()

if(MSVC)
    target_compile_options(AgentServer PRIVATE /Yu"stdafx.h")
    set_source_files_properties(
        stdafx.cpp PROPERTIES
        COMPILE_FLAGS "/Yc'stdafx.h'"
    )
endif()
