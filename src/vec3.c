#include "../include/aglm.h"

void fillVec3(const float x, const float y, const float z, Vec3 outputVector)
{
	outputVector[0] = x;
	outputVector[1] = y;
	outputVector[2] = z;
}
void zeroVec3(Vec3 zeroedVector)
{
	fillVec3(0, 0, 0, zeroedVector);
}
void copyVec3(const Vec3 inputVector, Vec3 copyIntoVector)
{
	fillVec3(inputVector[0], inputVector[1], inputVector[2], copyIntoVector);
}

void addVec3(const Vec3 vectorA, const Vec3 vectorB, Vec3 outputVector)
{
	outputVector[0] = vectorA[0] + vectorB[0];
	outputVector[1] = vectorA[1] + vectorB[1];
	outputVector[2] = vectorA[2] + vectorB[2];
}
void subtractVec3(const Vec3 vectorA, const Vec3 vectorB, Vec3 outputVector)
{
	outputVector[0] = vectorA[0] - vectorB[0];
	outputVector[1] = vectorA[1] - vectorB[1];
	outputVector[2] = vectorA[2] - vectorB[2];
}

void sumOfVec3(Vec3 outputVector, const size_t numOfOperands, ...)
{
	int argIndex;
	va_list argInfo;
	Vec3 tempOutputVector; // to support outputVector being one of the operands

	va_start(argInfo, numOfOperands);

	zeroVec3(tempOutputVector);
	for (argIndex = 0; argIndex < numOfOperands; argIndex++)
	{
		addVec3(tempOutputVector, va_arg(argInfo, float*), tempOutputVector);
	}

	va_end(argInfo);

	copyVec3(tempOutputVector, outputVector);
}
void differenceOfVec3(Vec3 outputVector, const size_t numOfOperands, ...)
{
	int argIndex;
	va_list argInfo;
	Vec3 tempOutputVector; // to support outputVector being one of the operands

	va_start(argInfo, numOfOperands);

	// copy first argument/operand so that subtraction is not applied
	copyVec3(va_arg(argInfo, float*), tempOutputVector); 
	for (argIndex = 1; argIndex < numOfOperands; argIndex++)
	{
		subtractVec3(tempOutputVector, va_arg(argInfo, float*), tempOutputVector);
	}

	va_end(argInfo);

	copyVec3(tempOutputVector, outputVector);
}

void scaleVec3(const float scalar, Vec3 scaledVector)
{
	scaledVector[0] = scalar * scaledVector[0];
	scaledVector[1] = scalar * scaledVector[1];
	scaledVector[2] = scalar * scaledVector[2];
}
void negVec3(Vec3 negatedVector)
{
	scaleVec3(-1, negatedVector);
}

