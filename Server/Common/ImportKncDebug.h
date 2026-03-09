#ifndef IMPORT_KNC_DEBUG_H
#define IMPORT_KNC_DEBUG_H

// Debug import stub
#include <windows.h>

// Dummy debug functions
VOID KncDebugInitialize() {}
VOID KncDebugCleanup() {}
VOID KncDebugTrace(LPCWSTR msg) { OutputDebugStringW(msg); }
VOID KncDebugInfo(LPCWSTR msg) { OutputDebugStringW(msg); }
VOID KncDebugError(LPCWSTR msg) { OutputDebugStringW(msg); }

#endif // IMPORT_KNC_DEBUG_H
