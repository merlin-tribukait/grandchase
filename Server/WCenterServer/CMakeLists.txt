# WCenterServer CMakeLists.txt

set(WCENTERSERVER_SOURCES
    stdafx.cpp
    stdafx.h
    WCenterServer.cpp
    WCenterServer.h
    WCenterServerDlg.cpp
    WCenterServerDlg.h
)

# Collect all source files
file(GLOB_RECURSE WCENTERSERVER_ALL_SOURCES 
    "*.cpp"
    "*.h"
)

add_executable(WCenterServer WIN32 ${WCENTERSERVER_ALL_SOURCES})

target_include_directories(WCenterServer PRIVATE
    ${COMMON_INCLUDES}
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(WCenterServer PRIVATE
    ServerCommon
    ${COMMON_LIBS}
)

target_compile_definitions(WCenterServer PRIVATE
    WIN32
    _WINDOWS
    UNICODE
    _UNICODE
)

if(PLATFORM_X64)
    target_compile_definitions(WCenterServer PRIVATE WIN64)
else()
    target_compile_definitions(WCenterServer PRIVATE _USE_32BIT_TIME_T)
endif()

if(MSVC)
    target_compile_options(WCenterServer PRIVATE /Yu"stdafx.h")
    set_source_files_properties(
        stdafx.cpp PROPERTIES
        COMPILE_FLAGS "/Yc'stdafx.h'"
    )
endif()
