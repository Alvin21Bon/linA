#include "../include/aglm.h"

void scaleXMat2(Mat2 matrixToTransform, const float scaleAmt);
void scaleYMat2(Mat2 matrixToTransform, const float scaleAmt);

void rotateXMat2(Mat2 matrixToTransform, const double angleInRadians);
void rotateYMat2(Mat2 matrixToTransform, const double angleInRadians);
void rotateZMat2(Mat2 matrixToTransform, const double angleInRadians);

void pitchMat2(Mat2 matrixToTransform, const double angleInRadians);
void yawMat2(Mat2 matrixToTransform, const double angleInRadians);
void rollMat2(Mat2 matrixToTransform, const double angleInRadians);

void reflectPlaneYZMat2(Mat2 matrixToTransform); 
void reflectPlaneZYMat2(Mat2 matrixToTransform);

void reflectPlaneZXMat2(Mat2 matrixToTransform);
void reflectPlaneXZMat2(Mat2 matrixToTransform);

void reflectX(Mat2 matrixToTransform);
void reflectY(Mat2 matrixToTransform);

void shearPlaneYZMat2(Mat2 matrixToTransform, const float shearAmt);
void shearPlaneZYMat2(Mat2 matrixToTransform, const float shearAmt);

void shearPlaneZXMat2(Mat2 matrixToTransform, const float shearAmt);
void shearPlaneXZMat2(Mat2 matrixToTransform, const float shearAmt);

void shearX(Mat2 matrixToTransform, const float shearAmt);
void shearY(Mat2 matrixToTransform, const float shearAmt);
