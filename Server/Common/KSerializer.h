#ifndef _KSERIALIZER_H_
#define _KSERIALIZER_H_

#include "Serializer/SerBuffer.h"
#include <vector>

// KSerBuffer class
class KSerBuffer
{
public:
    KSerBuffer() {}
    ~KSerBuffer() {}
    
    void Clear() { buffer.clear(); }
    void Resize(size_t size) { buffer.resize(size); }
    size_t Size() const { return buffer.size(); }
    
    template<typename T>
    void Put(const T& data) {}
    
    template<typename T>
    void Get(T& data) {}
    
private:
    std::vector<unsigned char> buffer;
};

// KSerializer class
class KSerializer
{
public:
    KSerializer() {}
    ~KSerializer() {}
    
    void BeginWriting(KSerBuffer* buffer) {}
    void EndWriting() {}
    
    template<typename T>
    void Put(const T& data) {}
    
    template<typename T>
    void Get(T& data) {}
};

#endif // _KSERIALIZER_H_
