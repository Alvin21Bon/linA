#include "../../include/lina.h"

// constructors
dVec3 dvec3(const double e1, const double e2, const double e3)
{
	dVec3 vec;
	vec.elements[0] = e1;
	vec.elements[1] = e2;
	vec.elements[2] = e3;
	return vec;
}
dVec3 dvec3F(const double e1, const double e2, const double e3) // helper
{
	return dvec3(e1, e2, e3);
}
dVec3 dvec3V(const dVec2 vec, const double e3)
{
	return dvec3(vec.x, vec.y, e3);
}
dVec3 dvec3Fill(const double fillValue)
{
	return dvec3(fillValue, fillValue, fillValue);
}
dVec3 dvec3Zero()
{
	return dvec3Fill(0);
}

// operations
dVec3 dvec3Add(const dVec3 left, const dVec3 right)
{
	dVec3 result;
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	result.z = left.z + right.z;
	return result;
}
dVec3 dvec3Sub(const dVec3 left, const dVec3 right)
{
	dVec3 result;
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	result.z = left.z - right.z;
	return result;
}
double dvec3Dot(const dVec3 left, const dVec3 right)
{
	return (left.x * right.x) + (left.y * right.y) + (left.z * right.z);
}
dVec3 dvec3Cross(const dVec3 left, const dVec3 right)
{
	// straight cross product formula
	dVec3 result;
	result.x = (left.y * right.z) - (left.z * right.y);
	result.y = (left.z * right.x) - (left.x * right.z);
	result.z = (left.x * right.y) - (left.y * right.x);
	return result;
}
dVec3 dvec3ProjectedLine(const dVec3 vec, const dVec3 line)
{
	dVec3 normLine = dvec3Normalized(line);
	double projectionScalar = dvec3Dot(normLine, vec);
	return dvec3Scaled(normLine, projectionScalar);
}
dVec3 dvec3Negated(const dVec3 vec)
{
	return dvec3Scaled(vec, -1);
}
dVec3 dvec3Scaled(const dVec3 vec, const double scalar)
{
	dVec3 result;
	result.x = vec.x * scalar;
	result.y = vec.y * scalar;
	result.z = vec.z * scalar;
	return result;
}
dVec3 dvec3Rotated(const dVec3 vec, const double radians, const dVec3 axis)
{
	// if these functions are confusing, look at your rotation notes
	dVec3 vecProjectedOnAxis = dvec3ProjectedLine(vec, axis); 
	
	// we are defining a plane that rests on the tip of the vector and axis of rotation projection point
	// this plane is used to define a new coordinate system that will allow for simple circle calculations
	dVec3 circleIhat = dvec3Sub(vec, vecProjectedOnAxis);
	dVec3 circleJhat = dvec3Cross(axis, circleIhat); // taking cross product with argument due to edge case where the vector projected on the axis is zero vector
	double circleRadius = dvec3Length(circleIhat); // getting the radius before normalizing the circle basis vectors
	circleIhat = dvec3Normalized(circleIhat);
	circleJhat = dvec3Normalized(circleJhat);
	dMat3 circleCoordinateSystem = dmat3(circleIhat, circleJhat, dvec3Zero());

	// we are now working in our new coordinate system to get the circle coordinates
	double circleX = cos(radians) * circleRadius;
	double circleY = sin(radians) * circleRadius;
	dVec3 circleCoords = dvec3(circleX, circleY, 0);

	// this is essentially just change of basis work
	dVec3 circleCoordsInOurCoordinateSystem = dmat3MultVec(circleCoordinateSystem, circleCoords);

	dVec3 result = dvec3Add(vecProjectedOnAxis, circleCoordsInOurCoordinateSystem);
	return result; 
}
dVec3 dvec3Normalized(const dVec3 vec)
{
	double vecLength = dvec3Length(vec);
	if (vecLength == 0) return dvec3Zero();

	double scalar = 1 / vecLength;
	return dvec3Scaled(vec, scalar);
}
int dvec3Equals(const dVec3 left, const dVec3 right)
{
	dVec3 compareVec = dvec3Sub(left, right);
	return compareVec.x == 0 && compareVec.y == 0 && compareVec.z == 0;
}

// vector info
double dvec3Length(const dVec3 vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
}
void dvec3Print(const dVec3 vec)
{
	printf("| %f %f %f |\n", vec.x, vec.y, vec.z);
}
