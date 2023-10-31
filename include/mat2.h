#ifndef AGLM_MAT2_H
#define AGLM_MAT2_H

#include "shared.h"
#include "vec2.h"

typedef Vec2 Mat2[2];

void fillMat2(const Vec2 column0, const Vec2 column1, Mat2 outputMatrix);

// Arguments are in ROW-MAJOR order. Remember to transpose resulting matrix.
void fillMat2WithFloats(const float col0row0, const float col1row0, 
			const float col0row1, const float col1row1,
			Mat2 outputMatrix);

void zeroMat2(Mat2 zeroedMatrix);
void copyMat2(const Mat2 inputMatrix, Mat2 copyIntoMatrix);
void fillIdentityMat2(Mat2 outputMatrix);
void transposeMat2(Mat2 transposedMatrix);

void multMat2Vec(const Mat2 transformedSpace, Vec2 transformedVector);

/*
 * This function allows for a variable amount of vectors to be multiplied. To use the
 * function, simply add as many vector arguments as you want, while specifying the
 * number of vectors.
*/
void productOfMat2Vecs(const Mat2 transformedSpace, const size_t numOfVectors, ...);

void multMat2Mat(const Mat2 transformedSpace, Mat2 transformedMatrix);

void printMat2(const Mat2 matrixToPrint);

#endif // AGLM_MAT2_H
