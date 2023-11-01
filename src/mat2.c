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

void zeroMat2(Mat2 zeroedMatrix)
{
	int numOfElementsInMat2 = 4;

	memset(zeroedMatrix, 0, sizeof(float) * numOfElementsInMat2);
}
void copyMat2(const Mat2 inputMatrix, Mat2 copyIntoMatrix)
{
	fillMat2(inputMatrix[0], inputMatrix[1], copyIntoMatrix);
}
void fillIdentityMat2(Mat2 outputMatrix)
{
	zeroMat2(outputMatrix);
	outputMatrix[0][0] = 1;
	outputMatrix[1][1] = 1;
}
void transposeMat2(Mat2 transposedMatrix)
{
	fillMat2WithFloats(transposedMatrix[0][0], transposedMatrix[0][1], 
			   transposedMatrix[1][0], transposedMatrix[1][1],
			   transposedMatrix);
}

void multMat2Vec(const Mat2 transformedSpace, Vec2 transformedVector)
{
	// NOTE: might need to add a for loop here for better readability or adaptability

	Mat2 tempCopyOfMatrix;
	copyMat2(transformedSpace, tempCopyOfMatrix);
}

void productOfMat2Vecs(const Mat2 transformedSpace, const size_t numOfVectors, ...);

void multMat2Mat(const Mat2 transformedSpace, Mat2 transformedMatrix);

void printMat2(const Mat2 matrixToPrint);
