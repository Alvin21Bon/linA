#ifndef LINA_DVEC2_H
#define LINA_DVEC2_H

#include "../vec-types.h"

// constructors
dVec2 dvec2(const double e1, const double e2);
dVec2 dvec2Fill(const double fillValue);
dVec2 dvec2Zero();

// operations
dVec2 dvec2Add(const dVec2 left, const dVec2 right);
dVec2 dvec2Sub(const dVec2 left, const dVec2 right);
double dvec2Dot(const dVec2 left, const dVec2 right);
double dvec2Cross(const dVec2 left, const dVec2 right);
dVec2 dvec2ProjectedLine(const dVec2 vec, const dVec2 line);
dVec2 dvec2Negated(const dVec2 vec);
dVec2 dvec2Scaled(const dVec2 vec, const double scalar);
dVec2 dvec2Rotated(const dVec2 vec, const double radians, const dVec3 axis);
dVec2 dvec2Normalized(const dVec2 vec);

// vector info
double dvec2Length(const dVec2 vec);
void dvec2Print(const dVec2 vec);

#endif // LINA_DVEC2_H
