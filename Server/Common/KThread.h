#ifndef _KTHREAD_H_
#define _KTHREAD_H_

#include "thread/Thread.h"
#include "Thread/Locker.h"

// Base thread class
class KThread : public Thread
{
public:
    KThread() : running(false) {}
    virtual ~KThread() {}
    
    bool StartThread()
    {
        running = true;
        return Start();
    }
    
    void StopThread()
    {
        running = false;
    }
    
    bool IsRunning() const { return running; }
    
protected:
    volatile bool running;
};

#endif // _KTHREAD_H_
