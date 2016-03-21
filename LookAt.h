#ifndef _LOOKAT_H
#define _LOOKAT_H
#include <vector>
#include "SDL.h"
#include "SDL_opengl.h"

#pragma once
class LookAt
{
public:
	LookAt();
	~LookAt();
	void LookAt_Set(std::vector<GLfloat> &matrix, std::vector<GLfloat> eyePosition3D,
		std::vector<GLfloat> center3D, std::vector<GLfloat> upVector3D);
private:
	void MultiplyMatrices(std::vector<GLfloat> &result, std::vector<GLfloat> matrix1, std::vector<GLfloat> matrix2);
	void Translate(std::vector<GLfloat> &matrix, GLfloat x, GLfloat y, GLfloat z);
	void ComputeNormalOfPlane(std::vector<GLfloat> &normal, const std::vector<GLfloat> pvector1, const std::vector<GLfloat> pvector2);
	void NormalizeVector(std::vector<GLfloat> &pvector);

};

#endif