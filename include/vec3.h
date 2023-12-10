#ifndef LINA_VEC3_H
#define LINA_VEC3_H

#include "shared.h"
#include "vec2.h"

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
	
	// psuedo-swizzling
	struct {
		union {
			Vec2 xy;
			Vec2 st;
		};
		float dummy0;
	};
	struct {
		float dummy1;
		Vec2 yz;
	};
} Vec3;

// constructors
Vec3 vec3(const float e1, const float e2, const float e3);
Vec3 vec3F(const float e1, const float e2, const float e3); // helper
Vec3 vec3V(const Vec2 vec, const float e3);
Vec3 vec3Fill(const float fillValue);
Vec3 vec3Zero();

// operations
Vec3 vec3Add(const Vec3 left, const Vec3 right);
Vec3 vec3Sub(const Vec3 left, const Vec3 right);
float vec3Dot(const Vec3 left, const Vec3 right);
Vec3 vec3Cross(const Vec3 left, const Vec3 right);
Vec3 vec3Negated(const Vec3 vec);
Vec3 vec3Scaled(const Vec3 vec, const float scalar);
Vec3 vec3Rotated(const Vec3 vec, const float radians);
Vec3 vec3Normalized(const Vec3 vec);

// vector info
float vec3Length(const Vec3 vec);

#endif // LINA_VEC3_H
