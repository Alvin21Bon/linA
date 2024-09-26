#ifndef LINA_DMAT2_H
#define LINA_DMAT2_H

#include "../mat-types.h"

// constructors
dMat2 dmat2(const dVec2 col0, const dVec2 col1);
dMat2 dmat2Fill(const double fillValue);
dMat2 dmat2Zero();
dMat2 dmat2Diagonalize(const double diagonalValue);
dMat2 dmat2Identity();

// operations
dVec2 dmat2MultVec(const dMat2 mat, const dVec2 vec);
dMat2 dmat2MultMat(const dMat2 left, const dMat2 right);
dMat2 dmat2Inverse(const dMat2 mat);
dMat2 dmat2Transposed(const dMat2 mat);

// matrix info
double dmat2Determinant(const dMat2 mat);
void dmat2Print(const dMat2 mat);

#endif // LINA_DMAT2_H
