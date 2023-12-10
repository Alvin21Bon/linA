#include "../include/lina.h"

// constructors
Mat4 mat4(const Vec4 col0, const Vec4 col1, const Vec4 col2, const Vec4 col3)
{
	Mat4 mat;
	mat.col0 = col0;
	mat.col1 = col1;
	mat.col2 = col2;
	mat.col3 = col3;
	return mat;
}
Mat4 mat4Fill(const float fillValue)
{
	Vec4 fillVec = vec4Fill(fillValue);
	return mat4(fillVec, fillVec, fillVec, fillVec);
}
Mat4 mat4Zero()
{
	return mat4Fill(0);
}
Mat4 mat4Diagonalize(const float diagonalValue)
{
	Mat4 mat = mat4Zero();
	mat.elements[0][0] = diagonalValue;
	mat.elements[1][1] = diagonalValue;
	mat.elements[2][2] = diagonalValue;
	mat.elements[3][3] = diagonalValue;
	return mat;
}
Mat4 mat4Identity()
{
	return mat4Diagonalize(1);
}

// operations
Vec4 mat4MultVec(const Mat4 mat, const Vec4 vec)
{
	Vec4 result = vec4Zero();
	for (int i = 0; i < MAT4_NUM_OF_COLUMNS; i++)
	{
		result = vec4Add(result, vec4Scaled(mat.columns[i], vec.elements[i]));
	}
	return result;
}
Mat4 mat4MultMat(const Mat4 left, const Mat4 right)
{
	Mat4 result;
	result.colX = mat4MultVec(left, right.colX);
	result.colY = mat4MultVec(left, right.colY);
	result.colZ = mat4MultVec(left, right.colZ);
	result.colW = mat4MultVec(left, right.colW);
	return result;
}
Mat4 mat4Inverse(const Mat4 mat);

// matrix info
float mat4Determinant(const Mat4 mat)
{
	// this one is even worse :/
	Mat3 detMat0 = mat3(vec3(mat.e[1][1], mat.e[1][2], mat.e[1][3]), vec3(mat.e[2][1], mat.e[2][2], mat.e[2][3]), vec3(mat.e[3][1], mat.e[3][2], mat.e[3][3]));
	Mat3 detMat1 = mat3(vec3(mat.e[1][0], mat.e[1][2], mat.e[1][3]), vec3(mat.e[2][0], mat.e[2][2], mat.e[2][3]), vec3(mat.e[3][0], mat.e[3][2], mat.e[3][3]));
	Mat3 detMat2 = mat3(vec3(mat.e[1][0], mat.e[1][1], mat.e[1][3]), vec3(mat.e[2][0], mat.e[2][1], mat.e[2][3]), vec3(mat.e[3][0], mat.e[3][1], mat.e[3][3]));
	Mat3 detMat3 = mat3(vec3(mat.e[1][0], mat.e[1][1], mat.e[1][2]), vec3(mat.e[2][0], mat.e[2][1], mat.e[2][2]), vec3(mat.e[3][0], mat.e[3][1], mat.e[3][2]));

	return  (mat.col0.x * mat3Determinant(detMat0)) + 
		(mat.col0.y * mat3Determinant(detMat1)) +
		(mat.col0.z * mat3Determinant(detMat2)) +
		(mat.col0.w * mat3Determinant(detMat3)) ;
}
void mat4Print(const Mat4 mat)
{
	for (int i = 0; i < MAT4_NUM_OF_ROWS; i++)
	{
		printf("| ");
		for (int j = 0; j < MAT4_NUM_OF_COLUMNS; j++)
		{
			printf("%f ", mat.elements[j][i]);
		}
		printf("|\n");
	}
}
