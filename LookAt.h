#ifndef _LOOKAT_H
#define _LOOKAT_H

#include <vector>

#include "SDL_opengl.h"

class LookAt
{
public:
	static void LookAt_Set(std::vector<GLfloat> &matrix, std::vector<GLfloat> eyePosition3D,
	                std::vector<GLfloat> center3D, std::vector<GLfloat> upVector3D);
private:
	static void MultiplyMatrices(std::vector<GLfloat> &result, std::vector<GLfloat> matrix1, std::vector<GLfloat> matrix2);
	static void Translate(std::vector<GLfloat> &matrix, GLfloat x, GLfloat y, GLfloat z);
	static void ComputeNormalOfPlane
		(std::vector<GLfloat> &normal, const std::vector<GLfloat> &pvector1, const std::vector<GLfloat> &pvector2);
	static void NormalizeVector(std::vector<GLfloat> &pvector);
};

#endif
