# NewPatcher CMakeLists.txt

set(NEWPATCHER_SOURCES
    stdafx.cpp
    stdafx.h
    NewPatcher.cpp
    NewPatcher.h
    NewPatcherDlg.cpp
    NewPatcherDlg.h
    globalfunction.cpp
    globalfunction.h
)

# Collect all source files
file(GLOB_RECURSE NEWPATCHER_ALL_SOURCES 
    "*.cpp"
    "*.h"
)

add_library(NewPatcher STATIC ${NEWPATCHER_ALL_SOURCES})

target_include_directories(NewPatcher PRIVATE
    ${COMMON_INCLUDES}
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_compile_definitions(NewPatcher PRIVATE
    WIN32
    _WINDOWS
    _USE_32BIT_TIME_T
    UNICODE
    _UNICODE
)

if(MSVC)
    target_compile_options(NewPatcher PRIVATE /Yu"stdafx.h")
    set_source_files_properties(
        stdafx.cpp PROPERTIES
        COMPILE_FLAGS "/Yc'stdafx.h'"
    )
endif()
