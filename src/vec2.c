#include "../include/aglm.h"

void fillVec2(const float x, const float y, Vec2 outputVector)
{
	outputVector[0] = x;
	outputVector[1] = y;
}
void zeroVec2(Vec2 zeroedVector)
{
	fillVec2(0, 0, zeroedVector);
}
void copyVec2(const Vec2 inputVector, Vec2 copyIntoVector)
{
	fillVec2(inputVector[0], inputVector[1], copyIntoVector);
}

void addVec2(const Vec2 vectorA, const Vec2 vectorB, Vec2 outputVector)
{
	outputVector[0] = vectorA[0] + vectorB[0];
	outputVector[1] = vectorA[1] + vectorB[1];
}
void subtractVec2(const Vec2 vectorA, const Vec2 vectorB, Vec2 outputVector)
{
	outputVector[0] = vectorA[0] - vectorB[0];
	outputVector[1] = vectorA[1] - vectorB[1];
}

void sumOfVec2(Vec2 outputVector, const size_t numOfOperands, ...)
{
	int argIndex;
	va_list argInfo;

	va_start(argInfo, numOfOperands);

	zeroVec2(outputVector);
	for (argIndex = 0; argIndex < numOfOperands; argIndex++)
	{
		addVec2(outputVector, va_arg(argInfo, float*), outputVector);
	}

	va_end(argInfo);
}
void differenceOfVec2(Vec2 outputVector, const size_t numOfOperands, ...)
{
	int argIndex;
	va_list argInfo;

	va_start(argInfo, numOfOperands);

	// copy first argument/operand so that subtraction is not applied
	copyVec2(va_arg(argInfo, float*), outputVector); 
	for (argIndex = 1; argIndex < numOfOperands; argIndex++)
	{
		subtractVec2(outputVector, va_arg(argInfo, float*), outputVector);
	}

	va_end(argInfo);
}

void scaleVec2(const float scalar, const Vec2 inputVector, Vec2 outputVector)
{
	outputVector[0] = scalar * inputVector[0];
	outputVector[1] = scalar * inputVector[1];
}
void negVec2(const Vec2 inputVector, Vec2 outputVector)
{
	scaleVec2(-1, inputVector, outputVector);
}

