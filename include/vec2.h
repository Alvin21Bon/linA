#ifndef AGLM_VEC2_H
#define AGLM_VEC2_H

#include "shared.h"

typedef float Vec2[2];

void fillVec2(const float x, const float y, Vec2 outputVector);
void zeroVec2(Vec2 zeroedVector);
void copyVec2(const Vec2 inputVector, Vec2 copyIntoVector);

void addVec2(const Vec2 vectorA, const Vec2 vectorB, Vec2 outputVector);
void subtractVec2(const Vec2 vectorA, const Vec2 vectorB, Vec2 outputVector);

/*
 * These functions allow for a variable amount of vectors to be added or subtracted together. 
 * To use the function, simply add as many vector arguments as you want, while specifying the
 * number of vectors.
*/
void sumOfVec2(Vec2 outputVector, const size_t numOfOperands, ...);
void differenceOfVec2(Vec2 outputVector, const size_t numOfOperands, ...);

void scaleVec2(const float scalar, Vec2 scaledVector);
void negVec2(Vec2 negatedVector);

#endif // AGLM_VEC2_H
