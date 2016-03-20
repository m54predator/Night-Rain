#include "LookAt.h"
#include "SDL.h"
#include "SDL_opengl.h"
#include <cmath>
#include <vector>

LookAt::LookAt()
{
}


LookAt::~LookAt()
{
}


void LookAt::MultiplyMatrices(std::vector<GLfloat> *result, std::vector<GLfloat> matrix1, std::vector<GLfloat> matrix2)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				(*result)[i + j*4] += matrix1[i + k*4] * matrix2[k + j*4];
}

void LookAt::Translate(std::vector<GLfloat> *matrix, GLfloat x, GLfloat y, GLfloat z)
{
	for (int i = 0; i < 4; i++)
		(*matrix)[i + 12] = (*matrix)[i] * x + (*matrix)[i + 4] * y + (*matrix)[i + 8] * z + (*matrix)[i + 12];
}

void LookAt::ComputeNormalOfPlane(std::vector<GLfloat> *normal, const std::vector<GLfloat> pvector1, const std::vector<GLfloat> pvector2)
{
	(*normal)[0] = (pvector1[1] * pvector2[2]) - (pvector1[2] * pvector2[1]);
	(*normal)[1] = (pvector1[2] * pvector2[0]) - (pvector1[0] * pvector2[2]);
	(*normal)[2] = (pvector1[0] * pvector2[1]) - (pvector1[1] * pvector2[0]);
}


void LookAt::NormalizeVector(std::vector<GLfloat> *pvector)
{
	GLfloat normalizingConstant;
	int i;
	normalizingConstant = 0;
	for (i = 0; i < 3; i++)
		normalizingConstant += std::pow((*pvector)[i], 2);
	normalizingConstant = 1.0 / sqrt(normalizingConstant);
	for (i = 0; i < 3; i++)
		(*pvector)[i] *= normalizingConstant;
}

void LookAt::LookAt_Set(std::vector<GLfloat> *matrix, std::vector<GLfloat> eyePosition3D,
	std::vector<GLfloat> center3D, std::vector<GLfloat> upVector3D)
{
	std::vector<GLfloat> forward, side, up, matrix2, resultMatrix;

	forward.resize(3);
	side.resize(3);
	up.resize(3);
	matrix2.resize(16);
	resultMatrix.resize(16);
	//------------------
	forward[0] = center3D[0] - eyePosition3D[0];
	forward[1] = center3D[1] - eyePosition3D[1];
	forward[2] = center3D[2] - eyePosition3D[2];
	NormalizeVector(&forward);
	//------------------
	//Side = forward x up
	ComputeNormalOfPlane(&side, forward, upVector3D);
	NormalizeVector(&side);
	//------------------
	//Recompute up as: up = side x forward
	ComputeNormalOfPlane(&up, side, forward);
	//------------------
	matrix2[0] = side[0];
	matrix2[4] = side[1];
	matrix2[8] = side[2];
	matrix2[12] = 0.0;
	//------------------
	matrix2[1] = up[0];
	matrix2[5] = up[1];
	matrix2[9] = up[2];
	matrix2[13] = 0.0;
	//------------------
	matrix2[2] = -forward[0];
	matrix2[6] = -forward[1];
	matrix2[10] = -forward[2];
	matrix2[14] = 0.0;
	//------------------
	matrix2[3] = matrix2[7] = matrix2[11] = 0.0;
	matrix2[15] = 1.0;
	//------------------
	MultiplyMatrices(&resultMatrix, *matrix, matrix2);
	Translate(&resultMatrix,
		-eyePosition3D[0], -eyePosition3D[1], -eyePosition3D[2]);
	//------------------
	*matrix = resultMatrix;
}