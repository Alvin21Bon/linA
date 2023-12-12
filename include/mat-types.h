#ifndef LINA_MAT_TYPES_H
#define LINA_MAT_TYPES_H

#include "vec-types.h"

typedef union Mat2 {
	float elements[2][2];
	float e[2][2]; // should be used rarely due to its unobvious name
	Vec2 columns[2];

	struct {
		Vec2 col0;
		Vec2 col1;
	};
	struct {
		Vec2 ihat;
		Vec2 jhat;
	};
} Mat2;

typedef union Mat3 {
	float elements[3][3];
	float e[3][3]; // should be used rarely due to its unobvious name
	Vec3 columns[3];

	struct {
		Vec3 col0;
		Vec3 col1;
		Vec3 col2;
	};
	struct {
		Vec3 ihat;
		Vec3 jhat;
		Vec3 khat;
	};
} Mat3;

typedef union Mat4 {
	float elements[4][4];
	float e[4][4]; // should be used rarely due to its unobvious name
	Vec4 columns[4];

	struct {
		Vec4 col0;
		Vec4 col1;
		Vec4 col2;
		Vec4 col3;
	};
	struct {
		Vec4 ihat;
		Vec4 jhat;
		Vec4 khat;
		Vec4 lhat;
	};
} Mat4;

#endif // LINA_MAT_TYPES_H
