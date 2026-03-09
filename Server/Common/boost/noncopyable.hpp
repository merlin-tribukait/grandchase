#ifndef BOOST_NONCOPYABLE_HPP
#define BOOST_NONCOPYABLE_HPP

// Boost noncopyable stub
namespace boost {
    class noncopyable {
    protected:
        noncopyable() = default;
        ~noncopyable() = default;
    private:
        noncopyable(const noncopyable&) = delete;
        noncopyable& operator=(const noncopyable&) = delete;
    };
}

#endif // BOOST_NONCOPYABLE_HPP
