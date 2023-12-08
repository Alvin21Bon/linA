#ifndef LINA_MAT4_H
#define LINA_MAT4_H

#include "shared.h"
#include "vec4.h"

#define MAT4_NUM_OF_COLUMNS 4
#define MAT4_NUM_OF_ROWS 4
#define MAT4_NUM_OF_ELEMENTS (MAT4_NUM_OF_COLUMNS * MAT4_NUM_OF_ROWS) 

typedef Vec4 Mat4[4];

void fillMat4(const Vec4 column0, const Vec4 column1, const Vec4 column2, const Vec4 column3, Mat4 outputMatrix);

// Arguments are in ROW-MAJOR order. Remember to transpose resulting matrix.
void fillMat4WithFloats(const float col0row0, const float col1row0, const float col2row0, const float col3row0, 
			const float col0row1, const float col1row1, const float col2row1, const float col3row1,
			const float col0row2, const float col1row2, const float col2row2, const float col3row2,
			const float col0row3, const float col1row3, const float col2row3, const float col3row3,
			Mat4 outputMatrix);

void zeroMat4(Mat4 zeroedMatrix);
void copyMat4(const Mat4 inputMatrix, Mat4 copyIntoMatrix);
void fillIdentityMat4(Mat4 outputMatrix);
void transposeMat4(Mat4 transposedMatrix);

void multMat4Vec(const Mat4 transformedSpace, Vec4 transformedVector);

/*
 * This function allows for a variable amount of vectors to be multiplied. To use the
 * function, simply add as many vector arguments as you want, while specifying the
 * number of vectors.
*/
void productOfMat4Vecs(const Mat4 transformedSpace, const size_t numOfVectors, ...);

void multMat4Mat(const Mat4 transformedSpace, Mat4 transformedMatrix);

void printMat4(const Mat4 matrixToPrint);

#endif // LINA_MAT4_H
