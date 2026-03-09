# GameServer CMakeLists.txt (converted from .vcproj)

set(GAMESERVER_SOURCES
    stdafx.cpp
    stdafx.h
    GameServer.cpp
    GameServer.h
    WGameServer.cpp
    WGameServer.h
    WGameServerDlg.cpp
    WGameServerDlg.h
)

# Collect all source files
file(GLOB_RECURSE GAMESERVER_ALL_SOURCES 
    "*.cpp"
    "*.h"
)

add_executable(GameServer WIN32 ${GAMESERVER_ALL_SOURCES})

target_include_directories(GameServer PRIVATE
    ${COMMON_INCLUDES}
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(GameServer PRIVATE
    ServerCommon
    ${COMMON_LIBS}
)

target_compile_definitions(GameServer PRIVATE
    WIN32
    _WINDOWS
    UNICODE
    _UNICODE
)

if(PLATFORM_X64)
    target_compile_definitions(GameServer PRIVATE WIN64)
else()
    target_compile_definitions(GameServer PRIVATE _USE_32BIT_TIME_T)
endif()

if(MSVC)
    target_compile_options(GameServer PRIVATE /Yu"stdafx.h")
    set_source_files_properties(
        stdafx.cpp PROPERTIES
        COMPILE_FLAGS "/Yc'stdafx.h'"
    )
endif()
