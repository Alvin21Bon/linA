#ifndef AGLM_VEC3_H
#define AGLM_VEC3_H

#include "shared.h"
#include "vec4.h" // for the implementation of the sumOfVec function

typedef float Vec3[3];

void fillVec3(const float x, const float y, const float z, Vec3 outputVector);

void addVec3(const Vec3 vectorA, const Vec3 vectorB, Vec3 outputVector);
void subtractVec3(const Vec3 vectorA, const Vec3 vectorB, Vec3 outputVector);

/*
 * These functions allow for a variable amount of vectors to be added or subtracted together. 
 * To use the function, simply add as many vector arguments as you want, while specifying the
 * number of vectors.
*/
void sumOfVec3(Vec3 outputVector, const size_t numOfOperands, ...);
void differenceOfVec3(Vec3 outputVector, const size_t numOfOperands, ...);

void scaleVec3(const float scalar, const Vec3 inputVector, Vec3 outputVector);
void negVec3(const Vec3 inputVector, Vec3 outputVector);

#endif // AGLM_VEC3_H
