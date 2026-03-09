# Server CMakeLists.txt

# Common server library
add_library(ServerCommon STATIC)

# Collect all Common source files
file(GLOB_RECURSE SERVER_COMMON_SOURCES 
    "Common/*.cpp"
    "Common/*.h"
    "Common/*/*.cpp"
    "Common/*/*.h"
)

# Exclude specific files that shouldn't be in the common library
list(FILTER SERVER_COMMON_SOURCES EXCLUDE REGEX ".*AgentServer.*")
list(FILTER SERVER_COMMON_SOURCES EXCLUDE REGEX ".*GameServer.*")
list(FILTER SERVER_COMMON_SOURCES EXCLUDE REGEX ".*WGameServer.*")

target_sources(ServerCommon PRIVATE ${SERVER_COMMON_SOURCES})

target_include_directories(ServerCommon PRIVATE
    ${COMMON_INCLUDES}
    "${CMAKE_CURRENT_SOURCE_DIR}/Common"
)

target_compile_definitions(ServerCommon PRIVATE
    WIN32
    _WINDOWS
    UNICODE
    _UNICODE
    BOOST_LIB_DIAGNOSTIC
)

# Platform-specific definitions for Common
if(PLATFORM_X64)
    target_compile_definitions(ServerCommon PRIVATE WIN64)
else()
    target_compile_definitions(ServerCommon PRIVATE _USE_32BIT_TIME_T)
endif()

# Add individual server projects
add_subdirectory(GameClient)
add_subdirectory(AgentServer)
add_subdirectory(GameServer)
add_subdirectory(WGameServer)
add_subdirectory(WCenterServer)

# Check for optional server directories and add them if they exist
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/WUDPRelay/CMakeLists.txt")
    add_subdirectory(WUDPRelay)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/GCServerManager_Battle/CMakeLists.txt")
    add_subdirectory(GCServerManager_Battle)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/MatchServer/CMakeLists.txt")
    add_subdirectory(MatchServer)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/WTCPRelay/CMakeLists.txt")
    add_subdirectory(WTCPRelay)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/WMsgServer/CMakeLists.txt")
    add_subdirectory(WMsgServer)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/UnitTest/CMakeLists.txt")
    add_subdirectory(UnitTest)
endif()
