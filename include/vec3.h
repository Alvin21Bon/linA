#ifndef LINA_VEC3_H
#define LINA_VEC3_H

#include "shared.h"

typedef union Vec3 {
	float elements[3];

	struct {
		float x, y, z;	
	};
	struct {
		float r, g, b;
	};
	struct {
		float s, t, p;
	};
} Vec3;

void fillVec3(const float x, const float y, const float z, Vec3 outputVector);
void zeroVec3(Vec3 zeroedVector);
void copyVec3(const Vec3 inputVector, Vec3 copyIntoVector);

void addVec3(const Vec3 vectorA, const Vec3 vectorB, Vec3 outputVector);
void subtractVec3(const Vec3 vectorA, const Vec3 vectorB, Vec3 outputVector);

/*
 * These functions allow for a variable amount of vectors to be added or subtracted together. 
 * To use the function, simply add as many vector arguments as you want, while specifying the
 * number of vectors.
*/
void sumOfVec3(Vec3 outputVector, const size_t numOfOperands, ...);
void differenceOfVec3(Vec3 outputVector, const size_t numOfOperands, ...);

void scaleVec3(const float scalar, Vec3 scaledVector);
void negVec3(Vec3 negatedVector);

#endif // LINA_VEC3_H
