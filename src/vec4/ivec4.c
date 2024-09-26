#include "../../include/lina.h"

// constructors
iVec4 ivec4(const int e1, const int e2, const int e3, const int e4)
{
	iVec4 vec;
	vec.elements[0] = e1;
	vec.elements[1] = e2;
	vec.elements[2] = e3;
	vec.elements[3] = e4;
	return vec;
}
iVec4 ivec4F(const int e1, const int e2, const int e3, const int e4) // helper
{
	return ivec4(e1, e2, e3, e4);
}
iVec4 ivec4V(const iVec3 vec, const int e4)
{
	return ivec4(vec.x, vec.y, vec.z, e4);
}
iVec4 ivec4Fill(const int fillValue)
{
	return ivec4(fillValue, fillValue, fillValue, fillValue);
}
iVec4 ivec4Zero()
{
	return ivec4Fill(0);
}

// operations
iVec4 ivec4Add(const iVec4 left, const iVec4 right)
{
	iVec4 result;
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	result.z = left.z + right.z;
	result.w = left.w + right.w;
	return result;
}
iVec4 ivec4Sub(const iVec4 left, const iVec4 right)
{
	iVec4 result;
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	result.z = left.z - right.z;
	result.w = left.w - right.w;
	return result;
}
iVec4 ivec4Negated(const iVec4 vec)
{
	return ivec4Scaled(vec, -1);
}
iVec4 ivec4Scaled(const iVec4 vec, const int scalar)
{
	iVec4 result;
	result.x = vec.x * scalar;
	result.y = vec.y * scalar;
	result.z = vec.z * scalar;
	result.w = vec.w * scalar;
	return result;
}

// vector info
float ivec4Length(const iVec4 vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2) + pow(vec.w, 2));
}
void ivec4Print(const iVec4 vec)
{
	printf("| %d %d %d %d |\n", vec.x, vec.y, vec.z, vec.w);
}
