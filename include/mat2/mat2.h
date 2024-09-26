#ifndef LINA_MAT2_H
#define LINA_MAT2_H

#include "../mat-types.h"

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
Mat2 mat2Transposed(const Mat2 mat);

// matrix info
float mat2Determinant(const Mat2 mat);
void mat2Print(const Mat2 mat);

#endif // LINA_MAT2_H
