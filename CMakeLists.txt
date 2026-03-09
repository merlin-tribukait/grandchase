cmake_minimum_required(VERSION 3.20)
project(GrandChase VERSION 1.0.0 LANGUAGES CXX)

# Force latest Visual Studio compiler and Windows SDK
if(MSVC)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    add_compile_options(/std:c++20)
    add_compile_options(/permissive-)
    add_compile_options(/Zc:__cplusplus)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    
    # Force Windows 10 SDK and latest toolset
    set(CMAKE_SYSTEM_VERSION "10.0")
    set(CMAKE_VS_WINDOWS_TARGET_PLATFORM_VERSION "10.0")
    set(CMAKE_GENERATOR_TOOLSET "v143")  # Use VS 2022 toolset
endif()

# Include CMake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Platform detection
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(PLATFORM_X64 TRUE)
    add_compile_definitions(WIN64)
else()
    set(PLATFORM_X86 TRUE)
    add_compile_definitions(WIN32)
endif()

# External libraries paths
set(GCEXTLIB "${CMAKE_CURRENT_SOURCE_DIR}/Libs/ExternalLib")
set(KNCSDKPATH "${CMAKE_CURRENT_SOURCE_DIR}/Libs/InternalLib/KNCSDK_2015")

# Common include directories
set(COMMON_INCLUDES
    "${CMAKE_CURRENT_SOURCE_DIR}/Server/Common"
    "${CMAKE_CURRENT_SOURCE_DIR}/CommonFiles"
    "${KNCSDKPATH}/include"
    "${GCEXTLIB}/Boost/boost_1_67_0"
    "${GCEXTLIB}/apache-log4cxx-0.10.0/src/main/include"
    "${GCEXTLIB}/apr-1.7.0/include"
    "${GCEXTLIB}/apr-util-1.6.1/include"
    "${GCEXTLIB}/IntelTBB/tbb2019_20190410oss/include"
    "${GCEXTLIB}/Serializer"
    "${GCEXTLIB}/Thread"
)

# Common library directories
set(COMMON_LIB_DIRS
    "${KNCSDKPATH}/lib"
    "${GCEXTLIB}/Boost/boost_1_67_0/stage/lib"
    "${GCEXTLIB}/Boost/boost_1_67_0/lib"
    "${GCEXTLIB}/apache-log4cxx-0.10.0/projects/Release"
    "${GCEXTLIB}/apr-1.7.0/LibR"
    "${GCEXTLIB}/apr-util-1.6.1/LibR"
    "${GCEXTLIB}/IntelTBB/tbb2019_20190410oss/lib/ia32/vc14"
)

# Common libraries
set(COMMON_LIBS
    kernel32
    user32
    gdi32
    winspool
    comdlg32
    advapi32
    shell32
    ole32
    oleaut32
    uuid
    odbc32
    odbccp32
    Normaliz
    Crypt32
    Wldap32
    aprutil-1
    apr-1
    log4cxx
)

# Platform-specific libraries
if(PLATFORM_X64)
    list(APPEND COMMON_LIB_DIRS
        "${GCEXTLIB}/IntelTBB/tbb2019_20190410oss/lib/intel64/vc14"
    )
else()
    list(APPEND COMMON_LIB_DIRS
        "${GCEXTLIB}/IntelTBB/tbb2019_20190410oss/lib/ia32/vc14"
    )
endif()

# Compiler-specific options
if(MSVC)
    add_compile_options(
        /W3
        /MP
        /utf-8
        /D_CRT_SECURE_NO_WARNINGS
        /D_SCL_SECURE_NO_WARNINGS
        /DBOOST_SIGNALS_NO_DEPRECATION_WARNING
        /D_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
        /D_VC80_UPGRADE=0x0710
    )
    
    # Disable specific warnings
    add_compile_options(/wd4819)  # character cannot be represented in current code page
    add_compile_options(/wd4996)  # deprecated function warnings
endif()

# Configure external libraries
include(ExternalLibs)

# Configure stub headers for missing dependencies
include(StubHeaders)

# Add subdirectories
add_subdirectory(Server)
add_subdirectory(Client)

# Custom targets for external libraries if needed
add_custom_target(external_libs ALL
    COMMAND ${CMAKE_COMMAND} -E echo "External libraries configured"
    COMMENT "Configuring external libraries"
)
