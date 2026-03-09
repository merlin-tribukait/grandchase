#pragma once

// Stub KncSecurity header to avoid missing include issues
class KncSecurity
{
public:
    KncSecurity() {}
    ~KncSecurity() {}
    
    bool Initialize() { return true; }
    void Shutdown() {}
    bool Encrypt(void* data, size_t size) { return true; }
    bool Decrypt(void* data, size_t size) { return true; }
};
