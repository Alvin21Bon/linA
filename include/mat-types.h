#ifndef LINA_MAT_TYPES_H
#define LINA_MAT_TYPES_H

#include "vec-types.h"

typedef union Mat2 Mat2;
typedef union dMat2 dMat2;

typedef union Mat3 Mat3;
typedef union dMat3 dMat3;

typedef union Mat4 Mat4;
typedef union dMat4 dMat4;

union Mat2 {
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
};
union dMat2 {
	double elements[2][2];
	double e[2][2]; // should be used rarely due to its unobvious name
	dVec2 columns[2];

	struct {
		dVec2 col0;
		dVec2 col1;
	};
	struct {
		dVec2 ihat;
		dVec2 jhat;
	};
};

union Mat3 {
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
};
union dMat3 {
	double elements[3][3];
	double e[3][3]; // should be used rarely due to its unobvious name
	dVec3 columns[3];

	struct {
		dVec3 col0;
		dVec3 col1;
		dVec3 col2;
	};
	struct {
		dVec3 ihat;
		dVec3 jhat;
		dVec3 khat;
	};
};

union Mat4 {
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
};
union dMat4 {
	double elements[4][4];
	double e[4][4]; // should be used rarely due to its unobvious name
	dVec4 columns[4];

	struct {
		dVec4 col0;
		dVec4 col1;
		dVec4 col2;
		dVec4 col3;
	};
	struct {
		dVec4 ihat;
		dVec4 jhat;
		dVec4 khat;
		dVec4 lhat;
	};
};

#endif // LINA_MAT_TYPES_H
