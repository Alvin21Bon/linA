#ifndef LINA_DMAT4_H
#define LINA_DMAT4_H

#include "../mat-types.h"

// constructors
dMat4 dmat4(const dVec4 col0, const dVec4 col1, const dVec4 col2, const dVec4 col3);
dMat4 dmat4Fill(const double fillValue);
dMat4 dmat4Zero();
dMat4 dmat4Diagonalize(const double diagonalValue);
dMat4 dmat4Identity();

// operations
dVec4 dmat4MultVec(const dMat4 mat, const dVec4 vec);
dMat4 dmat4MultMat(const dMat4 left, const dMat4 right);
dMat4 dmat4Inverse(const dMat4 mat);
dMat4 dmat4Transposed(const dMat4 mat);

// matrix info
double dmat4Determinant(const dMat4 mat);
void dmat4Print(const dMat4 mat);

#endif // LINA_DMAT4_H
