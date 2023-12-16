#ifndef LINA_VEC_TYPES_H
#define LINA_VEC_TYPES_H

typedef union Vec2 {
	float elements[2];

	struct {
		float x, y;
	};	
	struct {
		float s, t;
	};	
	struct {
		float width, height;
	};
} Vec2;

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
	struct {
		float dummy7;
		union {
			Vec3 yzw;
		};
	};
} Vec4;

#endif // LINA_VEC_TYPES_H
