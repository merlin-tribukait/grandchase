#ifndef _LOCKER_H_
#define _LOCKER_H_

#include <windows.h>

// Simple thread locker stub
class Locker
{
public:
    Locker() { InitializeCriticalSection(&cs); }
    ~Locker() { DeleteCriticalSection(&cs); }
    
    void Lock() { EnterCriticalSection(&cs); }
    void Unlock() { LeaveCriticalSection(&cs); }
    
private:
    CRITICAL_SECTION cs;
};

// RAII locker
class AutoLocker
{
public:
    AutoLocker(Locker& locker) : lock(locker) { lock.Lock(); }
    ~AutoLocker() { lock.Unlock(); }
    
private:
    Locker& lock;
};

// KncCriticalSection alias for compatibility
typedef Locker KncCriticalSection;

// KLocker alias for compatibility
typedef AutoLocker KLocker;

#endif // _LOCKER_H_
