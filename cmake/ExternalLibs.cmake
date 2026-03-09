# External Libraries CMake Configuration

# Find Boost
set(BOOST_ROOT "${GCEXTLIB}/Boost/boost_1_67_0")
set(BOOST_INCLUDEDIR "${BOOST_ROOT}")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/stage/lib")

# Try to find Boost, but fall back to stubs if not found
find_package(Boost 1.67.0 QUIET COMPONENTS 
    system 
    filesystem 
    thread 
    date_time 
    regex 
    signals
)

if(NOT Boost_FOUND)
    message(STATUS "Boost not found, using stub headers")
    
    # Create stub Boost targets
    add_library(Boost::system INTERFACE IMPORTED)
    add_library(Boost::filesystem INTERFACE IMPORTED)
    add_library(Boost::thread INTERFACE IMPORTED)
    add_library(Boost::date_time INTERFACE IMPORTED)
    add_library(Boost::regex INTERFACE IMPORTED)
    add_library(Boost::signals INTERFACE IMPORTED)
    
    # Set include directories for stub headers
    set_target_properties(Boost::system PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${BOOST_ROOT}"
    )
    set_target_properties(Boost::filesystem PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${BOOST_ROOT}"
    )
    set_target_properties(Boost::thread PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${BOOST_ROOT}"
    )
    set_target_properties(Boost::date_time PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${BOOST_ROOT}"
    )
    set_target_properties(Boost::regex PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${BOOST_ROOT}"
    )
    set_target_properties(Boost::signals PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${BOOST_ROOT}"
    )
else()
    message(STATUS "Found Boost: ${Boost_VERSION}")
    add_library(Boost::Boost INTERFACE IMPORTED)
    set_target_properties(Boost::Boost PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${Boost_INCLUDE_DIRS}"
        INTERFACE_LINK_LIBRARIES "${Boost_LIBRARIES}"
    )
endif()

# Find APR
find_path(APR_INCLUDE_DIR apr.h
    PATHS "${GCEXTLIB}/apr-1.7.0/include"
    NO_DEFAULT_PATH
)

find_library(APR_LIBRARY
    NAMES apr-1 apr
    PATHS "${GCEXTLIB}/apr-1.7.0/LibR" "${GCEXTLIB}/apr-1.7.0/lib"
    NO_DEFAULT_PATH
)

if(APR_INCLUDE_DIR AND APR_LIBRARY)
    message(STATUS "Found APR: ${APR_LIBRARY}")
    add_library(APR::APR STATIC IMPORTED)
    set_target_properties(APR::APR PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${APR_INCLUDE_DIR}"
        IMPORTED_LOCATION "${APR_LIBRARY}"
    )
else()
    message(WARNING "APR not found")
endif()

# Find APR-Util
find_path(APRUTIL_INCLUDE_DIR apu.h
    PATHS "${GCEXTLIB}/apr-util-1.6.1/include"
    NO_DEFAULT_PATH
)

find_library(APRUTIL_LIBRARY
    NAMES aprutil-1 aprutil
    PATHS "${GCEXTLIB}/apr-util-1.6.1/LibR" "${GCEXTLIB}/apr-util-1.6.1/lib"
    NO_DEFAULT_PATH
)

if(APRUTIL_INCLUDE_DIR AND APRUTIL_LIBRARY)
    message(STATUS "Found APR-Util: ${APRUTIL_LIBRARY}")
    add_library(APR::APRUtil STATIC IMPORTED)
    set_target_properties(APR::APRUtil PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${APRUTIL_INCLUDE_DIR}"
        IMPORTED_LOCATION "${APRUTIL_LIBRARY}"
    )
else()
    message(WARNING "APR-Util not found")
endif()

# Find Log4cxx
find_path(LOG4CXX_INCLUDE_DIR log4cxx/logger.h
    PATHS "${GCEXTLIB}/apache-log4cxx-0.10.0/src/main/include"
    NO_DEFAULT_PATH
)

find_library(LOG4CXX_LIBRARY
    NAMES log4cxx
    PATHS "${GCEXTLIB}/apache-log4cxx-0.10.0/projects/Release"
    NO_DEFAULT_PATH
)

if(LOG4CXX_INCLUDE_DIR AND LOG4CXX_LIBRARY)
    message(STATUS "Found Log4cxx: ${LOG4CXX_LIBRARY}")
    add_library(Log4cxx::Log4cxx STATIC IMPORTED)
    set_target_properties(Log4cxx::Log4cxx PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${LOG4CXX_INCLUDE_DIR}"
        IMPORTED_LOCATION "${LOG4CXX_LIBRARY}"
    )
else()
    message(WARNING "Log4cxx not found")
endif()

# Create convenience target for all external libs
add_library(ExternalLibs INTERFACE IMPORTED)
target_include_directories(ExternalLibs INTERFACE
    ${COMMON_INCLUDES}
)

target_link_libraries(ExternalLibs INTERFACE
    ${COMMON_LIBS}
)

if(TARGET APR::APR)
    target_link_libraries(ExternalLibs INTERFACE APR::APR)
endif()

if(TARGET APR::APRUtil)
    target_link_libraries(ExternalLibs INTERFACE APR::APRUtil)
endif()

if(TARGET Log4cxx::Log4cxx)
    target_link_libraries(ExternalLibs INTERFACE Log4cxx::Log4cxx)
endif()

if(TARGET Boost::Boost)
    target_link_libraries(ExternalLibs INTERFACE Boost::Boost)
endif()
