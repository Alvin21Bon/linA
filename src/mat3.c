#include "../include/lina.h"

// constructors
Mat3 mat3(const Vec3 col0, const Vec3 col1, const Vec3 col2)
{
	Mat3 mat;
	mat.col0 = col0;
	mat.col1 = col1;
	mat.col2 = col2;
	return mat;
}
Mat3 mat3Fill(const float fillValue)
{
	Vec3 fillVec = vec3Fill(fillValue);
	return mat3(fillVec, fillVec, fillVec);
}
Mat3 mat3Zero()
{
	return mat3Fill(0);
}
Mat3 mat3Diagonalize(const float diagonalValue)
{
	Mat3 mat = mat3Zero();
	mat.elements[0][0] = diagonalValue;
	mat.elements[1][1] = diagonalValue;
	mat.elements[2][2] = diagonalValue;
	return mat;
}
Mat3 mat3Identity()
{
	return mat3Diagonalize(1);
}

// operations
Vec3 mat3MultVec(const Mat3 mat, const Vec3 vec)
{
	Vec3 result = vec3Zero();
	for (int i = 0; i < MAT3_NUM_OF_COLUMNS; i++)
	{
		result = vec3Add(result, vec3Scaled(mat.columns[i], vec.elements[i]));
	}
	return result;
}
Mat3 mat3MultMat(const Mat3 left, const Mat3 right)
{
	Mat3 result;
	result.ihat = mat3MultVec(left, right.ihat);
	result.jhat = mat3MultVec(left, right.jhat);
	result.khat = mat3MultVec(left, right.khat);
	return result;
}
Mat3 mat3Inverse(const Mat3 mat);

// matrix info
float mat3Determinant(const Mat3 mat)
{
	// wonky ass determinant formula lol
	Mat2 detMat0 = mat2(mat.col1.yz, mat.col2.yz);
	Mat2 detMat1 = mat2(vec2(mat.e[1][0], mat.e[1][2]), vec2(mat.e[2][0], mat.e[2][2]));
	Mat2 detMat2 = mat2(mat.col1.xy, mat.col2.xy);

	return  (mat.col0.x * mat2Determinant(detMat0)) - 
		(mat.col0.y * mat2Determinant(detMat1)) +
		(mat.col0.z * mat2Determinant(detMat2)) ;
	
}
void mat3Print(const Mat3 mat)
{
	for (int i = 0; i < MAT3_NUM_OF_ROWS; i++)
	{
		printf("| ");
		for (int j = 0; j < MAT3_NUM_OF_COLUMNS; j++)
		{
			printf("%f ", mat.elements[j][i]);
		}
		printf("|\n");
	}
}
