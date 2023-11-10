#ifndef AGLM_TRANSFORM_MAT2_H
#define AGLM_TRANSFORM_MAT2_H

#include "shared.h"
#include "mat2.h"

/******************************************************************************
* SCALING FUNCTIONS
******************************************************************************/

//
void scaleXMat2(Mat2 matrixToTransform, const float scaleAmt);
void scaleYMat2(Mat2 matrixToTransform, const float scaleAmt);

/******************************************************************************
* ROTATING FUNCTIONS
*
* NOTE: All of these functions use radians
******************************************************************************/

//
void rotateXMat2(Mat2 matrixToTransform, const double angleInRadians);
void rotateYMat2(Mat2 matrixToTransform, const double angleInRadians);
void rotateZMat2(Mat2 matrixToTransform, const double angleInRadians);

void pitchMat2(Mat2 matrixToTransform, const double angleInRadians);
void yawMat2(Mat2 matrixToTransform, const double angleInRadians);
void rollMat2(Mat2 matrixToTransform, const double angleInRadians);

/******************************************************************************
* REFLECTING FUNCTIONS
******************************************************************************/

//
void reflectPlaneYZMat2(Mat2 matrixToTransform); 
void reflectPlaneZYMat2(Mat2 matrixToTransform);

void reflectPlaneZXMat2(Mat2 matrixToTransform);
void reflectPlaneXZMat2(Mat2 matrixToTransform);

void reflectX(Mat2 matrixToTransform);
void reflectY(Mat2 matrixToTransform);

/******************************************************************************
* SHEARING FUNCTIONS
******************************************************************************/

//
void shearX(Mat2 matrixToTransform, const float shearAmt);
void shearY(Mat2 matrixToTransform, const float shearAmt);

#endif // AGLM_TRANSFORM_MAT2_H
