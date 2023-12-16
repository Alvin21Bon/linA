#include "../include/lina.h"

// constructors
Vec2 vec2(const float e1, const float e2)
{
	Vec2 vec;
	vec.elements[0] = e1;
	vec.elements[1] = e2;
	return vec;
}
Vec2 vec2Fill(const float fillValue)
{
	return vec2(fillValue, fillValue);
}
Vec2 vec2Zero()
{
	return vec2Fill(0);
}

// operations
Vec2 vec2Add(const Vec2 left, const Vec2 right)
{
	Vec2 result;
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	return result;
}
Vec2 vec2Sub(const Vec2 left, const Vec2 right)
{
	Vec2 result;
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	return result;
}
float vec2Dot(const Vec2 left, const Vec2 right)
{
	return (left.x * right.x) + (left.y * right.y);	
}
float vec2Cross(const Vec2 left, const Vec2 right)
{
	Mat2 mat = mat2(left, right);
	return mat2Determinant(mat);
}
Vec2 vec2Negated(const Vec2 vec)
{
	return vec2Scaled(vec, -1);
}
Vec2 vec2Scaled(const Vec2 vec, const float scalar)
{
	Vec2 result;
	result.x = vec.x * scalar;
	result.y = vec.y * scalar;
	return result;
}
Vec2 vec2Rotated(const Vec2 vec, const float radians, const Vec3 axis);
Vec2 vec2Normalized(const Vec2 vec)
{
	float scalar = 1 / vec2Length(vec);
	return vec2Scaled(vec, scalar);
}

// vector info
float vec2Length(const Vec2 vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}
