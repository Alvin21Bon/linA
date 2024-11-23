#ifndef LINA_VEC2_H
#define LINA_VEC2_H

#include "../vec-types.h"

// constructors
Vec2 vec2(const float e1, const float e2);
Vec2 vec2Fill(const float fillValue);
Vec2 vec2Zero();

// operations
Vec2 vec2Add(const Vec2 left, const Vec2 right);
Vec2 vec2Sub(const Vec2 left, const Vec2 right);
float vec2Dot(const Vec2 left, const Vec2 right);
float vec2Cross(const Vec2 left, const Vec2 right);
Vec2 vec2ProjectedLine(const Vec2 vec, const Vec2 line);
Vec2 vec2Negated(const Vec2 vec);
Vec2 vec2Scaled(const Vec2 vec, const float scalar);
Vec2 vec2Rotated(const Vec2 vec, const float radians, const Vec3 axis);
Vec2 vec2Normalized(const Vec2 vec);
int vec2Equals(const Vec2 left, const Vec2 right);

// vector info
float vec2Length(const Vec2 vec);
void vec2Print(const Vec2 vec);

#endif // LINA_VEC2_H
