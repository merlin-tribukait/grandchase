/** @file
@author cruise@kogsoft.com
*/

#ifndef _KLUAMANAGER_H_
#define _KLUAMANAGER_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

////#include <string>
extern "C"{
#include "LUA/lua.h"
#include "LUA/lauxlib.h"
#include "LUA/lualib.h"
};
//#include <windows.h>
////#include <assert.h>

/** LUA manager class.
LUA언어로 작성된 configuration file을 읽어 오고, 그 내용을 C++
프로그램으로 가져오기 위한 class. LUA의 기본형은 number (float 형태로
저장), string 2가지 뿐이고, 이들을 table (structure 개념과 유사)로
저장할 수 있다. table 내의 table도 지원된다. 자세한 내용은 LUA manual을
참고하기 바란다.
 
@verbinclude testKLuaManager.cpp
*/

#endif // _KLUAMANAGER_H_
