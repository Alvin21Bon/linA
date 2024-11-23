#include "../../include/lina.h"

// constructors
iVec3 ivec3(const int e1, const int e2, const int e3)
{
	iVec3 vec;
	vec.elements[0] = e1;
	vec.elements[1] = e2;
	vec.elements[2] = e3;
	return vec;
}
iVec3 ivec3F(const int e1, const int e2, const int e3) // helper
{
	return ivec3(e1, e2, e3);
}
iVec3 ivec3V(const iVec2 vec, const int e3)
{
	return ivec3(vec.x, vec.y, e3);
}
iVec3 ivec3Fill(const int fillValue)
{
	return ivec3(fillValue, fillValue, fillValue);
}
iVec3 ivec3Zero()
{
	return ivec3Fill(0);
}

// operations
iVec3 ivec3Add(const iVec3 left, const iVec3 right)
{
	iVec3 result;
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	result.z = left.z + right.z;
	return result;
}
iVec3 ivec3Sub(const iVec3 left, const iVec3 right)
{
	iVec3 result;
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	result.z = left.z - right.z;
	return result;
}
iVec3 ivec3Negated(const iVec3 vec)
{
	return ivec3Scaled(vec, -1);
}
iVec3 ivec3Scaled(const iVec3 vec, const int scalar)
{
	iVec3 result;
	result.x = vec.x * scalar;
	result.y = vec.y * scalar;
	result.z = vec.z * scalar;
	return result;
}
int ivec3Equals(const iVec3 left, const iVec3 right)
{
	iVec3 compareVec = ivec3Sub(left, right);
	return compareVec.x == 0 && compareVec.y == 0 && compareVec.z == 0;
}

// vector info
float ivec3Length(const iVec3 vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
}
void ivec3Print(const iVec3 vec)
{
	printf("| %d %d %d |\n", vec.x, vec.y, vec.z);
}
