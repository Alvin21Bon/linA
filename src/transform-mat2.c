#include "../include/aglm.h"

void scaleXMat2(Mat2 matrixToTransform, const float scaleAmt)
{
	Mat2 transformation;
	fillIdentityMat2(transformation);

	scaleVec2(scaleAmt, transformation[0]);

	multMat2Mat(transformation, matrixToTransform);
}
void scaleYMat2(Mat2 matrixToTransform, const float scaleAmt)
{
	Mat2 transformation;
	fillIdentityMat2(transformation);

	scaleVec2(scaleAmt, transformation[1]);

	multMat2Mat(transformation, matrixToTransform);
}

void rotateXMat2(Mat2 matrixToTransform, const double angleInRadians)
{
	Mat2 transformation;
	Vec2 transformedIHat = {1, 0};
	Vec2 transformedJHat = {0, cos(angleInRadians)};

	fillMat2(transformedIHat, transformedJHat, transformation);

	multMat2Mat(transformation, matrixToTransform);
}
void rotateYMat2(Mat2 matrixToTransform, const double angleInRadians)
{
	Mat2 transformation;
	Vec2 transformedIHat = {cos(angleInRadians), 0};
	Vec2 transformedJHat = {0, 1};

	fillMat2(transformedIHat, transformedJHat, transformation);

	multMat2Mat(transformation, matrixToTransform);
}
void rotateZMat2(Mat2 matrixToTransform, const double angleInRadians)
{
	Mat2 transformation;
	Vec2 transformedIHat = {cos(angleInRadians), sin(angleInRadians)};
	Vec2 transformedJHat = {-sin(angleInRadians), cos(angleInRadians)};

	fillMat2(transformedIHat, transformedJHat, transformation);

	multMat2Mat(transformation, matrixToTransform);
}

void pitchMat2(Mat2 matrixToTransform, const double angleInRadians)
{
	rotateXMat2(matrixToTransform, angleInRadians);
}
void yawMat2(Mat2 matrixToTransform, const double angleInRadians)
{
	rotateYMat2(matrixToTransform, angleInRadians);
}
void rollMat2(Mat2 matrixToTransform, const double angleInRadians)
{
	rotateZMat2(matrixToTransform, angleInRadians);
}

void reflectPlaneYZMat2(Mat2 matrixToTransform) 
{
	Mat2 transformation;
	fillIdentityMat2(transformation);

	negVec2(transformation[0]);

	multMat2Mat(transformation, matrixToTransform);
}
void reflectPlaneZYMat2(Mat2 matrixToTransform)
{
	reflectPlaneYZMat2(matrixToTransform);
}

void reflectPlaneZXMat2(Mat2 matrixToTransform)
{
	Mat2 transformation;
	fillIdentityMat2(transformation);

	negVec2(transformation[1]);

	multMat2Mat(transformation, matrixToTransform);
}
void reflectPlaneXZMat2(Mat2 matrixToTransform)
{
	reflectPlaneZXMat2(matrixToTransform);
}

void reflectX(Mat2 matrixToTransform)
{
	reflectPlaneZXMat2(matrixToTransform);
}
void reflectY(Mat2 matrixToTransform)
{
	reflectPlaneYZMat2(matrixToTransform);
}

void shearPlaneYZMat2(Mat2 matrixToTransform, const float shearAmt);
void shearPlaneZYMat2(Mat2 matrixToTransform, const float shearAmt);

void shearPlaneZXMat2(Mat2 matrixToTransform, const float shearAmt);
void shearPlaneXZMat2(Mat2 matrixToTransform, const float shearAmt);

void shearX(Mat2 matrixToTransform, const float shearAmt);
void shearY(Mat2 matrixToTransform, const float shearAmt);
