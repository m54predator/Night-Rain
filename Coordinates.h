#ifndef _COORDINATES_H
#define _COORDINATES_H

#include <vector>
#include <SDL_opengl.h>

class Coordinates
{
public:
	void SetCoordinates(double _x, double _y, double _z);
	void SetCoordinates(double _x, double _y);
	void SetCoordinates(double _x);
	void Clear();

	std::vector<GLdouble> x, y, z;
};

#endif
