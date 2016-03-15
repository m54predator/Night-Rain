#include "Coordinates.h"


Coordinates::Coordinates()
{
}

Coordinates::~Coordinates()
{
	Clear();
}

void Coordinates::SetCoordinates(double _x, double _y, double _z)
{
	x.push_back(_x);
	y.push_back(_y);
	z.push_back(_z);
}

void Coordinates::SetCoordinates(double _x, double _y)
{
	x.push_back(_x);
	y.push_back(_y);
}

void Coordinates::SetCoordinates(double _x)
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