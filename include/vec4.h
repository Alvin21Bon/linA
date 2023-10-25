#ifndef AGLM_VEC4_H
#define AGLM_VEC4_H

#include "shared.h"

typedef float Vec4[4];

void fillVec4(const float x, const float y, const float z, const float w, Vec4 outputVector);

void addVec4(const Vec4 vectorA, const Vec4 vectorB, Vec4 outputVector);
void subtractVec4(const Vec4 vectorA, const Vec4 vectorB, Vec4 outputVector);

/*
 * These functions allow for a variable amount of vectors to be added or subtracted together. 
 * To use the function, simply add as many vector arguments as you want, while specifying the
 * number of vectors.
*/
void sumOfVec4(Vec4 outputVector, const size_t numOfOperands, ...);
void differenceOfVec4(Vec4 outputVector, const size_t numOfOperands, ...);

void scaleVec4(const float scalar, const Vec4 inputVector, Vec4 ouputVector);
void negVec4(const Vec4 inputVector, Vec4 outputVector);

#endif // AGLM_VEC4_H
