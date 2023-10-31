#include "../include/aglm.h"

void fillMat2(const Vec2 column1, const Vec2 column2, Mat2 outputMatrix);

void fillMat2WithFloats(const float col1row1, const float col2row1, 
			const float col1row2, const float col2row2,
			Mat2 outputMatrix);

void zeroMat2(Mat2 zeroedMatrix);
void copyMat2(const Mat2 inputMatrix, Mat2 copyIntoMatrix);
void fillIdentityMat2(Mat2 outputMatrix);
void transposeMat2(Mat2 transposedMatrix);

void multMat2Vec(const Mat2 transformedSpace, Vec2 transformedVector);

void productOfMat2Vecs(const Mat2 transformedSpace, const size_t numOfVectors, ...);

void multMat2Mat(const Mat2 transformedSpace, Mat2 transformedMatrix);

void printMat2(const Mat2 matrixToPrint);
