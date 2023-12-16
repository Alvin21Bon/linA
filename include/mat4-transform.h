#ifndef LINA_MAT4_TRANSFORM_H
#define LINA_MAT4_TRANSFORM_H

#include "shared.h"
#include "mat-types.h"

// scaling
Mat4 mat4ScaledX(const Mat4 mat, const float scalar);
Mat4 mat4ScaledY(const Mat4 mat, const float scalar);
Mat4 mat4ScaledZ(const Mat4 mat, const float scalar);
Mat4 mat4Scaled(const Mat4 mat, const float scalar);

// rotating
Mat4 mat4RotatedX(const Mat4 mat, const double radians);
Mat4 mat4RotatedY(const Mat4 mat, const double radians);
Mat4 mat4RotatedZ(const Mat4 mat, const double radians);

Mat4 mat4Pitch(const Mat4 mat, const double radians);
Mat4 mat4Yaw(const Mat4 mat, const double radians);
Mat4 mat4Roll(const Mat4 mat, const double radians);

// reflecting
Mat4 mat4ReflectedYZ(const Mat4 mat);
Mat4 mat4ReflectedZY(const Mat4 mat);

Mat4 mat4ReflectedZX(const Mat4 mat);
Mat4 mat4ReflectedXZ(const Mat4 mat);

Mat4 mat4ReflectedXY(const Mat4 mat);
Mat4 mat4ReflectedYX(const Mat4 mat);

// shearing
Mat4 mat4ShearedYZ(const Mat4 mat, const float shearAmtY, const float shearAmtZ);
Mat4 mat4ShearedZY(const Mat4 mat, const float shearAmtZ, const float shearAmtY);

Mat4 mat4ShearedZX(const Mat4 mat, const float shearAmtZ, const float shearAmtX);
Mat4 mat4ShearedXZ(const Mat4 mat, const float shearAmtX, const float shearAmtZ);

Mat4 mat4ShearedXY(const Mat4 mat, const float shearAmtX, const float shearAmtY);
Mat4 mat4ShearedYX(const Mat4 mat, const float shearAmtY, const float shearAmtX);

// translating
Mat4 mat4Translate(const Mat4 mat, const Vec3 translation);
Mat4 mat4TranslateV(const Mat4 mat, const Vec3 translation); // helper
Mat4 mat4TranslateF(const Mat4 mat, const float x, const float y, const float z);

#endif // LINA_MAT4_TRANSFORM_H
