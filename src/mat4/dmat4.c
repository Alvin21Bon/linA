#include "../../include/lina.h"

// constructors
dMat4 dmat4(const dVec4 col0, const dVec4 col1, const dVec4 col2, const dVec4 col3)
{
	dMat4 mat;
	mat.col0 = col0;
	mat.col1 = col1;
	mat.col2 = col2;
	mat.col3 = col3;
	return mat;
}
dMat4 dmat4Fill(const double fillValue)
{
	dVec4 fillVec = dvec4Fill(fillValue);
	return dmat4(fillVec, fillVec, fillVec, fillVec);
}
dMat4 dmat4Zero()
{
	return dmat4Fill(0);
}
dMat4 dmat4Diagonalize(const double diagonalValue)
{
	dMat4 mat = dmat4Zero();
	mat.elements[0][0] = diagonalValue;
	mat.elements[1][1] = diagonalValue;
	mat.elements[2][2] = diagonalValue;
	mat.elements[3][3] = diagonalValue;
	return mat;
}
dMat4 dmat4Identity()
{
	return dmat4Diagonalize(1);
}

// operations
dVec4 dmat4MultVec(const dMat4 mat, const dVec4 vec)
{
	dVec4 result = dvec4Zero();
	for (int i = 0; i < MAT4_NUM_OF_COLUMNS; i++)
	{
		result = dvec4Add(result, dvec4Scaled(mat.columns[i], vec.elements[i]));
	}
	return result;
}
dMat4 dmat4MultMat(const dMat4 left, const dMat4 right)
{
	dMat4 result;
	result.ihat = dmat4MultVec(left, right.ihat);
	result.jhat = dmat4MultVec(left, right.jhat);
	result.khat = dmat4MultVec(left, right.khat);
	result.lhat = dmat4MultVec(left, right.lhat);
	return result;
}
dMat4 dmat4Inverse(const dMat4 mat);
dMat4 dmat4Transposed(const dMat4 mat)
{
	dVec4 xComponents = dvec4(mat.col0.x, mat.col1.x, mat.col2.x, mat.col3.x);
	dVec4 yComponents = dvec4(mat.col0.y, mat.col1.y, mat.col2.y, mat.col3.y);
	dVec4 zComponents = dvec4(mat.col0.z, mat.col1.z, mat.col2.z, mat.col3.z);
	dVec4 wComponents = dvec4(mat.col0.w, mat.col1.w, mat.col2.w, mat.col3.w);
	return dmat4(xComponents, yComponents, zComponents, wComponents);
}

// matrix info
double dmat4Determinant(const dMat4 mat)
{
	// this one is even worse :/
	dMat3 detMat0 = dmat3(mat.col1.yzw, mat.col2.yzw, mat.col3.yzw);
	dMat3 detMat1 = dmat3(dvec3(mat.e[1][0], mat.e[1][2], mat.e[1][3]), dvec3(mat.e[2][0], mat.e[2][2], mat.e[2][3]), dvec3(mat.e[3][0], mat.e[3][2], mat.e[3][3]));
	dMat3 detMat2 = dmat3(dvec3V(mat.col1.xy, mat.e[1][3]), dvec3V(mat.col2.xy, mat.e[2][3]), dvec3V(mat.col3.xy, mat.e[3][3]));
	dMat3 detMat3 = dmat3(mat.col1.xyz, mat.col2.xyz, mat.col3.xyz);

	return  (mat.col0.x * dmat3Determinant(detMat0)) - 
		(mat.col0.y * dmat3Determinant(detMat1)) +
		(mat.col0.z * dmat3Determinant(detMat2)) -
		(mat.col0.w * dmat3Determinant(detMat3)) ;
}
void dmat4Print(const dMat4 mat)
{
	for (int i = 0; i < MAT4_NUM_OF_ROWS; i++)
	{
		printf("| ");
		for (int j = 0; j < MAT4_NUM_OF_COLUMNS; j++)
		{
			printf("%lf ", mat.elements[j][i]);
		}
		printf("|\n");
	}
}
