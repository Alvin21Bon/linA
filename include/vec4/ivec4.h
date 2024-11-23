#ifndef LINA_IVEC4_H
#define LINA_IVEC4_H

#include "../vec-types.h"

// constructors
iVec4 ivec4(const int e1, const int e2, const int e3, const int e4);
iVec4 ivec4F(const int e1, const int e2, const int e3, const int e4); // helper
iVec4 ivec4V(const iVec3 vec, const int e4);
iVec4 ivec4Fill(const int fillValue);
iVec4 ivec4Zero();

// operations
iVec4 ivec4Add(const iVec4 left, const iVec4 right);
iVec4 ivec4Sub(const iVec4 left, const iVec4 right);
iVec4 ivec4Negated(const iVec4 vec);
iVec4 ivec4Scaled(const iVec4 vec, const int scalar);
int ivec4Equals(const iVec4 left, const iVec4 right);

// vector info
float ivec4Length(const iVec4 vec);
void ivec4Print(const iVec4 vec);

#endif // LINA_IVEC4_H
