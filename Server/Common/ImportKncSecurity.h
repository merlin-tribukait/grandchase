#ifndef IMPORT_KNC_SECURITY_H
#define IMPORT_KNC_SECURITY_H

// Security import stub
#include <windows.h>

// Dummy security functions
BOOL KncSecurityInitialize() { return TRUE; }
BOOL KncSecurityValidate() { return TRUE; }
VOID KncSecurityCleanup() {}

#endif // IMPORT_KNC_SECURITY_H
