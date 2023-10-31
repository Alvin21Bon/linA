#include "../include/aglm.h"

void fillMat3(const Vec3 column1, const Vec3 column2, const Vec3 column3, Mat3 outputMatrix);

void fillMat3WithFloats(const float col1row1, const float col2row1, const float col3row1, 
			const float col1row2, const float col2row2, const float col3row2,
			const float col1row3, const float col2row3, const float col3row3,
			Mat3 outputMatrix);

void zeroMat3(Mat3 zeroedMatrix);
void copyMat3(const Mat3 inputMatrix, Mat3 copyIntoMatrix);
void fillIdentityMat3(Mat3 outputMatrix);
void transposeMat3(Mat3 transposedMatrix);

void multMat3Vec(const Mat3 transformedSpace, Vec3 transformedVector);

void productOfMat3Vecs(const Mat3 transformedSpace, const size_t numOfVectors, ...);

void multMat3Mat(const Mat3 transformedSpace, Mat3 transformedMatrix);

void printMat3(const Mat3 matrixToPrint);
