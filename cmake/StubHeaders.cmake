# CMake configuration for missing dependencies

# Create stub headers for missing dependencies that were previously handled manually

# NetError_def.h stub
add_library(NetErrorStub INTERFACE)
target_include_directories(NetErrorStub INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/Server/Common")

# dbg.hpp stub
add_library(DebugStub INTERFACE)
target_include_directories(DebugStub INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/Server/Common")

# ImportKncSecurity.h stub
add_library(KncSecurityStub INTERFACE)
target_include_directories(KncSecurityStub INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/Server/Common")

# ImportKncDebug.h stub
add_library(KncDebugStub INTERFACE)
target_include_directories(KncDebugStub INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/Server/Common")

# Boost stubs
add_library(BoostStub INTERFACE)
target_include_directories(BoostStub INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/Server/Common/boost")

# Serializer stubs
add_library(SerializerStub INTERFACE)
target_include_directories(SerializerStub INTERFACE "${GCEXTLIB}/Serializer")

# Thread stubs
add_library(ThreadStub INTERFACE)
target_include_directories(ThreadStub INTERFACE "${GCEXTLIB}/Thread")

# EventDefines.h stub
add_library(EventDefinesStub INTERFACE)
target_include_directories(EventDefinesStub INTERFACE "${GCEXTLIB}")

# Create a unified stub library target
add_library(AllStubs INTERFACE)
target_link_libraries(AllStubs INTERFACE
    NetErrorStub
    DebugStub
    KncSecurityStub
    KncDebugStub
    BoostStub
    SerializerStub
    ThreadStub
    EventDefinesStub
)

# Add stub headers to all targets
function(add_stubs_to_target TARGET_NAME)
    target_link_libraries(${TARGET_NAME} PRIVATE AllStubs)
endfunction()

# Macro to create stub header if it doesn't exist
macro(create_stub_header PATH CONTENT)
    if(NOT EXISTS "${PATH}")
        get_filename_component(DIR "${PATH}" DIRECTORY)
        file(MAKE_DIRECTORY "${DIR}")
        file(WRITE "${PATH}" "${CONTENT}")
        message(STATUS "Created stub header: ${PATH}")
    endif()
endmacro()

# Create essential stub headers
create_stub_header("${CMAKE_CURRENT_SOURCE_DIR}/Server/Common/NetError_def.h" 
"#ifndef NETERROR_DEF_H
#define NETERROR_DEF_H

// Stub NetError definitions
#define NET_OK 0
#define ERR_UNKNOWN -1

#endif // NETERROR_DEF_H
")

create_stub_header("${CMAKE_CURRENT_SOURCE_DIR}/Server/Common/dbg.hpp"
"#ifndef DBG_HPP
#define DBG_HPP

// Stub debug macros
#define START_LOG(stream, msg) stream << msg
#define END_LOG
#define BUILD_LOG(val) << val
#define BUILD_LOGtm(val) << val
#define BUILD_LOGc(val) << val
#define BUILD_LOGb(val) << val

#endif // DBG_HPP
")

create_stub_header("${CMAKE_CURRENT_SOURCE_DIR}/Server/Common/ImportKncSecurity.h"
"#ifndef IMPORT_KNC_SECURITY_H
#define IMPORT_KNC_SECURITY_H

// Stub security functions
inline bool KncSecurityCheck() { return true; }
inline void KncSecurityInit() {}

#endif // IMPORT_KNC_SECURITY_H
")

create_stub_header("${CMAKE_CURRENT_SOURCE_DIR}/Server/Common/ImportKncDebug.h"
"#ifndef IMPORT_KNC_DEBUG_H
#define IMPORT_KNC_DEBUG_H

// Stub debug functions
inline void KncDebugLog(const char* msg) {}
inline void KncDebugInit() {}

#endif // IMPORT_KNC_DEBUG_H
")
