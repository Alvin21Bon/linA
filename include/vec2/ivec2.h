#ifndef LINA_IVEC2_H
#define LINA_IVEC2_H

#include "../vec-types.h"

// constructors
iVec2 ivec2(const int e1, const int e2);
iVec2 ivec2Fill(const int fillValue);
iVec2 ivec2Zero();

// operations
iVec2 ivec2Add(const iVec2 left, const iVec2 right);
iVec2 ivec2Sub(const iVec2 left, const iVec2 right);
iVec2 ivec2Scaled(const iVec2 vec, const int scalar);
iVec2 ivec2Negated(const iVec2 vec);
int ivec2Equals(const iVec2 left, const iVec2 right);

// vector info
float ivec2Length(const iVec2 vec);
void ivec2Print(const iVec2 vec);

#endif // LINA_IVEC2_H
