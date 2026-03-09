#ifndef TOSTRING_H
#define TOSTRING_H

#include <string>
#include <sstream>

// ToString utility stub
template<typename T>
std::wstring ToStringW(const T& value) {
    std::wostringstream oss;
    oss << value;
    return oss.str();
}

template<typename T>
std::string ToString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

#endif // TOSTRING_H
