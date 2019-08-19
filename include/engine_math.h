#include <xmmintrin.h>

//// Intrinsics
//inline u32
//RoundF32ToU32(f32 Real32)
//{
    //u32 Result = (u32)_mm_cvtss_si32(_mm_set_ss(Real32));
    //return Result;
//}

//inline f32
//Sqrt(f32 X) 
//{
    //f32 Result = _mm_cvtss_f32(_mm_sqrt_ss(_mm_set_ss(X)));
    //return Result;
//}

//// Scalar operations
//inline f32
//Square(f32 A)
//{
    //f32 Result = A*A;
    //return Result;
//}

//inline f32
//LinearTosRGB(f32 L)
//{
   //if (L < 0.0f) { L = 0.0f; }
   //if (L > 1.0f) { L = 1.0f; }

   //f32 S = L*12.92f;
   //if (L > 0.0031308f) {
       //S = 1.055f*pow(L, 1.0f/2.4f) - 0.055f;
   //}

   //return S;
//}

f32 mapRange(f32 input, f32 inputStart, f32 inputEnd, f32 outputStart, f32 outputEnd) {
    f64 slope = 1.0 * (outputEnd - outputStart) / (inputEnd- inputStart);
    return outputStart + (slope * (input - inputStart));
}

struct vec3d {
    f32 x, y, z;
};


struct mat4x4 {
    f32 m[4][4] = {};    
};

inline mat4x4
MakeIdentity()
{
    mat4x4 matrix;
    matrix.m[0][0] = 1.0f;
    matrix.m[1][1] = 1.0f;
    matrix.m[2][2] = 1.0f;
    matrix.m[3][3] = 1.0f;
    return matrix;
}

inline mat4x4
MakeRotationX(f32 angleRad)
{
    mat4x4 matrix; 
    matrix.m[0][0] = 1.0f; 
    matrix.m[1][1] = cosf(angleRad);
    matrix.m[1][2] = sinf(angleRad);
    matrix.m[2][1] = -sinf(angleRad);
    matrix.m[2][2] = cosf(angleRad);
    matrix.m[3][3] = 1.0f; 
    return matrix;
}

inline mat4x4
MakeRotationY(f32 angleRad)
{
    mat4x4 matrix; 
    matrix.m[0][0] = cosf(angleRad);
    matrix.m[0][2] = sinf(angleRad);
    matrix.m[2][0] = -sinf(angleRad);
    matrix.m[1][1] = 1.0f; 
    matrix.m[2][2] = cosf(angleRad);
    matrix.m[3][3] = 1.0f; 
    return matrix;
}

inline mat4x4
MakeRotationZ(f32 angleRad)
{
    mat4x4 matrix; 
    matrix.m[0][0] = cosf(angleRad);
    matrix.m[0][1] = sinf(angleRad);
    matrix.m[1][0] = -sinf(angleRad);
    matrix.m[1][1] = cosf(angleRad);
    matrix.m[2][2] = 1.0f; 
    matrix.m[3][3] = 1.0f; 
    return matrix;
}

inline mat4x4
MakeTranslation(f32 X, f32 Y, f32 Z)
{
    mat4x4 matrix; 
    matrix.m[0][0] = 1.0f; 
    matrix.m[1][1] = 1.0f; 
    matrix.m[2][2] = 1.0f; 
    matrix.m[3][3] = 1.0f; 
    matrix.m[3][0] = X; 
    matrix.m[3][1] = Y; 
    matrix.m[3][2] = Z; 
    return matrix;
}

inline mat4x4
MakeProjection(f32 fovDeg, f32 aspect, f32 fovNear, f32 fovFar)
{
    f32 fovRad = 1.0f / tanf(fovDeg * 0.5f / 180.0f * M_PI);
    mat4x4 matrix;
    matrix.m[0][0] = aspect * fovRad; 
    matrix.m[1][1] = fovRad; 
    matrix.m[2][2] = fovFar / (fovFar - fovNear); 
    matrix.m[3][2] = (-fovFar * fovNear) / (fovFar - fovNear); 
    matrix.m[2][3] = 1.0f; 
    matrix.m[3][3] = 0.0f; 
    return matrix;
}

