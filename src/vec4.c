#include "../include/aglm.h"

void fillVec4(const float x, const float y, const float z, const float w, Vec4 outputVector)
{
	outputVector[0] = x;
	outputVector[1] = y;
	outputVector[2] = z;
	outputVector[3] = w;
}

void addVec4(const Vec4 vectorA, const Vec4 vectorB, Vec4 outputVector);
void subtractVec4(const Vec4 vectorA, const Vec4 vectorB, Vec4 outputVector);

void sumOfVec4(Vec4 outputVector, const size_t numOfOperands, ...);
void differenceOfVec4(Vec4 outputVector, const size_t numOfOperands, ...);

void scaleVec4(const float scalar, const Vec4 inputVector, Vec4 outputVector);
void negVec4(const Vec4 inputVector, Vec4 outputVector);
