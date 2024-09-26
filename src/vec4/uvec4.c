#include "../../include/lina.h"

// constructors
uVec4 uvec4(const unsigned int e1, const unsigned int e2, const unsigned int e3, const unsigned int e4)
{
	uVec4 vec;
	vec.elements[0] = e1;
	vec.elements[1] = e2;
	vec.elements[2] = e3;
	vec.elements[3] = e4;
	return vec;
}
uVec4 uvec4F(const unsigned int e1, const unsigned int e2, const unsigned int e3, const unsigned int e4) // helper
{
	return uvec4(e1, e2, e3, e4);
}
uVec4 uvec4V(const uVec3 vec, const unsigned int e4)
{
	return uvec4(vec.x, vec.y, vec.z, e4);
}
uVec4 uvec4Fill(const unsigned int fillValue)
{
	return uvec4(fillValue, fillValue, fillValue, fillValue);
}
uVec4 uvec4Zero()
{
	return uvec4Fill(0);
}

// operations
uVec4 uvec4Add(const uVec4 left, const uVec4 right)
{
	uVec4 result;
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	result.z = left.z + right.z;
	result.w = left.w + right.w;
	return result;
}
uVec4 uvec4Sub(const uVec4 left, const uVec4 right)
{
	uVec4 result;
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	result.z = left.z - right.z;
	result.w = left.w - right.w;
	return result;
}
uVec4 uvec4Scaled(const uVec4 vec, const unsigned int scalar)
{
	uVec4 result;
	result.x = vec.x * scalar;
	result.y = vec.y * scalar;
	result.z = vec.z * scalar;
	result.w = vec.w * scalar;
	return result;
}

// vector info
float uvec4Length(const uVec4 vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2) + pow(vec.w, 2));
}
void uvec4Print(const uVec4 vec)
{
	printf("| %u %u %u %u |\n", vec.x, vec.y, vec.z, vec.w);
}
