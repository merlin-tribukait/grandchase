#ifndef _SERBUFFER_H_
#define _SERBUFFER_H_

#include <vector>
#include <string>

// Simple serialization buffer stub
class SerBuffer
{
public:
    SerBuffer() {}
    ~SerBuffer() {}
    
    void Write(const void* data, size_t size) {}
    void Read(void* data, size_t size) {}
    
    template<typename T>
    SerBuffer& operator<<(const T& data) { return *this; }
    
    template<typename T>
    SerBuffer& operator>>(T& data) { return *this; }
};

#endif // _SERBUFFER_H_
