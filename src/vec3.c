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

	va_start(argInfo, numOfOperands);

	zeroVec3(outputVector);
	for (argIndex = 0; argIndex < numOfOperands; argIndex++)
	{
		addVec3(outputVector, va_arg(argInfo, Vec3), outputVector);
	}

	va_end(argInfo);
}
void differenceOfVec3(Vec3 outputVector, const size_t numOfOperands, ...)
{
	int argIndex;
	va_list argInfo;

	va_start(argInfo, numOfOperands);

	// copy first argument/operand so that subtraction is not applied
	copyVec3(va_arg(argInfo, Vec3), outputVector); 
	for (argIndex = 1; argIndex < numOfOperands; argIndex++)
	{
		subtractVec3(outputVector, va_arg(argInfo, Vec3), outputVector);
	}

	va_end(argInfo);
}

void scaleVec3(const float scalar, const Vec3 inputVector, Vec3 outputVector)
{
	outputVector[0] = scalar * inputVector[0];
	outputVector[1] = scalar * inputVector[1];
	outputVector[2] = scalar * inputVector[2];
}
void negVec3(const Vec3 inputVector, Vec3 outputVector)
{
	scaleVec3(-1, inputVector, outputVector);
}

