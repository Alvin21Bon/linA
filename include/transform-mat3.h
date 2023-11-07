#ifndef AGLM_TRANSFORM_MAT3_H
#define AGLM_TRANSFORM_MAT3_H

#include "shared.h"
#include "mat3.h"

/******************************************************************************
* SCALING FUNCTIONS
******************************************************************************/

//
void scaleXMat3(Mat3 matrixToTransform, const float scaleAmt);
void scaleYMat3(Mat3 matrixToTransform, const float scaleAmt);
void scaleZMat3(Mat3 matrixToTransform, const float scaleAmt);

/******************************************************************************
* ROTATING FUNCTIONS
*
* NOTE: All of these functions use radians
******************************************************************************/

//
void rotateXMat3(Mat3 matrixToTransform, const double angleInRadians);
void rotateYMat3(Mat3 matrixToTransform, const double angleInRadians);
void rotateZMat3(Mat3 matrixToTransform, const double angleInRadians);

void pitchMat3(Mat3 matrixToTransform, const double angleInRadians);
void yawMat3(Mat3 matrixToTransform, const double angleInRadians);
void rollMat3(Mat3 matrixToTransform, const double angleInRadians);

/******************************************************************************
* REFLECTING FUNCTIONS
******************************************************************************/

//
void reflectPlaneYZMat3(Mat3 matrixToTransform); 
void reflectPlaneZYMat3(Mat3 matrixToTransform);

void reflectPlaneZXMat3(Mat3 matrixToTransform);
void reflectPlaneXZMat3(Mat3 matrixToTransform);

void reflectPlaneXYMat3(Mat3 matrixToTransform);
void reflectPlaneYXMat3(Mat3 matrixToTransform);

/******************************************************************************
* TRANSLATING FUNCTIONS
******************************************************************************/

//
void translate2DMat3(Mat3 matrixToTransform, const float x, const float y);

/******************************************************************************
* SHEARING FUNCTIONS
******************************************************************************/

//
void shearPlaneYZMat3(Mat3 matrixToTransform, const float shearAmt);
void shearPlaneZYMat3(Mat3 matrixToTransform, const float shearAmt);

void shearPlaneZXMat3(Mat3 matrixToTransform, const float shearAmt);
void shearPlaneXZMat3(Mat3 matrixToTransform, const float shearAmt);

void shearPlaneXYMat3(Mat3 matrixToTransform, const float shearAmt);
void shearPlaneYXMat3(Mat3 matrixToTransform, const float shearAmt);

#endif // AGLM_TRANSFORM_MAT3_H
