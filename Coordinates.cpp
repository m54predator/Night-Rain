#include "Coordinates.h"

Coordinates::Coordinates(std::vector<GLfloat> &&x, std::vector<GLfloat> &&y, std::vector<GLfloat> &&z)
	:x(x), y(y), z(z)
{}

void Coordinates::SetCoordinates(GLfloat _x, GLfloat _y, GLfloat _z)
{
	x.push_back(_x);
	y.push_back(_y);
	z.push_back(_z);
}

void Coordinates::SetCoordinates(GLfloat _x, GLfloat _y)
{
	x.push_back(_x);
	y.push_back(_y);
}

void Coordinates::SetCoordinates(GLfloat _x)
{
	x.push_back(_x);
	y.push_back(_x);
	z.push_back(_x);
}

void Coordinates::Clear()
{
	x.clear();
	y.clear();
	z.clear();
}

void Coordinates::Resize(int _size)
{
	x.resize(_size);
	y.resize(_size);
	z.resize(_size);
}