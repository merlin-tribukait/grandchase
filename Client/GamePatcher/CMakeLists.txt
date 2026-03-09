# GamePatcher CMakeLists.txt

set(GAMEPATCHER_SOURCES
    stdafx.cpp
    stdafx.h
    GamePatcher.cpp
    GamePatcher.h
    GamePatcherDlg.cpp
    GamePatcherDlg.h
)

# Collect all source files
file(GLOB_RECURSE GAMEPATCHER_ALL_SOURCES 
    "*.cpp"
    "*.h"
)

add_library(GamePatcher STATIC ${GAMEPATCHER_ALL_SOURCES})

target_include_directories(GamePatcher PRIVATE
    ${COMMON_INCLUDES}
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_compile_definitions(GamePatcher PRIVATE
    WIN32
    _WINDOWS
    _USE_32BIT_TIME_T
    UNICODE
    _UNICODE
)

if(MSVC)
    target_compile_options(GamePatcher PRIVATE /Yu"stdafx.h")
    set_source_files_properties(
        stdafx.cpp PROPERTIES
        COMPILE_FLAGS "/Yc'stdafx.h'"
    )
endif()
