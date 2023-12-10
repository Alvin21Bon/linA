#include "../include/lina.h"

// constructors
Vec3 vec3(const float e1, const float e2, const float e3)
{
	Vec3 vec;
	vec.elements[0] = e1;
	vec.elements[1] = e2;
	vec.elements[2] = e3;
	return vec;
}
Vec3 vec3F(const float e1, const float e2, const float e3)
{
	return vec3(e1, e2, e3);
}
Vec3 vec3V(const Vec2 vec, const float e3)
{
	return vec3(vec.x, vec.y, e3);
}
Vec3 vec3Fill(const float fillValue)
{
	return vec3(fillValue, fillValue, fillValue);
}
Vec3 vec3Zero()
{
	return vec3Fill(0);
}

// operations
Vec3 vec3Add(const Vec3 left, const Vec3 right)
{
	Vec3 result;
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	result.z = left.z + right.z;
	return result;
}
Vec3 vec3Sub(const Vec3 left, const Vec3 right)
{
	Vec3 result;
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	result.z = left.z - right.z;
	return result;
}
float vec3Dot(const Vec3 left, const Vec3 right)
{
	return (left.x * right.x) + (left.y * right.y) + (left.z * right.z);
}
Vec3 vec3Cross(const Vec3 left, const Vec3 right)
{
	// straight cross product formula
	Vec3 result;
	result.x = (left.y * right.z) - (left.z * right.y);
	result.y = (left.z * right.x) - (left.x * right.z);
	result.z = (left.x * right.y) - (left.y * right.x);
	return result;
}
Vec3 vec3Negated(const Vec3 vec)
{
	return vec3Scaled(vec, -1);
}
Vec3 vec3Scaled(const Vec3 vec, const float scalar)
{
	Vec3 result;
	result.x = vec.x * scalar;
	result.y = vec.y * scalar;
	result.z = vec.z * scalar;
	return result;
}
Vec3 vec3Rotated(const Vec3 vec, const float radians);
Vec3 vec3Normalized(const Vec3 vec)
{
	float scalar = 1 / vec3Length(vec);
	return vec3Scaled(vec, scalar);
}

// vector info
float vec3Length(const Vec3 vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
}
