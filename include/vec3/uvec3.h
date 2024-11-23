#ifndef LINA_UVEC3_H
#define LINA_UVEC3_H

#include "../vec-types.h"

// constructors
uVec3 uvec3(const unsigned int e1, const unsigned int e2, const unsigned int e3);
uVec3 uvec3F(const unsigned int e1, const unsigned int e2, const unsigned int e3); // helper
uVec3 uvec3V(const uVec2 vec, const unsigned int e3);
uVec3 uvec3Fill(const unsigned int fillValue);
uVec3 uvec3Zero();

// operations
uVec3 uvec3Add(const uVec3 left, const uVec3 right);
uVec3 uvec3Sub(const uVec3 left, const uVec3 right);
uVec3 uvec3Scaled(const uVec3 vec, const unsigned int scalar);
int uvec3Equals(const uVec3 left, const uVec3 right);

// vector info
float uvec3Length(const uVec3 vec);
void uvec3Print(const uVec3 vec);

#endif // LINA_UVEC3_H
