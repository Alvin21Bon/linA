#include "../include/lina.h"

// constructors
Vec4 vec4(const float e1, const float e2, const float e3, const float e4)
{
	Vec4 vec;
	vec.elements[0] = e1;
	vec.elements[1] = e2;
	vec.elements[2] = e3;
	vec.elements[3] = e4;
	return vec;
}
Vec4 vec4F(const float e1, const float e2, const float e3, const float e4)
{
	return vec4(e1, e2, e3, e4);
}
Vec4 vec4V(const Vec3 vec, const float e4)
{
	return vec4(vec.x, vec.y, vec.z, e4);
}
Vec4 vec4Fill(const float fillValue)
{
	return vec4(fillValue, fillValue, fillValue, fillValue);
}
Vec4 vec4Zero()
{
	return vec4Fill(0);
}

// operations
Vec4 vec4Add(const Vec4 left, const Vec4 right)
{
	Vec4 result;
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	result.z = left.z + right.z;
	result.w = left.w + right.w;
	return result;
}
Vec4 vec4Sub(const Vec4 left, const Vec4 right)
{
	Vec4 result;
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	result.z = left.z - right.z;
	result.w = left.w - right.w;
	return result;
}
float vec4Dot(const Vec4 left, const Vec4 right)
{
	return (left.x * right.x) + (left.y * right.y) + (left.z * right.z) + (left.w * right.w);
}
Vec4 vec4Cross(const Vec4 left, const Vec4 right)
{
	Vec4 result;
	result.x = (left.y * right.z) - (left.z * right.y);
	result.y = (left.z * right.x) - (left.x * right.z);
	result.z = (left.x * right.y) - (left.y * right.x);
	result.w = left.w == right.w ? right.w : 1; // ??? idk. W component doesnt really matter here
	return result;
}
Vec4 vec4ProjectedLine(const Vec4 vec, const Vec4 line);
Vec4 vec4Negated(const Vec4 vec)
{
	return vec4Scaled(vec, -1);
}
Vec4 vec4Scaled(const Vec4 vec, const float scalar)
{
	Vec4 result;
	result.x = vec.x * scalar;
	result.y = vec.y * scalar;
	result.z = vec.z * scalar;
	result.w = vec.w * scalar;
	return result;
}
Vec4 vec4Rotated(const Vec4 vec, const float radians, const Vec3 axis);
Vec4 vec4Normalized(const Vec4 vec)
{
	float scalar = 1 / vec4Length(vec);
	return vec4Scaled(vec, scalar);
}

// vector info
float vec4Length(const Vec4 vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2) + pow(vec.w, 2));
}
