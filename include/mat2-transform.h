#ifndef LINA_MAT2_TRANSFORM_H
#define LINA_MAT2_TRANSFORM_H

#include "shared.h"
#include "mat-types.h"

// scaling
Mat2 mat2ScaledX(const Mat2 mat, const float scalar);
Mat2 mat2ScaledY(const Mat2 mat, const float scalar);
Mat2 mat2Scaled(const Mat2 mat, const float scalar);

// rotating
Mat2 mat2Rotated(const Mat2 mat, const double radians, const Vec3 axis);
Mat2 mat2Pitch(const Mat2 mat, const double radians);
Mat2 mat2Yaw(const Mat2 mat, const double radians);
Mat2 mat2Roll(const Mat2 mat, const double radians);

// reflecting
Mat2 mat2ReflectedX(const Mat2 mat);
Mat2 mat2ReflectedY(const Mat2 mat);

// shearing
Mat2 mat2ShearedX(const Mat2 mat, const float shearAmt);
Mat2 mat2ShearedY(const Mat2 mat, const float shearAmt);

#endif // LINA_MAT2_TRANSFORM_H
