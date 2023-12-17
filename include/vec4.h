#ifndef LINA_VEC4_H
#define LINA_VEC4_H

#include "shared.h"
#include "vec-types.h"

// constructors
Vec4 vec4(const float e1, const float e2, const float e3, const float e4);
Vec4 vec4F(const float e1, const float e2, const float e3, const float e4); // helper
Vec4 vec4V(const Vec3 vec, const float e4);
Vec4 vec4Fill(const float fillValue);
Vec4 vec4Zero();

// operations
Vec4 vec4Add(const Vec4 left, const Vec4 right);
Vec4 vec4Sub(const Vec4 left, const Vec4 right);
Vec4 vec4Negated(const Vec4 vec);
Vec4 vec4Scaled(const Vec4 vec, const float scalar);
Vec4 vec4Normalized(const Vec4 vec);
Vec4 vec4PerspDivide(const Vec4 vec);

// vector info
float vec4Length(const Vec4 vec);
void vec4Print(const Vec4 vec);

#endif // LINA_VEC4_H
