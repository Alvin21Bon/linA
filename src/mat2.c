#include "../include/lina.h"

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
	memset(zeroedMatrix, 0, sizeof(float) * MAT2_NUM_OF_ELEMENTS);
}
void copyMat2(const Mat2 inputMatrix, Mat2 copyIntoMatrix)
{
	fillMat2(inputMatrix[0], inputMatrix[1], copyIntoMatrix);
}
void fillIdentityMat2(Mat2 outputMatrix)
{
	zeroMat2(outputMatrix);

	for (int diagonalPos = 0; diagonalPos < MAT2_NUM_OF_COLUMNS && diagonalPos < MAT2_NUM_OF_ROWS; diagonalPos++)
	{
		outputMatrix[diagonalPos][diagonalPos] = 1;
	}
}
void transposeMat2(Mat2 transposedMatrix)
{
	fillMat2WithFloats(transposedMatrix[0][0], transposedMatrix[0][1], 
			   transposedMatrix[1][0], transposedMatrix[1][1],
			   transposedMatrix);
}

void multMat2Vec(const Mat2 transformedSpace, Vec2 transformedVector)
{
	Mat2 tempCopyOfMatrix;
	copyMat2(transformedSpace, tempCopyOfMatrix);

	for (int columnIndex = 0; columnIndex < MAT2_NUM_OF_COLUMNS; columnIndex++)
	{
		scaleVec2(transformedVector[columnIndex], tempCopyOfMatrix[columnIndex]);
	}

	sumOfVec2(transformedVector, 2, tempCopyOfMatrix[0], tempCopyOfMatrix[1]);
}

void productOfMat2Vecs(const Mat2 transformedSpace, const size_t numOfVectors, ...)
{
	int argIndex;
	va_list argInfo;

	va_start(argInfo, numOfVectors);

	for (argIndex = 0; argIndex < numOfVectors; argIndex++)
	{
		multMat2Vec(transformedSpace, va_arg(argInfo, float*));
	}

	va_end(argInfo);
}

void multMat2Mat(const Mat2 transformedSpace, Mat2 transformedMatrix)
{
	productOfMat2Vecs(transformedSpace, 2, transformedMatrix[0], transformedMatrix[1]);
}

void printMat2(const Mat2 matrixToPrint)
{
	for (int rowIndex = 0; rowIndex < MAT2_NUM_OF_ROWS; rowIndex++)
	{
		printf("| ");

		for (int columnIndex = 0; columnIndex < MAT2_NUM_OF_COLUMNS; columnIndex++)
		{
			printf("%f ", matrixToPrint[columnIndex][rowIndex]);
		}

		printf("|\n");
	}
}
