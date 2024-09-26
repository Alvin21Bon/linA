#include "../../include/lina.h"

// constructors
uVec2 uvec2(const unsigned int e1, const unsigned int e2);
uVec2 uvec2Fill(const unsigned int fillValue);
uVec2 uvec2Zero();

// operations
uVec2 uvec2Add(const uVec2 left, const uVec2 right);
uVec2 uvec2Sub(const uVec2 left, const uVec2 right);
uVec2 uvec2Scaled(const uVec2 vec, const unsigned int scalar);

// vector info
float uvec2Length(const uVec2 vec);
void uvec2Print(const uVec2 vec);
