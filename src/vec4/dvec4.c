#include "../../include/lina.h"

// constructors
dVec4 dvec4(const double e1, const double e2, const double e3, const double e4)
{
	dVec4 vec;
	vec.elements[0] = e1;
	vec.elements[1] = e2;
	vec.elements[2] = e3;
	vec.elements[3] = e4;
	return vec;
}
dVec4 dvec4F(const double e1, const double e2, const double e3, const double e4) // helper
{
	return dvec4(e1, e2, e3, e4);
}
dVec4 dvec4V(const dVec3 vec, const double e4)
{
	return dvec4(vec.x, vec.y, vec.z, e4);
}
dVec4 dvec4Fill(const double fillValue)
{
	return dvec4(fillValue, fillValue, fillValue, fillValue);
}
dVec4 dvec4Zero()
{
	return dvec4Fill(0);
}

// operations
dVec4 dvec4Add(const dVec4 left, const dVec4 right)
{
	dVec4 result;
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	result.z = left.z + right.z;
	result.w = left.w + right.w;
	return result;
}
dVec4 dvec4Sub(const dVec4 left, const dVec4 right)
{
	dVec4 result;
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	result.z = left.z - right.z;
	result.w = left.w - right.w;
	return result;
}
dVec4 dvec4Negated(const dVec4 vec)
{
	return dvec4Scaled(vec, -1);
}
dVec4 dvec4Scaled(const dVec4 vec, const double scalar)
{
	dVec4 result;
	result.x = vec.x * scalar;
	result.y = vec.y * scalar;
	result.z = vec.z * scalar;
	result.w = vec.w * scalar;
	return result;
}
dVec4 dvec4Normalized(const dVec4 vec)
{
	double vecLength = dvec4Length(vec);
	if (vecLength == 0) return dvec4Zero();

	double scalar = 1 / vecLength;
	return dvec4Scaled(vec, scalar);
}
dVec4 dvec4PerspDivide(const dVec4 vec)
{
	double scalar = 1 / vec.w;
	return dvec4Scaled(vec, scalar);
}

// vector info
double dvec4Length(const dVec4 vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2) + pow(vec.w, 2));
}
void dvec4Print(const dVec4 vec)
{
	printf("| %f %f %f %f |\n", vec.x, vec.y, vec.z, vec.w);
}
