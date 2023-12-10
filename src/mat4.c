#include "../include/lina.h"

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
