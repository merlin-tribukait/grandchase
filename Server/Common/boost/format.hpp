#ifndef BOOST_FORMAT_HPP
#define BOOST_FORMAT_HPP

// Boost format stub
#include <string>
#include <sstream>

namespace boost {
    class format {
    public:
        format(const std::string& fmt) : fmt_str(fmt) {}
        
        template<typename T>
        format& operator%(const T& value) {
            std::ostringstream oss;
            oss << value;
            size_t pos = fmt_str.find("%");
            if (pos != std::string::npos) {
                fmt_str.replace(pos, 1, oss.str());
            }
            return *this;
        }
        
        std::string str() const { return fmt_str; }
        
    private:
        std::string fmt_str;
    };
}

#endif // BOOST_FORMAT_HPP
