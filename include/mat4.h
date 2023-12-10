#ifndef LINA_MAT4_H
#define LINA_MAT4_H

#include "shared.h"
#include "vec4.h"

#define MAT4_NUM_OF_COLUMNS 4
#define MAT4_NUM_OF_ROWS 4
#define MAT4_NUM_OF_ELEMENTS (MAT4_NUM_OF_COLUMNS * MAT4_NUM_OF_ROWS) 

typedef union Mat4 {
	float elements[4][4];
	Vec4 columns[4];

	struct {
		Vec4 col0;
		Vec4 col1;
		Vec4 col2;
		Vec4 col3;
	};
	struct {
		Vec4 colX;
		Vec4 colY;
		Vec4 colZ;
		Vec4 colW;
	};
} Mat4;

// constructors
Mat4 mat4(const Vec4 col0, const Vec4 col1, const Vec4 col2, const Vec4 col3);
Mat4 mat4Fill(const float fillValue);
Mat4 mat4Zero();
Mat4 mat4Diagonalize(const float diagonalValue);
Mat4 mat4Identity();

// operations
Vec4 mat4MultVec(const Mat4 mat, const Vec4 vec);
Mat4 mat4MultMat(const Mat4 left, const Mat4 right);
Mat4 mat4Inverse(const Mat4 mat);

// matrix info
float mat4Determinant(const Mat4 mat);
void mat4Print(const Mat4 mat);

#endif // LINA_MAT4_H
