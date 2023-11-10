#include "../include/aglm.h"

void scaleXMat4(Mat4 matrixToTransform, const float scaleAmt)
{
	Mat4 transformation;
	fillIdentityMat4(transformation);

	scaleVec4(scaleAmt, transformation[0]);

	multMat4Mat(transformation, matrixToTransform);
}
void scaleYMat4(Mat4 matrixToTransform, const float scaleAmt)
{
	Mat4 transformation;
	fillIdentityMat4(transformation);

	scaleVec4(scaleAmt, transformation[1]);

	multMat4Mat(transformation, matrixToTransform);
}
void scaleZMat4(Mat4 matrixToTransform, const float scaleAmt)
{
	Mat4 transformation;
	fillIdentityMat4(transformation);

	scaleVec4(scaleAmt, transformation[2]);

	multMat4Mat(transformation, matrixToTransform);
}

void rotateXMat4(Mat4 matrixToTransform, const double angleInRadians);
void rotateYMat4(Mat4 matrixToTransform, const double angleInRadians);
void rotateZMat4(Mat4 matrixToTransform, const double angleInRadians);

void pitchMat4(Mat4 matrixToTransform, const double angleInRadians);
void yawMat4(Mat4 matrixToTransform, const double angleInRadians);
void rollMat4(Mat4 matrixToTransform, const double angleInRadians);

void reflectPlaneYZMat4(Mat4 matrixToTransform); 
void reflectPlaneZYMat4(Mat4 matrixToTransform);

void reflectPlaneZXMat4(Mat4 matrixToTransform);
void reflectPlaneXZMat4(Mat4 matrixToTransform);

void reflectPlaneXYMat4(Mat4 matrixToTransform);
void reflectPlaneYXMat4(Mat4 matrixToTransform);

void translate2DMat4(Mat4 matrixToTransform, const float x, const float y);
void translate3D(Mat4 matrixToTransform, const float x, const float y, const float z);

void shearPlaneYZMat4(Mat4 matrixToTransform, const float shearAmtY, const float shearAmtZ);
void shearPlaneZYMat4(Mat4 matrixToTransform, const float shearAmtY, const float shearAmtZ);

void shearPlaneZXMat4(Mat4 matrixToTransform, const float shearAmtZ, const float shearAmtX);
void shearPlaneXZMat4(Mat4 matrixToTransform, const float shearAmtZ, const float shearAmtX);

void shearPlaneXYMat4(Mat4 matrixToTransform, const float shearAmtX, const float shearAmtY);
void shearPlaneYXMat4(Mat4 matrixToTransform, const float shearAmtX, const float shearAmtY);

