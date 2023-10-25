#include "../include/aglm.h"

void fillVec2(const float x, const float y, Vec2 outputVector)
{
	outputVector[0] = x;
	outputVector[1] = y;
}

void addVec2(const Vec2 vectorA, const Vec2 vectorB, Vec2 outputVector);
void subtractVec2(const Vec2 vectorA, const Vec2 vectorB, Vec2 outputVector);

void sumOfVec2(Vec2 outputVector, const size_t numOfOperands, ...);
void differenceOfVec2(Vec2 outputVector, const size_t numOfOperands, ...);

void scaleVec2(const float scalar, const Vec2 inputVector, Vec2 ouputVector);
void negVec2(const Vec2 inputVector, Vec2 outputVector);

