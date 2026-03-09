# Client CMakeLists.txt

# Client projects
add_subdirectory(NewPatcher)

# Main GameClient executable
set(GAMECLIENT_SOURCES
    stdafx.cpp
    stdafx.h
    united.cpp
    united2.cpp
    united3.cpp
    united4.cpp
    united5.cpp
    united_square.cpp
    united_ui.cpp
    united_uifx.cpp
)

# Collect all source files from Client directory
file(GLOB_RECURSE GAMECLIENT_ALL_SOURCES 
    "*.cpp"
    "*.h"
)

# Create GameClient executable with unique name
add_executable(GameClientApp WIN32 ${GAMECLIENT_ALL_SOURCES})

# Set target properties
set_target_properties(GameClientApp PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    WIN32_EXECUTABLE TRUE
)

# Include directories
target_include_directories(GameClientApp PRIVATE
    ${COMMON_INCLUDES}
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${GCEXTLIB}/DXSDK/Include"
    "${GCEXTLIB}/VMProtect/Include"
)

# Link libraries
target_link_libraries(GameClientApp PRIVATE
    ${COMMON_LIBS}
    "${GCEXTLIB}/VMProtect/Lib/VMProtectSDK32.lib"
)

# Platform-specific configurations
if(PLATFORM_X64)
    target_compile_definitions(GameClientApp PRIVATE
        WIN64
        _WINDOWS
        UNICODE
        _UNICODE
    )
else()
    target_compile_definitions(GameClientApp PRIVATE
        WIN32
        _WINDOWS
        _USE_32BIT_TIME_T
        UNICODE
        _UNICODE
    )
endif()

# Configuration-specific settings
target_compile_definitions(GameClientApp PRIVATE
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<CONFIG:Release>:NDEBUG>
    $<$<CONFIG:Release>:_SECURE_SCL=0>
)

# Precompiled header
if(MSVC)
    target_compile_options(GameClientApp PRIVATE /Yu"stdafx.h")
    set_source_files_properties(
        stdafx.cpp PROPERTIES
        COMPILE_FLAGS "/Yc'stdafx.h'"
    )
endif()

# Copy DLLs to output directory
add_custom_command(TARGET GameClientApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${GCEXTLIB}/apache-log4cxx-0.10.0/projects/Release/log4cxx.dll"
    $<TARGET_FILE_DIR:GameClientApp>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${GCEXTLIB}/apr-1.7.0/LibR/apr-1.dll"
    $<TARGET_FILE_DIR:GameClientApp>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${GCEXTLIB}/apr-util-1.6.1/LibR/aprutil-1.dll"
    $<TARGET_FILE_DIR:GameClientApp>
    COMMENT "Copying required DLLs to output directory"
)
