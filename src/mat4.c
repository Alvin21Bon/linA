#include "../include/lina.h"

void fillMat4(const Vec4 column0, const Vec4 column1, const Vec4 column2, const Vec4 column3, Mat4 outputMatrix)
{
	copyVec4(column0, outputMatrix[0]);
	copyVec4(column1, outputMatrix[1]);
	copyVec4(column2, outputMatrix[2]);
	copyVec4(column3, outputMatrix[3]);
}

void fillMat4WithFloats(const float col0row0, const float col1row0, const float col2row0, const float col3row0, 
			const float col0row1, const float col1row1, const float col2row1, const float col3row1,
			const float col0row2, const float col1row2, const float col2row2, const float col3row2,
			const float col0row3, const float col1row3, const float col2row3, const float col3row3,
			Mat4 outputMatrix)
{
	Vec4 column0, column1, column2, column3;
	fillVec4(col0row0, col0row1, col0row2, col0row3, column0);
	fillVec4(col1row0, col1row1, col1row2, col1row3, column1);
	fillVec4(col2row0, col2row1, col2row2, col2row3, column2);
	fillVec4(col3row0, col3row1, col3row2, col3row3, column3);

	fillMat4(column0, column1, column2, column3, outputMatrix);
}

void zeroMat4(Mat4 zeroedMatrix)
{
	memset(zeroedMatrix, 0, sizeof(float) * MAT4_NUM_OF_ELEMENTS);
}
void copyMat4(const Mat4 inputMatrix, Mat4 copyIntoMatrix)
{
	fillMat4(inputMatrix[0], inputMatrix[1], inputMatrix[2], inputMatrix[3], copyIntoMatrix);
}
void fillIdentityMat4(Mat4 outputMatrix)
{
	zeroMat4(outputMatrix);

	for (int diagonalPos = 0; diagonalPos < MAT4_NUM_OF_COLUMNS && diagonalPos < MAT4_NUM_OF_ROWS; diagonalPos++)
	{
		outputMatrix[diagonalPos][diagonalPos] = 1;
	}
}
void transposeMat4(Mat4 transposedMatrix)
{
	fillMat4WithFloats(transposedMatrix[0][0], transposedMatrix[0][1], transposedMatrix[0][2], transposedMatrix[0][3],
			   transposedMatrix[1][0], transposedMatrix[1][1], transposedMatrix[1][2], transposedMatrix[1][3],
			   transposedMatrix[2][0], transposedMatrix[2][1], transposedMatrix[2][2], transposedMatrix[2][3],
			   transposedMatrix[3][0], transposedMatrix[3][1], transposedMatrix[3][2], transposedMatrix[3][3],
			   transposedMatrix);
}

void multMat4Vec(const Mat4 transformedSpace, Vec4 transformedVector)
{
	Mat4 tempCopyOfMatrix;
	copyMat4(transformedSpace, tempCopyOfMatrix);

	for (int columnIndex = 0; columnIndex < MAT4_NUM_OF_COLUMNS; columnIndex++)
	{
		scaleVec4(transformedVector[columnIndex], tempCopyOfMatrix[columnIndex]);
	}

	sumOfVec4(transformedVector, 4, tempCopyOfMatrix[0], tempCopyOfMatrix[1], tempCopyOfMatrix[2], tempCopyOfMatrix[3]);
}

void productOfMat4Vecs(const Mat4 transformedSpace, const size_t numOfVectors, ...)
{
	int argIndex;
	va_list argInfo;

	va_start(argInfo, numOfVectors);

	for (argIndex = 0; argIndex < numOfVectors; argIndex++)
	{
		multMat4Vec(transformedSpace, va_arg(argInfo, float*));
	}

	va_end(argInfo);
}

void multMat4Mat(const Mat4 transformedSpace, Mat4 transformedMatrix)
{
	productOfMat4Vecs(transformedSpace, 4, transformedMatrix[0], transformedMatrix[1], 
					       transformedMatrix[2], transformedMatrix[3]);
}

void printMat4(const Mat4 matrixToPrint)
{
	for (int rowIndex = 0; rowIndex < MAT4_NUM_OF_ROWS; rowIndex++)
	{
		printf("| ");

		for (int columnIndex = 0; columnIndex < MAT4_NUM_OF_COLUMNS; columnIndex++)
		{
			printf("%f ", matrixToPrint[columnIndex][rowIndex]);
		}

		printf("|\n");
	}
}
