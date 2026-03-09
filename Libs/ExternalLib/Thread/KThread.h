#ifndef KTHREAD_H
#define KTHREAD_H

#include <windows.h>
#include "Locker.h"

class KThread {
public:
    KThread() : m_handle(nullptr), m_threadId(0) {}
    virtual ~KThread() {
        if (m_handle) {
            CloseHandle(m_handle);
        }
    }
    
    virtual void Run() = 0;
    
    bool Start() {
        m_handle = CreateThread(nullptr, 0, ThreadProc, this, 0, &m_threadId);
        return m_handle != nullptr;
    }
    
    void Join() {
        if (m_handle) {
            WaitForSingleObject(m_handle, INFINITE);
        }
    }
    
protected:
    static DWORD WINAPI ThreadProc(LPVOID param) {
        KThread* thread = static_cast<KThread*>(param);
        thread->Run();
        return 0;
    }
    
    HANDLE m_handle;
    DWORD m_threadId;
    KncCriticalSection m_csExceptionTime;
};

#endif // KTHREAD_H
