#include "../include/aglm.h"

void fillMat2(const Vec2 column0, const Vec2 column1, Mat2 outputMatrix)
{
	copyVec2(column0, outputMatrix[0]);
	copyVec2(column1, outputMatrix[1]);
}

void fillMat2WithFloats(const float col0row0, const float col1row0, 
			const float col0row1, const float col1row1,
			Mat2 outputMatrix)
{
	Vec2 column0, column1;
	fillVec2(col0row0, col0row1, column0);
	fillVec2(col1row0, col1row1, column1);

	fillMat2(column0, column1, outputMatrix);
}

void zeroMat2(Mat2 zeroedMatrix);
void copyMat2(const Mat2 inputMatrix, Mat2 copyIntoMatrix);
void fillIdentityMat2(Mat2 outputMatrix);
void transposeMat2(Mat2 transposedMatrix);

void multMat2Vec(const Mat2 transformedSpace, Vec2 transformedVector);

void productOfMat2Vecs(const Mat2 transformedSpace, const size_t numOfVectors, ...);

void multMat2Mat(const Mat2 transformedSpace, Mat2 transformedMatrix);

void printMat2(const Mat2 matrixToPrint);
