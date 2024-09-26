#include "../../include/lina.h"

// constructors
iVec2 ivec2(const int e1, const int e2)
{
	iVec2 vec;
	vec.elements[0] = e1;
	vec.elements[1] = e2;
	return vec;
}
iVec2 ivec2Fill(const int fillValue)
{
	return ivec2(fillValue, fillValue);
}
iVec2 ivec2Zero()
{
	return ivec2Fill(0);
}

// operations
iVec2 ivec2Add(const iVec2 left, const iVec2 right)
{
	iVec2 result;
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	return result;
}
iVec2 ivec2Sub(const iVec2 left, const iVec2 right)
{
	iVec2 result;
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	return result;
}
iVec2 ivec2Scaled(const iVec2 vec, const int scalar)
{
	iVec2 result;
	result.x = vec.x * scalar;
	result.y = vec.y * scalar;
	return result;
}
iVec2 ivec2Negated(const iVec2 vec)
{
	return ivec2Scaled(vec, -1);
}

// vector info
float ivec2Length(const iVec2 vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}
void ivec2Print(const iVec2 vec)
{
	printf("| %d %d |\n", vec.x, vec.y);
}
