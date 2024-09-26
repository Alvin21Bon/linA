#include "../../include/lina.h"

// constructors
dVec2 dvec2(const double e1, const double e2)
{
	dVec2 vec;
	vec.elements[0] = e1;
	vec.elements[1] = e2;
	return vec;
}
dVec2 dvec2Fill(const double fillValue)
{
	return dvec2(fillValue, fillValue);
}
dVec2 dvec2Zero()
{
	return dvec2Fill(0);
}

// operations
dVec2 dvec2Add(const dVec2 left, const dVec2 right)
{
	dVec2 result;
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	return result;
}
dVec2 dvec2Sub(const dVec2 left, const dVec2 right)
{
	dVec2 result;
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	return result;
}
double dvec2Dot(const dVec2 left, const dVec2 right)
{
	return (left.x * right.x) + (left.y * right.y);	
}
double dvec2Cross(const dVec2 left, const dVec2 right)
{
	dMat2 mat = dmat2(left, right);
	return dmat2Determinant(mat);
}
dVec2 dvec2ProjectedLine(const dVec2 vec, const dVec2 line)
{
	dVec2 normLine = dvec2Normalized(line);
	double projectionScalar = dvec2Dot(normLine, vec);
	return dvec2Scaled(normLine, projectionScalar);
}
dVec2 dvec2Negated(const dVec2 vec)
{
	return dvec2Scaled(vec, -1);
}
dVec2 dvec2Scaled(const dVec2 vec, const double scalar)
{
	dVec2 result;
	result.x = vec.x * scalar;
	result.y = vec.y * scalar;
	return result;
}
dVec2 dvec2Rotated(const dVec2 vec, const double radians, const dVec3 axis)
{
	// this function will rotate vec through 3d space, then project it back onto the 2d plane
	// this is the only acceptable case to couple these functions together
	return dvec3Rotated(dvec3V(vec, 0), radians, axis).xy;
}
dVec2 dvec2Normalized(const dVec2 vec)
{
	double vecLength = dvec2Length(vec);
	if (vecLength == 0) return dvec2Zero();

	double scalar = 1 / vecLength;
	return dvec2Scaled(vec, scalar);
}

// vector info
double dvec2Length(const dVec2 vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}
void dvec2Print(const dVec2 vec)
{
	printf("| %f %f |\n", vec.x, vec.y);
}
