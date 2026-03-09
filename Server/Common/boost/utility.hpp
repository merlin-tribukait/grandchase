#ifndef BOOST_UTILITY_HPP
#define BOOST_UTILITY_HPP

// Boost utility stub
#include <memory>

namespace boost {
    template<typename T>
    class enable_shared_from_this;
    
    // Base class for non-copyable objects
    class noncopyable {
    protected:
        noncopyable() = default;
        ~noncopyable() = default;
    private:
        noncopyable(const noncopyable&) = delete;
        noncopyable& operator=(const noncopyable&) = delete;
    };
}

#endif // BOOST_UTILITY_HPP
