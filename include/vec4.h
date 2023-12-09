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

// constructors
Vec4 vec4(const float e1, const float e2, const float e3, const float e4);
Vec4 vec4F(const float e1, const float e2, const float e3, const float e4); // helper
Vec4 vec4V(const Vec3 vec, const float e4);
Vec4 vec4Fill(const float fillValue);
Vec4 vec4Zero();

// operations
Vec4 vec4Add(const Vec4 left, const Vec4 right);
Vec4 vec4Sub(const Vec4 left, const Vec4 right);
Vec4 vec4Dot(const Vec4 left, const Vec4 right);
Vec4 vec4Cross(const Vec4 left, const Vec4 right);
Vec4 vec4Negated(const Vec4 vec);
Vec4 vec4Scaled(const Vec4 vec, const float scalar);
Vec4 vec4Rotated(const Vec4 vec, const float radians);
Vec4 vec4Normalized(const Vec4 vec);

// vector info
float vec4Length(const Vec4 vec);

#endif // LINA_VEC4_H
