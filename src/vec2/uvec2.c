#include "../../include/lina.h"

// constructors
uVec2 uvec2(const unsigned int e1, const unsigned int e2)
{
	uVec2 vec;
	vec.elements[0] = e1;
	vec.elements[1] = e2;
	return vec;
}

uVec2 uvec2Fill(const unsigned int fillValue)
{
	return uvec2(fillValue, fillValue);
}
uVec2 uvec2Zero()
{
	return uvec2Fill(0);
}

// operations
uVec2 uvec2Add(const uVec2 left, const uVec2 right)
{
	uVec2 result;
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	return result;
}
uVec2 uvec2Sub(const uVec2 left, const uVec2 right)
{
	uVec2 result;
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	return result;
}
uVec2 uvec2Scaled(const uVec2 vec, const unsigned int scalar)
{
	uVec2 result;
	result.x = vec.x * scalar;
	result.y = vec.y * scalar;
	return result;
}
int uvec2Equals(const uVec2 left, const uVec2 right)
{
	uVec2 compareVec = uvec2Sub(left, right);
	return compareVec.x == 0 && compareVec.y == 0;
}

// vector info
float uvec2Length(const uVec2 vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}
void uvec2Print(const uVec2 vec)
{
	printf("| %u %u |\n", vec.x, vec.y);
}
