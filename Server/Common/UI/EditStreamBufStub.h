#pragma once

#include "EditLog.h"
#include <streambuf>

namespace EditStream {
    // Stub implementation to avoid template issues
    template <class E, class T = std::char_traits<E>, int BUF_SIZE = 2048 >
    class basic_editstreambuf : public std::basic_streambuf< E, T >
    {
    public:
        using char_type = E;
        using int_type = typename T::int_type;
        using traits_type = T;
        
        basic_editstreambuf(class CEditLog* pList) {}
        virtual ~basic_editstreambuf() {}
        
    protected:
        virtual int_type overflow(int_type c = T::eof()) { return c; }
        virtual int sync() { return 0; }
        virtual std::streamsize xsputn(const char_type* pch, std::streamsize n) { return n; }
        
        char_type*	psz;
        class CEditLog*		m_pEditLog;
        CRITICAL_SECTION	m_csLock;
    };

    // Ansi version
    typedef basic_editstreambuf< char >		editstreambuf;
    // Unicode version
    typedef basic_editstreambuf< wchar_t>	weditstreambuf;

    // TCHAR version
#ifdef _UNICODE
#define _teditstreambuf weditstreambuf
#else
#define _teditstreambuf editstreambuf
#endif
} // namespace EditStream
