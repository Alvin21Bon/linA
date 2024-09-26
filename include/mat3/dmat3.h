#ifndef LINA_DMAT3_H
#define LINA_DMAT3_H

#include "../mat-types.h"

// constructors
dMat3 dmat3(const dVec3 col0, const dVec3 col1, const dVec3 col2);
dMat3 dmat3Fill(const double fillValue);
dMat3 dmat3Zero();
dMat3 dmat3Diagonalize(const double diagonalValue);
dMat3 dmat3Identity();

// operations
dVec3 dmat3MultVec(const dMat3 mat, const dVec3 vec);
dMat3 dmat3MultMat(const dMat3 left, const dMat3 right);
dMat3 dmat3Inverse(const dMat3 mat);
dMat3 dmat3Transposed(const dMat3 mat);

// matrix info
double dmat3Determinant(const dMat3 mat);
void dmat3Print(const dMat3 mat);

#endif // LINA_DMAT3_H
