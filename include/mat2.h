#ifndef LINA_MAT2_H
#define LINA_MAT2_H

#include "shared.h"
#include "vec2.h"

#define MAT2_NUM_OF_COLUMNS 2
#define MAT2_NUM_OF_ROWS 2
#define MAT2_NUM_OF_ELEMENTS (MAT2_NUM_OF_COLUMNS * MAT2_NUM_OF_ROWS) 

typedef union Mat2 {
	float elements[2][2];
	float e[2][2];
	Vec2 columns[2];

	struct {
		Vec2 col0;
		Vec2 col1;
	};
	struct {
		Vec2 colX;
		Vec2 colY;
	};
} Mat2;

// constructors
Mat2 mat2(const Vec2 col0, const Vec2 col1);
Mat2 mat2Fill(const float fillValue);
Mat2 mat2Zero();
Mat2 mat2Diagonalize(const float diagonalValue);
Mat2 mat2Identity();

// operations
Vec2 mat2MultVec(const Mat2 mat, const Vec2 vec);
Mat2 mat2MultMat(const Mat2 left, const Mat2 right);
Mat2 mat2Inverse(const Mat2 mat);

// matrix info
float mat2Determinant(const Mat2 mat);
void mat2Print(const Mat2 mat);

#endif // LINA_MAT2_H
