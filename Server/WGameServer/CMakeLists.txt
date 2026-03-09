# WGameServer CMakeLists.txt

set(WGAMESERVER_SOURCES
    stdafx.cpp
    stdafx.h
    WGameServer.cpp
    WGameServer.h
    WGameServerDlg.cpp
    WGameServerDlg.h
)

# Collect all source files
file(GLOB_RECURSE WGAMESERVER_ALL_SOURCES 
    "*.cpp"
    "*.h"
)

add_executable(WGameServer WIN32 ${WGAMESERVER_ALL_SOURCES})

target_include_directories(WGameServer PRIVATE
    ${COMMON_INCLUDES}
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(WGameServer PRIVATE
    ServerCommon
    ${COMMON_LIBS}
)

target_compile_definitions(WGameServer PRIVATE
    WIN32
    _WINDOWS
    UNICODE
    _UNICODE
)

if(PLATFORM_X64)
    target_compile_definitions(WGameServer PRIVATE WIN64)
else()
    target_compile_definitions(WGameServer PRIVATE _USE_32BIT_TIME_T)
endif()

if(MSVC)
    target_compile_options(WGameServer PRIVATE /Yu"stdafx.h")
    set_source_files_properties(
        stdafx.cpp PROPERTIES
        COMPILE_FLAGS "/Yc'stdafx.h'"
    )
endif()
