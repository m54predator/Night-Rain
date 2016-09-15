#ifndef _COORDINATES_H
#define _COORDINATES_H

#include <SDL_opengl.h>
#include <vector>

class Coordinates
{
public:
	Coordinates() = default;
	Coordinates(std::vector<GLfloat> &&x, std::vector<GLfloat> &&y, std::vector<GLfloat> &&z);
	~Coordinates() = default;
	void Resize(int _size);
	void SetCoordinates(GLfloat _x, GLfloat _y, GLfloat _z);
	void SetCoordinates(GLfloat _x, GLfloat _y);
	void SetCoordinates(GLfloat _x);
	void Clear();

	std::vector<GLfloat> x, y, z;
};

#endif
