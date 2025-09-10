#include "../../include/lina.h"

// constructors
dMat3 dmat3(const dVec3 col0, const dVec3 col1, const dVec3 col2)
{
	dMat3 mat;
	mat.col0 = col0;
	mat.col1 = col1;
	mat.col2 = col2;
	return mat;
}
dMat3 dmat3Fill(const double fillValue)
{
	dVec3 fillVec = dvec3Fill(fillValue);
	return dmat3(fillVec, fillVec, fillVec);
}
dMat3 dmat3Zero()
{
	return dmat3Fill(0);
}
dMat3 dmat3Diagonalize(const double diagonalValue)
{
	dMat3 mat = dmat3Zero();
	mat.elements[0][0] = diagonalValue;
	mat.elements[1][1] = diagonalValue;
	mat.elements[2][2] = diagonalValue;
	return mat;
}
dMat3 dmat3Identity()
{
	return dmat3Diagonalize(1);
}

// operations
dVec3 dmat3MultVec(const dMat3 mat, const dVec3 vec)
{
	dVec3 result = dvec3Zero();
	for (int i = 0; i < MAT3_NUM_OF_COLUMNS; i++)
	{
		result = dvec3Add(result, dvec3Scaled(mat.columns[i], vec.elements[i]));
	}
	return result;
}
dMat3 dmat3MultMat(const dMat3 left, const dMat3 right)
{
	dMat3 result;
	result.ihat = dmat3MultVec(left, right.ihat);
	result.jhat = dmat3MultVec(left, right.jhat);
	result.khat = dmat3MultVec(left, right.khat);
	return result;
}
dMat3 dmat3Inverse(const dMat3 mat);
dMat3 dmat3Transposed(const dMat3 mat)
{
	dVec3 xComponents = dvec3(mat.col0.x, mat.col1.x, mat.col2.x);
	dVec3 yComponents = dvec3(mat.col0.y, mat.col1.y, mat.col2.y);
	dVec3 zComponents = dvec3(mat.col0.z, mat.col1.z, mat.col2.z);
	return dmat3(xComponents, yComponents, zComponents);
}

// matrix info
double dmat3Determinant(const dMat3 mat)
{
	// wonky ass determinant formula lol
	dMat2 detMat0 = dmat2(mat.col1.yz, mat.col2.yz);
	dMat2 detMat1 = dmat2(dvec2(mat.e[1][0], mat.e[1][2]), dvec2(mat.e[2][0], mat.e[2][2]));
	dMat2 detMat2 = dmat2(mat.col1.xy, mat.col2.xy);

	return  (mat.col0.x * dmat2Determinant(detMat0)) - 
		(mat.col0.y * dmat2Determinant(detMat1)) +
		(mat.col0.z * dmat2Determinant(detMat2)) ;
	
}
void dmat3Print(const dMat3 mat)
{
	for (int i = 0; i < MAT3_NUM_OF_ROWS; i++)
	{
		printf("| ");
		for (int j = 0; j < MAT3_NUM_OF_COLUMNS; j++)
		{
			printf("%lf ", mat.elements[j][i]);
		}
		printf("|\n");
	}
}
