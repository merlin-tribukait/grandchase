#ifndef ACTOR_H
#define ACTOR_H

#include "Socket/Session.h"

#include "FSM/support_FSM.h"

SmartPointer(KActor);

class KActor : public KSession
{
public:
	// RTTI implementation
	static const NiRTTI* GetRTTI() { return &ms_RTTI; }
	virtual const NiRTTI* GetRTTI() const { return &ms_RTTI; }
	static bool IsKindOf(const NiRTTI& rtti) { return &ms_RTTI == &rtti; }
	virtual bool IsKindOf(const NiRTTI& rtti) const { return &ms_RTTI == &rtti; }
	virtual const char* GetTypeName() const { return "KActor"; }
	virtual std::wstring ToString() const { return L"KActor"; }
	
private:
	static const NiRTTI ms_RTTI;

	DeclareFSM_MT;

public:
	KActor();
	virtual ~KActor();

protected:
	KncCriticalSection m_cs;
};

#endif