#include "../../include/lina.h"

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
	result.ihat = mat4MultVec(left, right.ihat);
	result.jhat = mat4MultVec(left, right.jhat);
	result.khat = mat4MultVec(left, right.khat);
	result.lhat = mat4MultVec(left, right.lhat);
	return result;
}
Mat4 mat4Inverse(const Mat4 mat);
Mat4 mat4Transposed(const Mat4 mat)
{
	Vec4 xComponents = vec4(mat.col0.x, mat.col1.x, mat.col2.x, mat.col3.x);
	Vec4 yComponents = vec4(mat.col0.y, mat.col1.y, mat.col2.y, mat.col3.y);
	Vec4 zComponents = vec4(mat.col0.z, mat.col1.z, mat.col2.z, mat.col3.z);
	Vec4 wComponents = vec4(mat.col0.w, mat.col1.w, mat.col2.w, mat.col3.w);
	return mat4(xComponents, yComponents, zComponents, wComponents);
}

// matrix info
float mat4Determinant(const Mat4 mat)
{
	// this one is even worse :/
	Mat3 detMat0 = mat3(mat.col1.yzw, mat.col2.yzw, mat.col3.yzw);
	Mat3 detMat1 = mat3(vec3(mat.e[1][0], mat.e[1][2], mat.e[1][3]), vec3(mat.e[2][0], mat.e[2][2], mat.e[2][3]), vec3(mat.e[3][0], mat.e[3][2], mat.e[3][3]));
	Mat3 detMat2 = mat3(vec3V(mat.col1.xy, mat.e[1][3]), vec3V(mat.col2.xy, mat.e[2][3]), vec3V(mat.col3.xy, mat.e[3][3]));
	Mat3 detMat3 = mat3(mat.col1.xyz, mat.col2.xyz, mat.col3.xyz);

	return  (mat.col0.x * mat3Determinant(detMat0)) - 
		(mat.col0.y * mat3Determinant(detMat1)) +
		(mat.col0.z * mat3Determinant(detMat2)) -
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
