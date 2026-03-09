#pragma once

#include <log4cxx/helpers/exception.h>
#include <log4cxx/logger.h>

namespace log4cxx
{
    class PropertyConfigurator
    {
    public:
        static void configure(const std::string& configFilename);
        static void configure(const std::wstring& configFilename);
    };
}
