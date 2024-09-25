#ifndef LINA_VEC_TYPES_H
#define LINA_VEC_TYPES_H

typedef union Vec2 Vec2;
typedef union Vec2 fVec2;
typedef union uVec2 uVec2;
typedef union iVec2 iVec2;
typedef union dVec2 dVec2;

typedef union Vec3 Vec3;
typedef union Vec3 fVec3;
typedef union uVec3 uVec3;
typedef union iVec3 iVec3;
typedef union dVec3 dVec3;

typedef union Vec4 Vec4;
typedef union Vec4 fVec4;
typedef union uVec4 uVec4;
typedef union iVec4 iVec4;
typedef union dVec4 dVec4;

union Vec2 {
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
};
union uVec2 {
	unsigned int elements[2];

	struct {
		unsigned int x, y;
	};

	struct {
		unsigned int s, t;
	};

	struct {
		unsigned int width, height;
	};
};
union iVec2 {
	int elements[2];

	struct {
		int x, y;
	};	
	struct {
		int s, t;
	};	
	struct {
		int width, height;
	};
};
union dVec2 {
	double elements[2];

	struct {
		double x, y;
	};	
	struct {
		double s, t;
	};	
	struct {
		double width, height;
	};
};

union Vec3 {
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
};
union uVec3 {
	unsigned int elements[3];

	struct {
		unsigned int x, y, z;	
	};
	struct {
		unsigned int r, g, b;
	};
	struct {
		unsigned int s, t, p;
	};
	
	// psuedo-swizzling
	struct {
		union {
			uVec2 xy;
			uVec2 st;
		};
		unsigned int dummy0;
	};
	struct {
		unsigned int dummy1;
		uVec2 yz;
	};
};
union iVec3 {
	int elements[3];

	struct {
		int x, y, z;	
	};
	struct {
		int r, g, b;
	};
	struct {
		int s, t, p;
	};
	
	// psuedo-swizzling
	struct {
		union {
			iVec2 xy;
			iVec2 st;
		};
		int dummy0;
	};
	struct {
		int dummy1;
		iVec2 yz;
	};
};
union dVec3 {
	double elements[3];

	struct {
		double x, y, z;	
	};
	struct {
		double r, g, b;
	};
	struct {
		double s, t, p;
	};
	
	// psuedo-swizzling
	struct {
		union {
			dVec2 xy;
			dVec2 st;
		};
		double dummy0;
	};
	struct {
		double dummy1;
		dVec2 yz;
	};
};

union Vec4 {
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
};
union uVec4 {
	unsigned int elements[4];

	struct {
		unsigned int x, y, z, w;
	};
	struct {
		unsigned int r, g, b, a;
	};
	struct {
		unsigned int s, t, p, q;
	};
	
	// vec2 swizzling
	struct {
		union {
			uVec2 xy;
			uVec2 st;
		};
		unsigned int dummy0;
		unsigned int dummy1;
	};
	struct {
		unsigned int dummy2;
		uVec2 yz;
		unsigned int dummy3;
	};
	struct {
		unsigned int dummy4;
		unsigned int dummy5;
		uVec2 zw;
	};

	// vec3 swizzling
	struct {
		union {
			uVec3 xyz, rgb, stp;
		};
		unsigned int dummy6;
	};
	struct {
		unsigned int dummy7;
		union {
			uVec3 yzw;
		};
	};
};
union iVec4 {
	int elements[4];

	struct {
		int x, y, z, w;
	};
	struct {
		int r, g, b, a;
	};
	struct {
		int s, t, p, q;
	};
	
	// vec2 swizzling
	struct {
		union {
			iVec2 xy;
			iVec2 st;
		};
		int dummy0;
		int dummy1;
	};
	struct {
		int dummy2;
		iVec2 yz;
		int dummy3;
	};
	struct {
		int dummy4;
		int dummy5;
		iVec2 zw;
	};

	// vec3 swizzling
	struct {
		union {
			iVec3 xyz, rgb, stp;
		};
		int dummy6;
	};
	struct {
		int dummy7;
		union {
			iVec3 yzw;
		};
	};
};
union dVec4 {
	double elements[4];

	struct {
		double x, y, z, w;
	};
	struct {
		double r, g, b, a;
	};
	struct {
		double s, t, p, q;
	};
	
	// vec2 swizzling
	struct {
		union {
			dVec2 xy;
			dVec2 st;
		};
		double dummy0;
		double dummy1;
	};
	struct {
		double dummy2;
		dVec2 yz;
		double dummy3;
	};
	struct {
		double dummy4;
		double dummy5;
		dVec2 zw;
	};

	// vec3 swizzling
	struct {
		union {
			dVec3 xyz, rgb, stp;
		};
		double dummy6;
	};
	struct {
		double dummy7;
		union {
			dVec3 yzw;
		};
	};
};

#endif // LINA_VEC_TYPES_H
