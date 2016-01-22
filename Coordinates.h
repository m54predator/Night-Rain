#pragma once

#include <vector>
#include <SDL.h>
#include <SDL_opengl.h>

class Coordinates
{
public:
	Coordinates();
	~Coordinates();

	std::vector<GLfloat> x, y, z;

	Coordinates &operator=(const Coordinates &rhs)
	{
		if (this != &rhs) {
			x = rhs.x;
			y = rhs.y;
			z = rhs.z;
		}
		return *this;
	}

	void SetCoordinates(double _x, double _y, double _z);
	void SetCoordinates(double _x, double _y);
	void SetCoordinates(double _x);
	void Clear();
};
