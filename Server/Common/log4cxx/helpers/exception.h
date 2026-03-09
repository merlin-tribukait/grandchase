#pragma once

#include <exception>
#include <string>

namespace log4cxx
{
    namespace helpers
    {
        class Exception : public std::exception
        {
        public:
            Exception(const std::string& msg) : message_(msg) {}
            virtual const char* what() const noexcept { return message_.c_str(); }
        private:
            std::string message_;
        };
    }
}
