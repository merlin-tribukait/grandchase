#ifndef _LOG4CXX_BASICCONFIGURATOR_H_
#define _LOG4CXX_BASICCONFIGURATOR_H_

namespace log4cxx
{
    class BasicConfigurator 
    {
    public:
        static void configure();
        static void resetConfiguration();
    };
}

#endif // _LOG4CXX_BASICCONFIGURATOR_H_
