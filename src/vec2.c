#include "../include/lina.h"

// constructors
Vec2 vec2(const float e1, const float e2)
{
	Vec2 vec;
	vec.elements[0] = e1;
	vec.elements[1] = e2;
	return vec;
}
Vec2 vec2Fill(const float fillValue)
{
	return vec2(fillValue, fillValue);
}
Vec2 vec2Zero()
{
	return vec2Fill(0);
}

// operations
Vec2 vec2Add(const Vec2 left, const Vec2 right)
{
	Vec2 result;
	result.x = left.x + right.x;
	result.y = left.y + right.y;
	return result;
}
Vec2 vec2Sub(const Vec2 left, const Vec2 right)
{
	Vec2 result;
	result.x = left.x - right.x;
	result.y = left.y - right.y;
	return result;
}
float vec2Dot(const Vec2 left, const Vec2 right)
{
	return (left.x * right.x) + (left.y * right.y);	
}
float vec2Cross(const Vec2 left, const Vec2 right)
{
	Mat2 mat = mat2(left, right);
	return mat2Determinant(mat);
}
Vec2 vec2ProjectedLine(const Vec2 vec, const Vec2 line)
{
	Vec2 normLine = vec2Normalized(line);
	float projectionScalar = vec2Dot(normLine, vec);
	return vec2Scaled(normLine, projectionScalar);
}
Vec2 vec2Negated(const Vec2 vec)
{
	return vec2Scaled(vec, -1);
}
Vec2 vec2Scaled(const Vec2 vec, const float scalar)
{
	Vec2 result;
	result.x = vec.x * scalar;
	result.y = vec.y * scalar;
	return result;
}
Vec2 vec2Rotated(const Vec2 vec, const float radians, const Vec3 axis)
{
	// this function will rotate vec through 3d space, then project it back onto the 2d plane
	// if these functions are confusing, look at your rotation notes
	Vec3 vec3D = vec3V(vec, 0);
	Vec3 vecProjectedOnAxis = vec3ProjectedLine(vec3D, axis); 
	
	// we are defining a plane that rests on the tip of the vector and axis of rotation projection point
	// this plane is used to define a new coordinate system that will allow for simple circle calculations
	Vec3 circleIhat = vec3Sub(vec3D, vecProjectedOnAxis);
	Vec3 circleJhat = vec3Cross(axis, circleIhat); // taking cross product with argument due to edge case where the vector projected on the axis is zero vector
	float circleRadius = vec3Length(circleIhat); // getting the radius before normalizing the circle basis vectors
	circleIhat = vec3Normalized(circleIhat);
	circleJhat = vec3Normalized(circleJhat);
	Mat3 circleCoordinateSystem = mat3(circleIhat, circleJhat, vec3Zero());

	// we are now working in our new coordinate system to get the circle coordinates
	float circleX = cos(radians) * circleRadius;
	float circleY = sin(radians) * circleRadius;
	Vec3 circleCoords = vec3(circleX, circleY, 0);

	// this is essentially just change of basis work
	Vec3 circleCoordsInOurCoordinateSystem = mat3MultVec(circleCoordinateSystem, circleCoords);

	Vec3 result = vec3Add(vecProjectedOnAxis, circleCoordsInOurCoordinateSystem);
	return result.xy; // projected back onto 2d plane
}
Vec2 vec2Normalized(const Vec2 vec)
{
	float scalar = 1 / vec2Length(vec);
	return vec2Scaled(vec, scalar);
}

// vector info
float vec2Length(const Vec2 vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}
