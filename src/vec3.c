#include "../include/aglm.h"

void fillVec3(const float x, const float y, const float z, Vec3 outputVector)
{
	outputVector[0] = x;
	outputVector[1] = y;
	outputVector[2] = z;
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

void sumOfVec3(Vec3 outputVector, const size_t numOfOperands, ...);
void differenceOfVec3(Vec3 outputVector, const size_t numOfOperands, ...);

void scaleVec3(const float scalar, const Vec3 inputVector, Vec3 outputVector);
void negVec3(const Vec3 inputVector, Vec3 outputVector);

