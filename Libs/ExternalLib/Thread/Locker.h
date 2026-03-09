#ifndef LOCKER_H
#define LOCKER_H

// Thread locking utilities
class KncCriticalSection {
public:
    KncCriticalSection() {}
    ~KncCriticalSection() {}
    void Lock() {}
    void Unlock() {}
};

class KLocker {
public:
    explicit KLocker(KncCriticalSection& cs) : m_cs(cs) {
        m_cs.Lock();
    }
    ~KLocker() {
        m_cs.Unlock();
    }
    
private:
    KncCriticalSection& m_cs;
};

#define KAutoLock(cs) KLocker locker(cs)

#endif // LOCKER_H
