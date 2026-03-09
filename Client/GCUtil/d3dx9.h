#ifndef _D3DX9_H_
#define _D3DX9_H_

// Temporary stub for d3dx9.h to allow compilation
// This is a minimal implementation - the real DirectX SDK would be needed for full functionality

#include <d3d9.h>

// Basic types and macros that might be needed
#define D3DX_DEFAULT            ((UINT)0)
#define D3DX_FILTER_NONE         1
#define D3DX_FILTER_POINT        2
#define D3DX_FILTER_LINEAR       3
#define D3DX_FILTER_TRIANGLE      4
#define D3DX_FILTER_BOX          5

// Basic matrix operations (stubs)
struct D3DXMATRIX : public D3DMATRIX
{
    D3DXMATRIX() {}
    D3DXMATRIX(const float* rhs) { memcpy(&m, rhs, sizeof(m)); }
    D3DXMATRIX(float m00, float m01, float m02, float m03,
                float m10, float m11, float m12, float m13,
                float m20, float m21, float m22, float m23,
                float m30, float m31, float m32, float m33)
    {
        m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
        m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
        m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
        m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
    }
    
    // Accessors
    float& operator () (int row, int col) { return m[row][col]; }
    const float& operator () (int row, int col) const { return m[row][col]; }
};

// Basic stub functions
inline D3DXMATRIX* D3DXMatrixIdentity(D3DXMATRIX *pout)
{
    if (pout == nullptr) return nullptr;
    memset(pout, 0, sizeof(D3DXMATRIX));
    pout->m[0][0] = pout->m[1][1] = pout->m[2][2] = pout->m[3][3] = 1.0f;
    return pout;
}

inline D3DXMATRIX* D3DXMatrixTranslation(D3DXMATRIX *pout, float x, float y, float z)
{
    D3DXMatrixIdentity(pout);
    if (pout) {
        pout->m[3][0] = x;
        pout->m[3][1] = y;
        pout->m[3][2] = z;
    }
    return pout;
}

inline D3DXMATRIX* D3DXMatrixRotationX(D3DXMATRIX *pout, float angle)
{
    D3DXMatrixIdentity(pout);
    if (pout) {
        float c = cosf(angle);
        float s = sinf(angle);
        pout->m[1][1] = c;
        pout->m[1][2] = s;
        pout->m[2][1] = -s;
        pout->m[2][2] = c;
    }
    return pout;
}

inline D3DXMATRIX* D3DXMatrixRotationY(D3DXMATRIX *pout, float angle)
{
    D3DXMatrixIdentity(pout);
    if (pout) {
        float c = cosf(angle);
        float s = sinf(angle);
        pout->m[0][0] = c;
        pout->m[0][2] = -s;
        pout->m[2][0] = s;
        pout->m[2][2] = c;
    }
    return pout;
}

inline D3DXMATRIX* D3DXMatrixRotationZ(D3DXMATRIX *pout, float angle)
{
    D3DXMatrixIdentity(pout);
    if (pout) {
        float c = cosf(angle);
        float s = sinf(angle);
        pout->m[0][0] = c;
        pout->m[0][1] = s;
        pout->m[1][0] = -s;
        pout->m[1][1] = c;
    }
    return pout;
}

#endif // _D3DX9_H_
