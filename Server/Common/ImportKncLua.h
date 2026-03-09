#ifndef _IMPORTKNCLUA_H_
#define _IMPORTKNCLUA_H_

#include "KncLua.h"

// Import KncLua functionality for server
class ImportKncLua
{
public:
    static void Initialize() {}
    static void Shutdown() {}
    static bool LoadScript(const char* filename) { return true; }
};

#endif // _IMPORTKNCLUA_H_
