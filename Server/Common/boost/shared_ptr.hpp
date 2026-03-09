#ifndef BOOST_SHARED_PTR_HPP
#define BOOST_SHARED_PTR_HPP

// Boost shared_ptr stub
#include <memory>

namespace boost {
    template<typename T>
    using shared_ptr = std::shared_ptr<T>;
    
    template<typename T, typename... Args>
    shared_ptr<T> make_shared(Args&&... args) {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}

#endif // BOOST_SHARED_PTR_HPP
