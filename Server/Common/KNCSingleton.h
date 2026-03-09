#ifndef _SINGLETON_H_
#define _SINGLETON_H_

// Simple singleton template
template<typename T>
class KNCSingleton
{
public:
    static T& Instance()
    {
        static T instance;
        return instance;
    }
    
protected:
    KNCSingleton() {}
    virtual ~KNCSingleton() {}
    
private:
    KNCSingleton(const KNCSingleton&) = delete;
    KNCSingleton& operator=(const KNCSingleton&) = delete;
};

#endif // _SINGLETON_H_
