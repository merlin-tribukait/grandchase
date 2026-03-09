#ifndef DBG_HPP
#define DBG_HPP

// Debug utilities stub
#include <iostream>

#define DBG_TRACE(msg) std::cout << "[TRACE] " << msg << std::endl
#define DBG_INFO(msg) std::cout << "[INFO] " << msg << std::endl
#define DBG_WARN(msg) std::cout << "[WARN] " << msg << std::endl
#define DBG_ERROR(msg) std::cout << "[ERROR] " << msg << std::endl

#endif // DBG_HPP
