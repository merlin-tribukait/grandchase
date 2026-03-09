#ifndef _LUA_STUB_H_
#define _LUA_STUB_H_

// Stub Lua headers for compilation
// In a real setup, these would be the actual Lua headers

typedef struct lua_State lua_State;
typedef int lua_Integer;
typedef double lua_Number;

// Stub Lua functions
extern "C" {
    lua_State* luaL_newstate();
    void luaL_openlibs(lua_State* L);
    void lua_close(lua_State* L);
    int luaL_loadfile(lua_State* L, const char* filename);
    int lua_pcall(lua_State* L, int nargs, int nresults, int errfunc);
    void lua_getglobal(lua_State* L, const char* name);
    void lua_setglobal(lua_State* L, const char* name);
    void lua_pushstring(lua_State* L, const char* s);
    void lua_pushnumber(lua_State* L, lua_Number n);
    void lua_pushinteger(lua_State* L, lua_Integer n);
    const char* lua_tostring(lua_State* L, int index);
    lua_Number lua_tonumber(lua_State* L, int index);
    lua_Integer lua_tointeger(lua_State* L, int index);
    int lua_isstring(lua_State* L, int index);
    int lua_isnumber(lua_State* L, int index);
}

#define LUA_GLOBALSINDEX "_G"

#endif // _LUA_STUB_H_
