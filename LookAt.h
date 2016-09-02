#ifndef _LOOKAT_H
#define _LOOKAT_H

#include <vector>

#include "SDL_opengl.h"

class LookAt
{
public:
	static void LookAt_Set(std::vector<GLfloat> &matrix, const std::vector<GLfloat> &eyePosition3D,
		const std::vector<GLfloat> &center3D, const std::vector<GLfloat> &upVector3D);
private:
	static void
		MultiplyMatrices(std::vector<GLfloat> &result, const std::vector<GLfloat> &matrix1, const std::vector<GLfloat> &matrix2);
	static void Translate(std::vector<GLfloat> &matrix, GLfloat x, GLfloat y, GLfloat z);
	static void ComputeNormalOfPlane
		(std::vector<GLfloat> &normal, const std::vector<GLfloat> &pvector1, const std::vector<GLfloat> &pvector2);
	static void NormalizeVector(std::vector<GLfloat> &pvector);
};

#endif
