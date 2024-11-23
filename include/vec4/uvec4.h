#ifndef LINA_UVEC4_H
#define LINA_UVEC4_H

#include "../vec-types.h"

// constructors
uVec4 uvec4(const unsigned int e1, const unsigned int e2, const unsigned int e3, const unsigned int e4);
uVec4 uvec4F(const unsigned int e1, const unsigned int e2, const unsigned int e3, const unsigned int e4); // helper
uVec4 uvec4V(const uVec3 vec, const unsigned int e4);
uVec4 uvec4Fill(const unsigned int fillValue);
uVec4 uvec4Zero();

// operations
uVec4 uvec4Add(const uVec4 left, const uVec4 right);
uVec4 uvec4Sub(const uVec4 left, const uVec4 right);
uVec4 uvec4Scaled(const uVec4 vec, const unsigned int scalar);
int uvec4Equals(const uVec4 left, const uVec4 right);

// vector info
float uvec4Length(const uVec4 vec);
void uvec4Print(const uVec4 vec);

#endif // LINA_UVEC4_H
