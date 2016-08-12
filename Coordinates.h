#ifndef _COORDINATES_H
#define _COORDINATES_H

#include <SDL_opengl.h>
#include <vector>

class Coordinates
{
public:
	void Resize(int _size);
	void SetCoordinates(double _x, double _y, double _z);
	void SetCoordinates(double _x, double _y);
	void SetCoordinates(double _x);
	void Clear();

	std::vector<GLdouble> x, y, z;
};

#endif
