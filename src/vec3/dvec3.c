#include "../../include/lina.h"

// constructors
dVec3 dvec3(const double e1, const double e2, const double e3);
dVec3 dvec3F(const double e1, const double e2, const double e3); // helper
dVec3 dvec3V(const dVec2 vec, const double e3);
dVec3 dvec3Fill(const double fillValue);
dVec3 dvec3Zero();

// operations
dVec3 dvec3Add(const dVec3 left, const dVec3 right);
dVec3 dvec3Sub(const dVec3 left, const dVec3 right);
double dvec3Dot(const dVec3 left, const dVec3 right);
dVec3 dvec3Cross(const dVec3 left, const dVec3 right);
dVec3 dvec3ProjectedLine(const dVec3 vec, const dVec3 line);
dVec3 dvec3Negated(const dVec3 vec);
dVec3 dvec3Scaled(const dVec3 vec, const double scalar);
dVec3 dvec3Rotated(const dVec3 vec, const double radians, const dVec3 axis);
dVec3 dvec3Normalized(const dVec3 vec);

// vector info
double dvec3Length(const dVec3 vec);
void dvec3Print(const dVec3 vec);
