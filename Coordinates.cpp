#include "Coordinates.h"

void Coordinates::SetCoordinates(double _x, double _y, double _z)
{
	x.push_back(static_cast<float>( _x));
	y.push_back(static_cast<float>( _y));
	z.push_back(static_cast<float>( _z));
}

void Coordinates::SetCoordinates(double _x, double _y)
{
	x.push_back(static_cast<float>( _x));
	y.push_back(static_cast<float>( _y));
}

void Coordinates::SetCoordinates(double _x)
{
	x.push_back(static_cast<float>( _x));
	y.push_back(static_cast<float>( _x));
	z.push_back(static_cast<float>( _x));
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