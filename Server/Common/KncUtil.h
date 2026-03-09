#ifndef _KNCUTIL_H_
#define _KNCUTIL_H_

#include <string>
#include <vector>

// Forward declare lua_State to avoid including lua.h
struct lua_State;

// Global lua state stub
extern lua_State* g_pLua;

// Stub lua functions
inline int lua_dostring(lua_State* L, const char* str)
{
    return 0;
}

namespace KncUtil
{
    // Convert wide string to narrow string
    std::string toNarrowString(const wchar_t* wideStr, int bufferSize = -1)
    {
        if (wideStr == nullptr)
            return std::string();
            
        if (bufferSize == -1)
            bufferSize = static_cast<int>(wcslen(wideStr) + 1);
            
        std::string result;
        result.reserve(bufferSize);
        
        for (int i = 0; i < bufferSize && wideStr[i] != L'\0'; ++i)
        {
            if (wideStr[i] < 256)
                result.push_back(static_cast<char>(wideStr[i]));
            else
                result.push_back('?'); // Replace non-ASCII characters
        }
        
        return result;
    }
    
    // Convert wide string to narrow string (overload for std::wstring)
    std::string toNarrowString(const std::wstring& wideStr)
    {
        return toNarrowString(wideStr.c_str(), static_cast<int>(wideStr.length() + 1));
    }
    
    // Convert narrow string to wide string
    std::wstring toWideString(const char* narrowStr, int bufferSize = -1)
    {
        if (narrowStr == nullptr)
            return std::wstring();
            
        if (bufferSize == -1)
            bufferSize = static_cast<int>(strlen(narrowStr) + 1);
            
        std::wstring result;
        result.reserve(bufferSize);
        
        for (int i = 0; i < bufferSize && narrowStr[i] != '\0'; ++i)
        {
            result.push_back(static_cast<wchar_t>(narrowStr[i]));
        }
        
        return result;
    }
    
    // Convert narrow string to wide string (overload for std::string)
    std::wstring toWideString(const std::string& narrowStr)
    {
        return toWideString(narrowStr.c_str(), static_cast<int>(narrowStr.length() + 1));
    }
}

#endif // _KNCUTIL_H_
