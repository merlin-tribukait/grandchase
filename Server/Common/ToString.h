#ifndef _TOSTRING_H_
#define _TOSTRING_H_

#include <string>
#include <sstream>

// Simple toString utility
template<typename T>
std::string ToString(const T& value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

// Function overloads for common types (instead of template specialization)
inline std::string ToString(const std::string& value)
{
    return value;
}

inline std::string ToString(const char* value)
{
    return std::string(value);
}

#endif // _TOSTRING_H_
