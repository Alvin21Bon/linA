#include "../include/lina.h"

// scaling
Mat3 mat3ScaledX(const Mat3 mat, const float scalar)
{
	Mat3 transformation = mat3Identity();
	transformation.ihat.x = scalar;
	return mat3MultMat(transformation, mat);
}
Mat3 mat3ScaledY(const Mat3 mat, const float scalar)
{
	Mat3 transformation = mat3Identity();
	transformation.jhat.y = scalar;
	return mat3MultMat(transformation, mat);
}
Mat3 mat3ScaledZ(const Mat3 mat, const float scalar)
{
	Mat3 transformation = mat3Identity();
	transformation.khat.z = scalar;
	return mat3MultMat(transformation, mat);
}
Mat3 mat3Scaled(const Mat3 mat, const float scalar)
{
	Mat3 transformation = mat3Diagonalize(scalar);
	return mat3MultMat(transformation, mat);
}

// rotating
Mat3 mat3Rotated(const Mat3 mat, const double radians, const Vec3 axis);
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

