#include "../include/lina.h"

// scaling
Mat4 mat4ScaledX(const Mat4 mat, const float scalar)
{
	Mat4 transformation = mat4Identity();
	transformation.ihat.x = scalar;
	return mat4MultMat(transformation, mat);
}
Mat4 mat4ScaledY(const Mat4 mat, const float scalar)
{
	Mat4 transformation = mat4Identity();
	transformation.jhat.y = scalar;
	return mat4MultMat(transformation, mat);
}
Mat4 mat4ScaledZ(const Mat4 mat, const float scalar)
{
	Mat4 transformation = mat4Identity();
	transformation.khat.z = scalar;
	return mat4MultMat(transformation, mat);
}
Mat4 mat4ScaledW(const Mat4 mat, const float scalar)
{
	Mat4 transformation = mat4Identity();
	transformation.lhat.w = scalar;
	return mat4MultMat(transformation, mat);
}
Mat4 mat4Scaled(const Mat4 mat, const float scalar)
{
	Mat4 transformation = mat4Diagonalize(scalar);
	transformation.lhat.w = 1; // do not scale w components
	return mat4MultMat(transformation, mat);
}

// rotating
Mat4 mat4Rotated(const Mat4 mat, const double radians, const Vec3 axis)
{
	Mat4 transformation = mat4Identity();
	transformation.ihat.xyz = vec3Rotated(transformation.ihat.xyz, radians, axis);
	transformation.jhat.xyz = vec3Rotated(transformation.jhat.xyz, radians, axis);
	transformation.khat.xyz = vec3Rotated(transformation.khat.xyz, radians, axis);

	return mat4MultMat(transformation, mat);
}
Mat4 mat4Pitch(const Mat4 mat, const double radians)
{
	Mat4 transformation = mat4Rotated(mat4Identity(), radians, vec3(1,0,0));
	return mat4MultMat(transformation, mat);
}
Mat4 mat4Yaw(const Mat4 mat, const double radians)
{
	Mat4 transformation = mat4Rotated(mat4Identity(), radians, vec3(0,1,0));
	return mat4MultMat(transformation, mat);
}
Mat4 mat4Roll(const Mat4 mat, const double radians)
{
	Mat4 transformation = mat4Rotated(mat4Identity(), radians, vec3(0,0,1));
	return mat4MultMat(transformation, mat);
}

// reflecting
Mat4 mat4ReflectedYZ(const Mat4 mat)
{
	Mat4 transformation = mat4Identity();
	transformation.ihat = vec4Negated(transformation.ihat);
	return mat4MultMat(transformation, mat);
}
Mat4 mat4ReflectedZY(const Mat4 mat) { return mat4ReflectedYZ(mat); }

Mat4 mat4ReflectedZX(const Mat4 mat)
{
	Mat4 transformation = mat4Identity();
	transformation.jhat = vec4Negated(transformation.jhat);
	return mat4MultMat(transformation, mat);
}
Mat4 mat4ReflectedXZ(const Mat4 mat) { return mat4ReflectedZX(mat); }

Mat4 mat4ReflectedXY(const Mat4 mat)
{
	Mat4 transformation = mat4Identity();
	transformation.khat = vec4Negated(transformation.khat);
	return mat4MultMat(transformation, mat);
}
Mat4 mat4ReflectedYX(const Mat4 mat) { return mat4ReflectedXY(mat); }

// shearing
Mat4 mat4ShearedYZ(const Mat4 mat, const float shearAmtY, const float shearAmtZ)
{
	Mat4 transformation = mat4Identity();
	transformation.ihat.yz = vec2(shearAmtY, shearAmtZ);
	return mat4MultMat(transformation, mat);
}
Mat4 mat4ShearedZY(const Mat4 mat, const float shearAmtZ, const float shearAmtY)
	{ return mat4ShearedYZ(mat, shearAmtY, shearAmtZ); }

Mat4 mat4ShearedZX(const Mat4 mat, const float shearAmtZ, const float shearAmtX)
{
	Mat4 transformation = mat4Identity();
	transformation.jhat.xyz = vec3(shearAmtX, 1, shearAmtZ);
	return mat4MultMat(transformation, mat);
}
Mat4 mat4ShearedXZ(const Mat4 mat, const float shearAmtX, const float shearAmtZ)
	{ return mat4ShearedZX(mat, shearAmtZ, shearAmtX); }

Mat4 mat4ShearedXY(const Mat4 mat, const float shearAmtX, const float shearAmtY)
{
	Mat4 transformation = mat4Identity();
	transformation.khat.xy = vec2(shearAmtX, shearAmtY);
	return mat4MultMat(transformation, mat);
}
Mat4 mat4ShearedYX(const Mat4 mat, const float shearAmtY, const float shearAmtX)
	{ return mat4ShearedXY(mat, shearAmtX, shearAmtY); }

// translating
Mat4 mat4Translate(const Mat4 mat, const Vec3 translation)
{
	Mat4 transformation = mat4Identity();
	transformation.lhat.xyz = translation;
	return mat4MultMat(transformation, mat);
}
Mat4 mat4TranslateV(const Mat4 mat, const Vec3 translation) { return mat4Translate(mat, translation); }
Mat4 mat4TranslateF(const Mat4 mat, const float x, const float y, const float z)
{
	return mat4Translate(mat, vec3(x, y, z));
}

