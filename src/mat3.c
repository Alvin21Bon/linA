#include "../include/linA.h"

void fillMat3(const Vec3 column0, const Vec3 column1, const Vec3 column2, Mat3 outputMatrix)
{
	copyVec3(column0, outputMatrix[0]);
	copyVec3(column1, outputMatrix[1]);
	copyVec3(column2, outputMatrix[2]);
}

void fillMat3WithFloats(const float col0row0, const float col1row0, const float col2row0, 
			const float col0row1, const float col1row1, const float col2row1,
			const float col0row2, const float col1row2, const float col2row2,
			Mat3 outputMatrix)
{
	Vec3 column0, column1, column2;
	fillVec3(col0row0, col0row1, col0row2, column0);
	fillVec3(col1row0, col1row1, col1row2, column1);
	fillVec3(col2row0, col2row1, col2row2, column2);

	fillMat3(column0, column1, column2, outputMatrix);
}

void zeroMat3(Mat3 zeroedMatrix)
{
	memset(zeroedMatrix, 0, sizeof(float) * MAT3_NUM_OF_ELEMENTS);
}
void copyMat3(const Mat3 inputMatrix, Mat3 copyIntoMatrix)
{
	fillMat3(inputMatrix[0], inputMatrix[1], inputMatrix[2], copyIntoMatrix);
}
void fillIdentityMat3(Mat3 outputMatrix)
{
	zeroMat3(outputMatrix);

	for (int diagonalPos = 0; diagonalPos < MAT3_NUM_OF_COLUMNS && diagonalPos < MAT3_NUM_OF_ROWS; diagonalPos++)
	{
		outputMatrix[diagonalPos][diagonalPos] = 1;
	}
}
void transposeMat3(Mat3 transposedMatrix)
{
	fillMat3WithFloats(transposedMatrix[0][0], transposedMatrix[0][1], transposedMatrix[0][2],
			   transposedMatrix[1][0], transposedMatrix[1][1], transposedMatrix[1][2],
			   transposedMatrix[2][0], transposedMatrix[2][1], transposedMatrix[2][2],
			   transposedMatrix);
}

void multMat3Vec(const Mat3 transformedSpace, Vec3 transformedVector)
{
	Mat3 tempCopyOfMatrix;
	copyMat3(transformedSpace, tempCopyOfMatrix);

	for (int columnIndex = 0; columnIndex < MAT3_NUM_OF_COLUMNS; columnIndex++)
	{
		scaleVec3(transformedVector[columnIndex], tempCopyOfMatrix[columnIndex]);
	}

	sumOfVec3(transformedVector, 3, tempCopyOfMatrix[0], tempCopyOfMatrix[1], tempCopyOfMatrix[2]);
}

void productOfMat3Vecs(const Mat3 transformedSpace, const size_t numOfVectors, ...)
{
	int argIndex;
	va_list argInfo;

	va_start(argInfo, numOfVectors);

	for (argIndex = 0; argIndex < numOfVectors; argIndex++)
	{
		multMat3Vec(transformedSpace, va_arg(argInfo, float*));
	}

	va_end(argInfo);
}

void multMat3Mat(const Mat3 transformedSpace, Mat3 transformedMatrix)
{
	productOfMat3Vecs(transformedSpace, 3, transformedMatrix[0], transformedMatrix[1], transformedMatrix[2]);
}

void printMat3(const Mat3 matrixToPrint)
{
	for (int rowIndex = 0; rowIndex < MAT3_NUM_OF_ROWS; rowIndex++)
	{
		printf("| ");

		for (int columnIndex = 0; columnIndex < MAT3_NUM_OF_COLUMNS; columnIndex++)
		{
			printf("%f ", matrixToPrint[columnIndex][rowIndex]);
		}

		printf("|\n");
	}
}
