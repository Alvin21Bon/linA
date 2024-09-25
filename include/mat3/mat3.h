#ifndef LINA_MAT3_H
#define LINA_MAT3_H

#include "../mat-types.h"

#define MAT3_NUM_OF_COLUMNS 3
#define MAT3_NUM_OF_ROWS 3
#define MAT3_NUM_OF_ELEMENTS (MAT3_NUM_OF_COLUMNS * MAT3_NUM_OF_ROWS) 

// constructors
Mat3 mat3(const Vec3 col0, const Vec3 col1, const Vec3 col2);
Mat3 mat3Fill(const float fillValue);
Mat3 mat3Zero();
Mat3 mat3Diagonalize(const float diagonalValue);
Mat3 mat3Identity();

// operations
Vec3 mat3MultVec(const Mat3 mat, const Vec3 vec);
Mat3 mat3MultMat(const Mat3 left, const Mat3 right);
Mat3 mat3Inverse(const Mat3 mat);
Mat3 mat3Transposed(const Mat3 mat);

// matrix info
float mat3Determinant(const Mat3 mat);
void mat3Print(const Mat3 mat);

#endif // LINA_MAT3_H
