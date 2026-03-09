#ifndef _LAUXLIB_STUB_H_
#define _LAUXLIB_STUB_H_

#include "lua.h"

// Stub auxiliary library functions
extern "C" {
    int luaL_dostring(lua_State* L, const char* str);
    int luaL_dofile(lua_State* L, const char* filename);
    void luaL_error(lua_State* L, const char* fmt, ...);
    int luaL_ref(lua_State* L, int t);
    void luaL_unref(lua_State* L, int t, int ref);
}

#endif // _LAUXLIB_STUB_H_
