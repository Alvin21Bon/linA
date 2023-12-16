#ifndef LINA_MAT3_TRANSFORM_H
#define LINA_MAT3_TRANSFORM_H

#include "shared.h"
#include "mat-types.h"

// scaling
Mat3 mat3ScaledX(const Mat3 mat, const float scalar);
Mat3 mat3ScaledY(const Mat3 mat, const float scalar);
Mat3 mat3ScaledZ(const Mat3 mat, const float scalar);
Mat3 mat3Scaled(const Mat3 mat, const float scalar);

// rotating
Mat3 mat3RotatedX(const Mat3 mat, const double radians);
Mat3 mat3RotatedY(const Mat3 mat, const double radians);
Mat3 mat3RotatedZ(const Mat3 mat, const double radians);

Mat3 mat3Pitch(const Mat3 mat, const double radians);
Mat3 mat3Yaw(const Mat3 mat, const double radians);
Mat3 mat3Roll(const Mat3 mat, const double radians);

// reflecting
Mat3 mat3ReflectedYZ(const Mat3 mat);
Mat3 mat3ReflectedZY(const Mat3 mat);

Mat3 mat3ReflectedZX(const Mat3 mat);
Mat3 mat3ReflectedXZ(const Mat3 mat);

Mat3 mat3ReflectedXY(const Mat3 mat);
Mat3 mat3ReflectedYX(const Mat3 mat);

// shearing
Mat3 mat3ShearedYZ(const Mat3 mat, const float shearAmtY, const float shearAmtZ);
Mat3 mat3ShearedZY(const Mat3 mat, const float shearAmtZ, const float shearAmtY);

Mat3 mat3ShearedZX(const Mat3 mat, const float shearAmtZ, const float shearAmtX);
Mat3 mat3ShearedXZ(const Mat3 mat, const float shearAmtX, const float shearAmtZ);

Mat3 mat3ShearedXY(const Mat3 mat, const float shearAmtX, const float shearAmtY);
Mat3 mat3ShearedYX(const Mat3 mat, const float shearAmtY, const float shearAmtX);

#endif // LINA_MAT3_TRANSFORM_H
