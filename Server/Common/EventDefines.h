#ifndef _EVENT_DEFINES_H_
#define _EVENT_DEFINES_H_

#include "Serializer/SerBuffer.h"
#include "KNCSingleton.h"
#include "ToString.h"
#include "KSerializer.h"

// Missing type definitions
enum {
    eTAG_USERCLASS = 1000
};

// Missing macro definitions
#define SmartPtr(classname) typedef std::shared_ptr<classname> classname##Ptr

#define SERIALIZE_DEFINE_TAG(classname, tag) \
    static const int SERIALIZE_TAG = tag;

#define SERIALIZE_DECLARE_PUTGET(classname) \
    virtual void Serialize(SerBuffer& buffer) const; \
    virtual void Deserialize(SerBuffer& buffer);

#define NiDeclareRootRTTI(classname) \
    public: \
        static const char* GetClassName() { return #classname; } \
        virtual const char* GetRTTIName() const { return GetClassName(); }

#define DeclToStringW \
    virtual std::wstring ToStringW() const { return L#classname; }

#define DeclOstmOperatorW(classname) \
    inline std::wostream& operator<<(std::wostream& os, const classname& obj) { \
        return os << obj.ToStringW(); \
    }

// Missing constants
#define EVENT_EVENTID_SENTINEL 0xFFFF

// Missing KBuffer type
typedef std::vector<unsigned char> KBuffer;

#endif // _EVENT_DEFINES_H_
