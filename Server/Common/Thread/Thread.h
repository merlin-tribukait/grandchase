#ifndef _THREAD_H_
#define _THREAD_H_

#include <windows.h>
#include <process.h>

// Simple thread stub
class Thread
{
public:
    Thread() : handle(nullptr), threadId(0) {}
    virtual ~Thread() { if (handle) CloseHandle(handle); }
    
    virtual void Run() = 0;
    
    bool Start()
    {
        handle = (HANDLE)_beginthreadex(nullptr, 0, ThreadFunc, this, 0, &threadId);
        return handle != nullptr;
    }
    
    void Wait()
    {
        if (handle) WaitForSingleObject(handle, INFINITE);
    }
    
private:
    static unsigned int __stdcall ThreadFunc(void* param)
    {
        Thread* thread = static_cast<Thread*>(param);
        thread->Run();
        return 0;
    }
    
    HANDLE handle;
    unsigned int threadId;
};

#endif // _THREAD_H_
