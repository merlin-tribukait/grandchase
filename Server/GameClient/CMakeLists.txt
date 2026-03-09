# GameClient Server CMakeLists.txt

set(GAMECLIENT_SERVER_SOURCES
    stdafx.cpp
    stdafx.h
    GameClient.cpp
    GameClient.h
    GameClientDlg.cpp
    GameClientDlg.h
)

# Collect all source files
file(GLOB_RECURSE GAMECLIENT_SERVER_ALL_SOURCES 
    "*.cpp"
    "*.h"
)

add_executable(GameClientServer WIN32 ${GAMECLIENT_SERVER_ALL_SOURCES})

target_include_directories(GameClientServer PRIVATE
    ${COMMON_INCLUDES}
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(GameClientServer PRIVATE
    ServerCommon
    ${COMMON_LIBS}
)

target_compile_definitions(GameClientServer PRIVATE
    WIN32
    _WINDOWS
    UNICODE
    _UNICODE
)

if(PLATFORM_X64)
    target_compile_definitions(GameClientServer PRIVATE WIN64)
else()
    target_compile_definitions(GameClientServer PRIVATE _USE_32BIT_TIME_T)
endif()

if(MSVC)
    target_compile_options(GameClientServer PRIVATE /Yu"stdafx.h")
    set_source_files_properties(
        stdafx.cpp PROPERTIES
        COMPILE_FLAGS "/Yc'stdafx.h'"
    )
endif()
