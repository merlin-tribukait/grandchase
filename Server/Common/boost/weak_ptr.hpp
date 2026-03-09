#ifndef BOOST_WEAK_PTR_HPP
#define BOOST_WEAK_PTR_HPP

// Boost weak_ptr stub
#include <memory>

namespace boost {
    template<typename T>
    using weak_ptr = std::weak_ptr<T>;
}

#endif // BOOST_WEAK_PTR_HPP
