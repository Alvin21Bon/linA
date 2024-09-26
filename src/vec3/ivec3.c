#include "../../include/lina.h"

// constructors
iVec3 ivec3(const int e1, const int e2, const int e3);
iVec3 ivec3F(const int e1, const int e2, const int e3); // helper
iVec3 ivec3V(const iVec2 vec, const int e3);
iVec3 ivec3Fill(const int fillValue);
iVec3 ivec3Zero();

// operations
iVec3 ivec3Add(const iVec3 left, const iVec3 right);
iVec3 ivec3Sub(const iVec3 left, const iVec3 right);
iVec3 ivec3Negated(const iVec3 vec);
iVec3 ivec3Scaled(const iVec3 vec, const int scalar);

// vector info
float ivec3Length(const iVec3 vec);
void ivec3Print(const iVec3 vec);
