#include "../include/aglm.h"

void fillVec4(const float x, const float y, const float z, const float w, Vec4 outputVector)
{
	outputVector[0] = x;
	outputVector[1] = y;
	outputVector[2] = z;
	outputVector[3] = w;
}
void zeroVec4(Vec4 zeroedVector)
{
	fillVec4(0, 0, 0, 0, zeroedVector);
}

void addVec4(const Vec4 vectorA, const Vec4 vectorB, Vec4 outputVector)
{
	outputVector[0] = vectorA[0] + vectorB[0];
	outputVector[1] = vectorA[1] + vectorB[1];
	outputVector[2] = vectorA[2] + vectorB[2];
	outputVector[3] = vectorA[3] + vectorB[3];
}
void subtractVec4(const Vec4 vectorA, const Vec4 vectorB, Vec4 outputVector)
{
	outputVector[0] = vectorA[0] - vectorB[0];
	outputVector[1] = vectorA[1] - vectorB[1];
	outputVector[2] = vectorA[2] - vectorB[2];
	outputVector[3] = vectorA[3] - vectorB[3];
}

void sumOfVec4(Vec4 outputVector, const size_t numOfOperands, ...)
{
	int argIndex;
	va_list argInfo;

	va_start(argInfo, numOfOperands);

	zeroVec4(outputVector);
	for (argIndex = 0; argIndex < numOfOperands; argIndex++)
	{
		addVec4(outputVector, va_arg(argInfo, Vec4), outputVector);
	}

	va_end(argInfo);
}
void differenceOfVec4(Vec4 outputVector, const size_t numOfOperands, ...);

void scaleVec4(const float scalar, const Vec4 inputVector, Vec4 outputVector)
{
	outputVector[0] = scalar * inputVector[0];
	outputVector[1] = scalar * inputVector[1];
	outputVector[2] = scalar * inputVector[2];
	outputVector[3] = scalar * inputVector[3];
}
void negVec4(const Vec4 inputVector, Vec4 outputVector)
{
	scaleVec4(-1, inputVector, outputVector);
}
