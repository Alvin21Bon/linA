#include "../../include/lina.h"

// constructors
uVec3 uvec3(const unsigned int e1, const unsigned int e2, const unsigned int e3)
{
	uVec3 vec;
	vec.elements[0] = e1;
	vec.elements[1] = e2;
	vec.elements[2] = e3;
	return vec;
}
uVec3 uvec3F(const unsigned int e1, const unsigned int e2, const unsigned int e3) // helper
{
	return uvec3(e1, e2, e3);
}
uVec3 uvec3V(const uVec2 vec, const unsigned int e3)
{
	return uvec3(vec.x, vec.y, e3);
}
uVec3 uvec3Fill(const unsigned int fillValue)
{
	return uvec3(fillValue, fillValue, fillValue);
}
uVec3 uvec3Zero()
{
	return uvec3Fill(0);
}

// operations
uVec3 uvec3Add(const uVec3 left, const uVec3 right)
{
	uVec3 result;
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	result.z = left.z + right.z;
	return result;
}
uVec3 uvec3Sub(const uVec3 left, const uVec3 right)
{
	uVec3 result;
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	result.z = left.z - right.z;
	return result;
}
uVec3 uvec3Scaled(const uVec3 vec, const unsigned int scalar)
{
	uVec3 result;
	result.x = vec.x * scalar;
	result.y = vec.y * scalar;
	result.z = vec.z * scalar;
	return result;
}
int uvec3Equals(const uVec3 left, const uVec3 right)
{
	uVec3 compareVec = uvec3Sub(left, right);
	return compareVec.x == 0 && compareVec.y == 0 && compareVec.z == 0;
}

// vector info
float uvec3Length(const uVec3 vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
}
void uvec3Print(const uVec3 vec)
{
	printf("| %u %u %u |\n", vec.x, vec.y, vec.z);
}
