#ifndef _LUALIB_STUB_H_
#define _LUALIB_STUB_H_

#include "lua.h"

// Stub standard library functions
extern "C" {
    void luaopen_base(lua_State* L);
    void luaopen_string(lua_State* L);
    void luaopen_math(lua_State* L);
    void luaopen_table(lua_State* L);
}

#endif // _LUALIB_STUB_H_
