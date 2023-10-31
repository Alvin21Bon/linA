#include "../include/aglm.h"

void fillMat4(const Vec4 column1, const Vec4 column2, const Vec4 column3, const Vec4 column4, Mat4 outputMatrix);

void fillMat4WithFloats(const float col1row1, const float col2row1, const float col3row1, const float col4row1, 
			const float col1row2, const float col2row2, const float col3row2, const float col4row2,
			const float col1row3, const float col2row3, const float col3row3, const float col4row3,
			const float col1row4, const float col2row4, const float col3row4, const float col4row4,
			Mat4 outputMatrix);

void zeroMat4(Mat4 zeroedMatrix);
void copyMat4(const Mat4 inputMatrix, Mat4 copyIntoMatrix);
void fillIdentityMat4(Mat4 outputMatrix);
void transposeMat4(Mat4 transposedMatrix);

void multMat4Vec(const Mat4 transformedSpace, Vec4 transformedVector);

void productOfMat4Vecs(const Mat4 transformedSpace, const size_t numOfVectors, ...);

void multMat4Mat(const Mat4 transformedSpace, Mat4 transformedMatrix);

void printMat4(const Mat4 matrixToPrint);
