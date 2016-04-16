#include "Coordinates.h"

void Coordinates::SetCoordinates(double _x, double _y, double _z)
{
	x.push_back((float) _x);
	y.push_back((float) _y);
	z.push_back((float) _z);
}

void Coordinates::SetCoordinates(double _x, double _y)
{
	x.push_back((float) _x);
	y.push_back((float) _y);
}

void Coordinates::SetCoordinates(double _x)
{
	x.push_back((float) _x);
	y.push_back((float) _x);
	z.push_back((float) _x);
}

void Coordinates::Clear()
{
	x.clear();
	y.clear();
	z.clear();
}
