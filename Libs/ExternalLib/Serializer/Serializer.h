#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <vector>
#include <string>
#include <memory>

namespace Serializer {
    class Buffer {
    public:
        Buffer() {}
        ~Buffer() {}
        
        void clear() { data.clear(); }
        size_t size() const { return data.size(); }
        const char* data_ptr() const { return data.empty() ? nullptr : &data[0]; }
        
        void append(const char* d, size_t len) {
            data.insert(data.end(), d, d + len);
        }
        
        template<typename T>
        void write(const T& value) {
            append(reinterpret_cast<const char*>(&value), sizeof(T));
        }
        
    private:
        std::vector<char> data;
    };
    
    class SerBuffer : public Buffer {
    public:
        SerBuffer() {}
        ~SerBuffer() {}
    };
}

#endif // SERIALIZER_H
