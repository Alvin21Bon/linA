#include "../include/lina.h"

void scaleXMat3(Mat3 matrixToTransform, const float scaleAmt)
{
	Mat3 transformation;
	fillIdentityMat3(transformation);

	scaleVec3(scaleAmt, transformation[0]);

	multMat3Mat(transformation, matrixToTransform);
}
void scaleYMat3(Mat3 matrixToTransform, const float scaleAmt)
{
	Mat3 transformation;
	fillIdentityMat3(transformation);

	scaleVec3(scaleAmt, transformation[1]);

	multMat3Mat(transformation, matrixToTransform);
}
void scaleZMat3(Mat3 matrixToTransform, const float scaleAmt)
{
	Mat3 transformation;
	fillIdentityMat3(transformation);

	scaleVec3(scaleAmt, transformation[2]);

	multMat3Mat(transformation, matrixToTransform);
}

void rotateXMat3(Mat3 matrixToTransform, const double angleInRadians)
{
	Mat3 transformation;
	Vec3 transformedIHat = {1, 0, 0};
	Vec3 transformedJHat = {0, cos(angleInRadians), -sin(angleInRadians)};
	Vec3 transformedKHat = {0, sin(angleInRadians), cos(angleInRadians)};

	fillMat3(transformedIHat, transformedJHat, transformedKHat, transformation);

	multMat3Mat(transformation, matrixToTransform);
}
void rotateYMat3(Mat3 matrixToTransform, const double angleInRadians)
{
	Mat3 transformation;
	Vec3 transformedIHat = {cos(angleInRadians), 0, sin(angleInRadians)};
	Vec3 transformedJHat = {0, 1, 0};
	Vec3 transformedKHat = {-sin(angleInRadians), 0, cos(angleInRadians)};

	fillMat3(transformedIHat, transformedJHat, transformedKHat, transformation);

	multMat3Mat(transformation, matrixToTransform);
}
void rotateZMat3(Mat3 matrixToTransform, const double angleInRadians)
{
	Mat3 transformation;
	Vec3 transformedIHat = {cos(angleInRadians), sin(angleInRadians), 0};
	Vec3 transformedJHat = {-sin(angleInRadians), cos(angleInRadians), 0};
	Vec3 transformedKHat = {0, 0, 1};

	fillMat3(transformedIHat, transformedJHat, transformedKHat, transformation);

	multMat3Mat(transformation, matrixToTransform);
}

void pitchMat3(Mat3 matrixToTransform, const double angleInRadians)
{
	rotateXMat3(matrixToTransform, angleInRadians);
}
void yawMat3(Mat3 matrixToTransform, const double angleInRadians)
{
	rotateYMat3(matrixToTransform, angleInRadians);
}
void rollMat3(Mat3 matrixToTransform, const double angleInRadians)
{
	rotateZMat3(matrixToTransform, angleInRadians);
}

void reflectPlaneYZMat3(Mat3 matrixToTransform)
{
	Mat3 transformation;
	fillIdentityMat3(transformation);

	negVec3(transformation[0]);

	multMat3Mat(transformation, matrixToTransform);
}
void reflectPlaneZYMat3(Mat3 matrixToTransform)
{
	reflectPlaneYZMat3(matrixToTransform);
}

void reflectPlaneZXMat3(Mat3 matrixToTransform)
{
	Mat3 transformation;
	fillIdentityMat3(transformation);

	negVec3(transformation[1]);

	multMat3Mat(transformation, matrixToTransform);
}
void reflectPlaneXZMat3(Mat3 matrixToTransform)
{
	reflectPlaneZXMat3(matrixToTransform);
}

void reflectPlaneXYMat3(Mat3 matrixToTransform)
{
	Mat3 transformation;
	fillIdentityMat3(transformation);

	negVec3(transformation[2]);

	multMat3Mat(transformation, matrixToTransform);
}
void reflectPlaneYXMat3(Mat3 matrixToTransform)
{
	reflectPlaneXYMat3(matrixToTransform);
}

void translate2DMat3(Mat3 matrixToTransform, const float x, const float y)
{
	Mat3 transformation;
	fillIdentityMat3(transformation);

	fillVec3(x, y, 1, transformation[2]);

	multMat3Mat(transformation, matrixToTransform);
}

void shearPlaneYZMat3(Mat3 matrixToTransform, const float shearAmtY, const float shearAmtZ)
{
	Mat3 transformation;
	fillIdentityMat3(transformation);

	fillVec3(1, shearAmtY, shearAmtZ, transformation[0]);

	multMat3Mat(transformation, matrixToTransform);
}
void shearPlaneZYMat3(Mat3 matrixToTransform, const float shearAmtY, const float shearAmtZ)
{
	shearPlaneYZMat3(matrixToTransform, shearAmtY, shearAmtZ);
}

void shearPlaneZXMat3(Mat3 matrixToTransform, const float shearAmtZ, const float shearAmtX)
{
	Mat3 transformation;
	fillIdentityMat3(transformation);

	fillVec3(shearAmtX, 1, shearAmtZ, transformation[1]);

	multMat3Mat(transformation, matrixToTransform);
}
void shearPlaneXZMat3(Mat3 matrixToTransform, const float shearAmtZ, const float shearAmtX)
{
	shearPlaneZXMat3(matrixToTransform, shearAmtZ, shearAmtX);
}

void shearPlaneXYMat3(Mat3 matrixToTransform, const float shearAmtX, const float shearAmtY)
{
	Mat3 transformation;
	fillIdentityMat3(transformation);

	fillVec3(shearAmtX, shearAmtY, 1, transformation[2]);

	multMat3Mat(transformation, matrixToTransform);
}
void shearPlaneYXMat3(Mat3 matrixToTransform, const float shearAmtX, const float shearAmtY)
{
	shearPlaneXYMat3(matrixToTransform, shearAmtX, shearAmtY);
}

