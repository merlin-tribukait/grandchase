#ifndef _RTTI_H_
#define _RTTI_H_

#include <typeinfo>
#include <string>

// Simple RTTI stub
class RTTI
{
public:
    template<typename T>
    static const char* GetClassName(T* obj)
    {
        return typeid(*obj).name();
    }
    
    template<typename T>
    static const char* GetClassName()
    {
        return typeid(T).name();
    }
};

#endif // _RTTI_H_
