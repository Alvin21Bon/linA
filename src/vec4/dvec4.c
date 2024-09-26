#include "../../include/lina.h"

// constructors
dVec4 dvec4(const double e1, const double e2, const double e3, const double e4);
dVec4 dvec4F(const double e1, const double e2, const double e3, const double e4); // helper
dVec4 dvec4V(const dVec3 vec, const double e4);
dVec4 dvec4Fill(const double fillValue);
dVec4 dvec4Zero();

// operations
dVec4 dvec4Add(const dVec4 left, const dVec4 right);
dVec4 dvec4Sub(const dVec4 left, const dVec4 right);
dVec4 dvec4Negated(const dVec4 vec);
dVec4 dvec4Scaled(const dVec4 vec, const double scalar);
dVec4 dvec4Normalized(const dVec4 vec);
dVec4 dvec4PerspDivide(const dVec4 vec);

// vector info
double dvec4Length(const dVec4 vec);
void dvec4Print(const dVec4 vec);
