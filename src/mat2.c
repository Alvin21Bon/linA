#include "../include/lina.h"

// constructors
Mat2 mat2(const Vec2 col0, const Vec2 col1)
{
	Mat2 mat;
	mat.col0 = col0;
	mat.col1 = col1;
	return mat;
}
Mat2 mat2Fill(const float fillValue)
{
	return mat2(vec2Fill(fillValue), vec2Fill(fillValue));
}
Mat2 mat2Zero()
{
	return mat2Fill(0);
}
Mat2 mat2Diagonalize(const float diagonalValue)
{
	Mat2 mat;
	mat = mat2Zero();
	mat.elements[0][0] = diagonalValue;
	mat.elements[1][1] = diagonalValue;
	return mat;
}
Mat2 mat2Identity()
{
	return mat2Diagonalize(1);
}

// operations
Vec2 mat2MultVec(const Mat2 mat, const Vec2 vec)
{
	Vec2 result;
	Mat2 scaledMat = mat2(vec2Scaled(mat.colX, vec.x), vec2Scaled(mat.colY, vec.y));
	result = vec2Add(scaledMat.colX, scaledMat.colY);
	return result;
}
Mat2 mat2MultMat(const Mat2 left, const Mat2 right)
{
	Mat2 result;
	result.colX = mat2MultVec(left, right.colX);
	result.colY = mat2MultVec(left, right.colY);
	return result;
}
Mat2 mat2Inverse(const Mat2 mat);

// matrix info
float mat2Determinant(const Mat2 mat)
{
	return (mat.e[0][0] * mat.e[1][1]) - (mat.e[0][1] * mat.e[1][0]);
}
void mat2Print(const Mat2 mat)
{
	for (int i = 0; i < MAT2_NUM_OF_ROWS; i++)
	{
		printf("| ");
		for (int j = 0; j < MAT2_NUM_OF_COLUMNS; j++)
		{
			printf("%f ", mat.elements[j][i]);
		}
		printf("|\n");
	}
}
