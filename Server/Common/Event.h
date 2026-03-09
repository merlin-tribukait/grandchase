#pragma once

#include "EventDefines.h"
#include <memory>
#include <boost/noncopyable.hpp>
#include <Serializer/SerBuffer.h>
#include "KncSmartPtr.h"
#include "RTTI.h"
#include <dbg.hpp>
#include <ToString.h>

// Forward declaration
SmartPointer(KEvent);

class KEvent;
SERIALIZE_DEFINE_TAG(KEvent, 1)
SERIALIZE_DECLARE_PUTGET(KEvent);

// Missing macro definitions for RTTI and string conversion
struct NiRTTI {
    const char* name;
    NiRTTI(const char* n) : name(n) {}
};

#ifndef NiDeclareRootRTTI
#define NiDeclareRootRTTI(classname) \
public: \
    static const NiRTTI* GetRTTI() { return &ms_RTTI; } \
    virtual const NiRTTI* GetRTTI() const { return &ms_RTTI; } \
    static bool IsKindOf(const NiRTTI& rtti) { return &ms_RTTI == &rtti; } \
    virtual bool IsKindOf(const NiRTTI& rtti) const { return &ms_RTTI == &rtti; } \
    virtual const char* GetTypeName() const { return #classname; } \
private: \
    static const NiRTTI ms_RTTI;
#endif

#ifndef DeclToStringW
#define DeclToStringW \
public: \
    virtual std::wstring ToString() const;
#endif

// Missing serialization macros
#ifndef SERIALIZE_DEFINE_TAG
#define SERIALIZE_DEFINE_TAG(classname, tag) \
    static const DWORD ms_dwSerializeTag = tag;
#endif

#ifndef SERIALIZE_DECLARE_PUTGET
#define SERIALIZE_DECLARE_PUTGET(classname) \
public: \
    virtual void Serialize(Serializer::SerBuffer& buffer) const; \
    virtual void Deserialize(Serializer::SerBuffer& buffer);
#endif

class KEvent : public boost::noncopyable
{
public:
	// RTTI implementation
	static const NiRTTI* GetRTTI() { return &ms_RTTI; }
	virtual const NiRTTI* GetRTTI() const { return &ms_RTTI; }
	static bool IsKindOf(const NiRTTI& rtti) { return &ms_RTTI == &rtti; }
	virtual bool IsKindOf(const NiRTTI& rtti) const { return &ms_RTTI == &rtti; }
	virtual const char* GetTypeName() const { return "KEvent"; }
	virtual std::wstring ToString() const { return L"KEvent"; }
	
private:
	static const NiRTTI ms_RTTI;

public:
	enum FROM_TYPE {
		FT_NONE = 0,
		FT_INNER,
		FT_OUTTER,
		FT_MAX
	};
	KEvent(void);
	virtual ~KEvent(void);

	virtual const wchar_t* GetEventIDString() const { return L"virtual function called."; }

	template <class T>
	void Serialize(const T& data);

	//SERIALIZE_DECLARE_FRIEND( KEvent );

//protected:
	unsigned short      m_usEventID;
	KSerBuffer          m_kbuff;
	int                 m_nFrom; //0, internal, outer
};

template <class T>
void KEvent::Serialize(const T& data_)
{
	KSerializer ks;
	m_kbuff.Clear();

	// serialize - only data
	ks.BeginWriting(&m_kbuff);
	ks.Put(data_);
	ks.EndWriting();
}

DeclOstmOperatorW(KEvent);
// ms_szEventID[]   : 이벤트 아이디의 문자열 변수
// GetEventIDString : 이벤트 아이디의 문자열을 얻어온다
#define DeclareEvent( classname ) \
public: \
    virtual const wchar_t*  GetEventIDString() const; \
    static const wchar_t*   GetEventIDString( unsigned short usEventID ); \
    static const wchar_t*   ms_szEventID[]; \

// GetEventIDString()   : implement
#define ImplementEvent( classname ) \
    const wchar_t* classname::GetEventIDString() const \
    { \
        if( m_usEventID >= EVENT_EVENTID_SENTINEL ) \
        { \
            return ms_szEventID[ EVENT_EVENTID_SENTINEL ]; \
        } \
        return ms_szEventID[ m_usEventID ]; \
    } \
    const wchar_t* classname::GetEventIDString( unsigned short usEventID ) \
    { \
        if( usEventID >= EVENT_EVENTID_SENTINEL ) \
        { \
            return ms_szEventID[ EVENT_EVENTID_SENTINEL ]; \
        } \
        return ms_szEventID[ usEventID ]; \
    }
