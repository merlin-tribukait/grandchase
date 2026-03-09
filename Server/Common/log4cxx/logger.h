#ifndef _LOG4CXX_LOGGER_H_
#define _LOG4CXX_LOGGER_H_

#include <string>
#include <memory>

namespace log4cxx
{
    class Logger
    {
    public:
        static LoggerPtr getLogger(const std::string& name);
        static LoggerPtr getLogger(const std::wstring& name);
        
        void info(const std::string& msg) {}
        void debug(const std::string& msg) {}
        void warn(const std::string& msg) {}
        void error(const std::string& msg) {}
        void fatal(const std::string& msg) {}
        
        void info(const std::wstring& msg) {}
        void debug(const std::wstring& msg) {}
        void warn(const std::wstring& msg) {}
        void error(const std::wstring& msg) {}
        void fatal(const std::wstring& msg) {}
    };
    
    typedef std::shared_ptr<Logger> LoggerPtr;
}

#endif // _LOG4CXX_LOGGER_H_
