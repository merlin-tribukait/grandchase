#ifndef _KNCUTIL_H_
#define _KNCUTIL_H_

#include <string>
#include <vector>

namespace KncUtil
{
    // Convert wide string to narrow string
    std::string toNarrowString(const wchar_t* wideStr, int bufferSize = -1);
    
    // Convert wide string to narrow string (overload for std::wstring)
    std::string toNarrowString(const std::wstring& wideStr);
    
    // Convert narrow string to wide string
    std::wstring toWideString(const char* narrowStr, int bufferSize = -1);
    
    // Convert narrow string to wide string (overload for std::string)
    std::wstring toWideString(const std::string& narrowStr);
}

#endif // _KNCUTIL_H_
