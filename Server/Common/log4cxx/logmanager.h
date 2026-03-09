#pragma once

#include <log4cxx/logger.h>
#include <string>

namespace log4cxx
{
    class LogManager
    {
    public:
        static LoggerPtr getLogger(const std::string& name);
        static LoggerPtr getLogger(const std::wstring& name);
        static void shutdown();
    };
}
