#ifndef _DSETUP_H_
#define _DSETUP_H_

// Stub DirectX Setup header for compilation
typedef void* PDIRECTSETUP;
typedef unsigned long DWORD;

// Stub DirectX Setup functions
extern "C" {
    PDIRECTSETUP DirectSetupCreate();
    void DirectSetupDestroy(PDIRECTSETUP pSetup);
    bool DirectXSetupGetVersion(DWORD* dwVersion, DWORD* dwRevision);
}

#endif // _DSETUP_H_
