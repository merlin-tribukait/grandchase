#ifndef BOOST_ENABLE_SHARED_FROM_THIS_HPP
#define BOOST_ENABLE_SHARED_FROM_THIS_HPP

// Boost enable_shared_from_this stub
#include <memory>

namespace boost {
    template<typename T>
    class enable_shared_from_this {
    public:
        std::shared_ptr<T> shared_from_this() {
            return std::static_pointer_cast<T>(std::shared_ptr<T>(this));
        }
        std::shared_ptr<const T> shared_from_this() const {
            return std::static_pointer_cast<const T>(std::shared_ptr<const T>(this));
        }
    protected:
        virtual ~enable_shared_from_this() = default;
    };
}

#endif // BOOST_ENABLE_SHARED_FROM_THIS_HPP
