#include "../include/aglm.h"

void fillVec3(const float x, const float y, const float z, Vec3 outputVector);

void addVec3(const Vec3 vectorA, const Vec3 vectorB, Vec3 outputVector);
void subtractVec3(const Vec3 vectorA, const Vec3 vectorB, Vec3 outputVector);

void sumOfVec3(Vec3 outputVector, const size_t numOfOperands, ...);
void differenceOfVec3(Vec3 outputVector, const size_t numOfOperands, ...);

void scaleVec3(const float scalar, const Vec3 inputVector, Vec3 ouputVector);
void negVec3(const Vec3 inputVector, Vec3 outputVector);

