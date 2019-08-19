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

//f32 mapRange(f32 input, f32 inputStart, f32 inputEnd, f32 outputStart, f32 outputEnd) {
    //f64 slope = 1.0 * (outputEnd - outputStart) / (inputEnd- inputStart);
    //return outputStart + (slope * (input - inputStart));
//}

//// Structs
//union v2 
//{
    //struct {
        //f32 x, y;
    //};
    //struct {
        //f32 u, v;
    //};
    //f32 E[2];
//};

//union v3
//{
    //struct {
        //f32 x, y, z;
    //};
    //struct {
        //f32 u, v, __;
    //};
    //struct {
        //f32 r, g, b;
    //};
    //struct {
        //v2 xy;
        //f32 Ignored0_;
    //};
    //struct {
        //f32 Ignored1_;
        //v2 yz;
    //};
    //struct {
        //v2 uv;
        //f32 Ignored2_;
    //};
    //struct {
        //f32 Ignored3_;
        //v2 v__;
    //};
    //f32 E[3];
//};

//union v4
//{
    //struct {
        //union
        //{
            //v3 xyz;
            //struct {
                //f32 x, y, z;
            //};
        //};
        
        //f32 w;  
    //};
    //struct {
        //union
        //{
            //v3 rgb;
            //struct {
                //f32 r, g, b;
            //};
        //};
        
        //f32 a;        
    //};
    //struct {
        //v2 xy;
        //f32 Ignored0_;
        //f32 Ignored1_;
    //};
    //struct {
        //f32 Ignored2_;
        //v2 yz;
        //f32 Ignored3_;
    //};
    //struct {
        //f32 Ignored4_;
        //f32 Ignored5_;
        //v2 zw;
    //};
    //f32 E[4];
//};

////
//// v2 operations
////

//inline v2
//V2(f32 X, f32 Y) 
//{
    //v2 Result;
    //Result.x = X;
    //Result.y = Y;
    //return Result;
//}

////
//// v3 operations
////

//inline v3
//operator*(f32 A, v3 B)
//{
    //v3 Result;
    //Result.x = A*B.x;
    //Result.y = A*B.y;
    //Result.z = A*B.z;
    //return Result;
//}

//inline v3
//operator*(v3 B, f32 A)
//{
    //v3 Result = A*B;
    //return Result;
//}

//inline v3
//operator-(v3 A, v3 B)
//{
    //v3 Result;
    //Result.x = A.x - B.x;
    //Result.y = A.y - B.y;
    //Result.z = A.z - B.z;
    //return Result;
//}

//inline v3
//operator+(v3 A, v3 B)
//{
    //v3 Result;
    //Result.x = A.x + B.x;
    //Result.y = A.y + B.y;
    //Result.z = A.z + B.z;
    //return Result;
//}

//inline v3 &
//operator+=(v3 &A, v3 B)
//{
    //A = A + B;
    //return A;
//}

//inline v3
//V3(f32 X, f32 Y, f32 Z) 
//{
    //v3 Result;
    //Result.x = X;
    //Result.y = Y;
    //Result.z = Z;
    //return Result;
//}

//inline f32
//Dot(v3 A, v3 B)
//{
    //f32 Result = A.x*B.x + A.y*B.y + A.z*B.z;
    //return Result;
//}

//inline v3
//Cross(v3 A, v3 B)
//{
    //v3 Result;
    //Result.x = A.y*B.z - A.z*B.y;
    //Result.y = A.z*B.x - A.x*B.z;
    //Result.z = A.x*B.y - A.y*B.x;
    //return Result;
//}

//inline f32
//LengthSq(v3 A)
//{
   //f32 Result = Dot(A, A); 
   //return Result;
//}

//inline f32
//Length(v3 A)
//{
    //f32 Result = Sqrt(LengthSq(A));    
    //return Result;
//}

//inline v3
//Normalize(v3 A)
//{
    //v3 Result = A * (1.0f / Length(A));
    //return Result;
//}

//inline v3
//NOZ(v3 A)
//{
    //v3 Result = {};
    //f32 LenSq = LengthSq(A);
    //if (LenSq > Square(0.0001f)) {
        //Result = A * (1.0f / Length(A));
    //}
    //return Result;
//}

//inline v3
//Lerp(v3 A, v3 B, f32 t)
//{
    //v3 Result = A*(1.0f - t) + B*t;
    //return Result;
//}

//inline v3
//Hadamard(v3 A, v3 B)
//{
    //v3 Result;
    //Result.x = A.x*B.x;
    //Result.y = A.y*B.y;
    //Result.z = A.z*B.z;
    //return Result;
//}

////
//// v4 operations
////

//inline u32
//BGRAPack(v4 Color)
//{
    //u32 Result = ((RoundF32ToU32(Color.a) << 24) |
                  //(RoundF32ToU32(Color.r) << 16) |
                  //(RoundF32ToU32(Color.g) << 8)  |
                  //(RoundF32ToU32(Color.b) << 0));

    //return Result;
//}

//inline v4
//V4(f32 X, f32 Y, f32 Z, f32 W)
//{
    //v4 Result;
    //Result.x = X;
    //Result.y = Y;
    //Result.z = Z;
    //Result.w = W;
    //return Result;
//}

//inline v4
//V4(v3 XYZ, f32 W)
//{
    //v4 Result;
    //Result.xyz = XYZ;
    //Result.w = W;
    //return Result;
//}

//inline f32
//Dot(v4 A, v4 B)
//{
    //f32 Result = A.x*B.x + A.y*B.y + A.z*B.z;
    //return Result;
//}

//inline v4
//Cross(v4 A, v4 B)
//{
    //v4 Result;
    //Result.x = A.y*B.z - A.z*B.y;
    //Result.y = A.z*B.x - A.x*B.z;
    //Result.z = A.x*B.y - A.y*B.x;
    //return Result;
//}

//inline f32
//LengthSq(v4 A)
//{
   //f32 Result = Dot(A, A); 
   //return Result;
//}

//inline f32
//Length(v4 A)
//{
    //f32 Result = Sqrt(LengthSq(A));    
    //return Result;
//}

//inline v4
//Multiply(v4 V, mat4x4 M)
//{
    //v4 Result;
    //Result.x = V.x * M.m[0][0] + V.y * M.m[1][0] + V.z * M.m[2][0] + M.m[3][0];
    //Result.y = V.x * M.m[0][1] + V.y * M.m[1][1] + V.z * M.m[2][1] + M.m[3][1];
    //Result.z = V.x * M.m[0][2] + V.y * M.m[1][2] + V.z * M.m[2][2] + M.m[3][2];
    //Result.w = V.x * M.m[0][3] + V.y * M.m[1][3] + V.z * M.m[2][3] + M.m[3][3];
    //return Result;
//}

//[>inline v4<]
////Normalize(v4 A)
////{
    ////v4 Result = A * (1.0f / Length(A));
    ////return Result;
////}

//inline v4
//operator*(f32 A, v4 B)
//{
    //v4 Result;
    //Result.x = A*B.x;
    //Result.y = A*B.y;
    //Result.z = A*B.z;
    //return Result;
//}

//inline v4
//operator*(v4 B, f32 A)
//{
    //v4 Result = A*B;
    //return Result;
//}

//inline v4
//operator-(v4 A, v4 B)
//{
    //v4 Result;
    //Result.x = A.x - B.x;
    //Result.y = A.y - B.y;
    //Result.z = A.z - B.z;
    //Result.w = A.w - B.w;
    //return Result;
//}

//inline v4
//operator+(v4 A, v4 B)
//{
    //v4 Result;
    //Result.x = A.x + B.x;
    //Result.y = A.y + B.y;
    //Result.z = A.z + B.z;
    //Result.w = A.w + B.w;
    //return Result;
//}


//// 
//// mat4x4 Operations
//// 
//inline mat4x4 
//Multiply(mat4x4 M1, mat4x4 M2)
//{
    //mat4x4 matrix;
    //for (int c = 0; c < 4; c++) 
        //for (int r = 0; r < 4; r++) 
            //matrix.m[r][c] = M1.m[r][0] * M2.m[0][c] + M1.m[r][1] * M2.m[1][c] + M1.m[r][2] * M2.m[2][c] + M1.m[r][3] * M2.m[3][c];
    //return matrix;
//}


struct vec3d {
    f32 x = 0.0f;
    f32 y = 0.0f;
    f32 z = 0.0f;
    //f32 w = 1.0f;
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

