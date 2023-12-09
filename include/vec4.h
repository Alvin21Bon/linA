#ifndef LINA_VEC4_H
#define LINA_VEC4_H

#include "shared.h"
#include "vec2.h"
#include "vec3.h"

typedef union Vec4 {
	float elements[4];

	struct {
		float x, y, z, w;
	};
	struct {
		float r, g, b, a;
	};
	struct {
		float s, t, p, q;
	};
	
	// vec2 swizzling
	struct {
		union {
			Vec2 xy;
			Vec2 st;
		};
		float dummy0;
		float dummy1;
	};
	struct {
		float dummy2;
		Vec2 yz;
		float dummy3;
	};
	struct {
		float dummy4;
		float dummy5;
		Vec2 zw;
	};

	// vec3 swizzling
	struct {
		union {
			Vec3 xyz, rgb, stp;
		};
		float dummy6;
	};
} Vec4;

void fillVec4(const float x, const float y, const float z, const float w, Vec4 outputVector);
void zeroVec4(Vec4 zeroedVector);
void copyVec4(const Vec4 inputVector, Vec4 copyIntoVector);

void addVec4(const Vec4 vectorA, const Vec4 vectorB, Vec4 outputVector);
void subtractVec4(const Vec4 vectorA, const Vec4 vectorB, Vec4 outputVector);

/*
 * These functions allow for a variable amount of vectors to be added or subtracted together. 
 * To use the function, simply add as many vector arguments as you want, while specifying the
 * number of vectors.
*/
void sumOfVec4(Vec4 outputVector, const size_t numOfOperands, ...);
void differenceOfVec4(Vec4 outputVector, const size_t numOfOperands, ...);

void scaleVec4(const float scalar, Vec4 scaledVector);
void negVec4(Vec4 negatedVector);

#endif // LINA_VEC4_H
