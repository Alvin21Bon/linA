#include "../../include/lina.h"

// constructors
dMat2 dmat2(const dVec2 col0, const dVec2 col1)
{
	dMat2 mat;
	mat.col0 = col0;
	mat.col1 = col1;
	return mat;
}
dMat2 dmat2Fill(const double fillValue)
{
	return dmat2(dvec2Fill(fillValue), dvec2Fill(fillValue));
}
dMat2 dmat2Zero()
{
	return dmat2Fill(0);
}
dMat2 dmat2Diagonalize(const double diagonalValue)
{
	dMat2 mat;
	mat = dmat2Zero();
	mat.elements[0][0] = diagonalValue;
	mat.elements[1][1] = diagonalValue;
	return mat;
}
dMat2 dmat2Identity()
{
	return dmat2Diagonalize(1);
}

// operations
dVec2 dmat2MultVec(const dMat2 mat, const dVec2 vec)
{
	dVec2 result = dvec2Zero();
	for (int i = 0; i < MAT2_NUM_OF_COLUMNS; i++)
	{
		result = dvec2Add(result, dvec2Scaled(mat.columns[i], vec.elements[i]));
	}
	return result;
}
dMat2 dmat2MultMat(const dMat2 left, const dMat2 right)
{
	dMat2 result;
	result.ihat = dmat2MultVec(left, right.ihat);
	result.jhat = dmat2MultVec(left, right.jhat);
	return result;
}
dMat2 dmat2Inverse(const dMat2 mat);
dMat2 dmat2Transposed(const dMat2 mat)
{
	dVec2 xComponents = dvec2(mat.col0.x, mat.col1.x);
	dVec2 yComponents = dvec2(mat.col0.y, mat.col1.y);
	return dmat2(xComponents, yComponents);
}

// matrix info
double dmat2Determinant(const dMat2 mat)
{
	return (mat.e[0][0] * mat.e[1][1]) - (mat.e[1][0] * mat.e[0][1]);
}
void dmat2Print(const dMat2 mat)
{
	for (int i = 0; i < MAT2_NUM_OF_ROWS; i++)
	{
		printf("| ");
		for (int j = 0; j < MAT2_NUM_OF_COLUMNS; j++)
		{
			printf("%lf ", mat.elements[j][i]);
		}
		printf("|\n");
	}
}
