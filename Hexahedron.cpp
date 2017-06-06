#include "Hexahedron.h"
#include "lodepng/lodepng.h"

Hexahedron::Hexahedron() :Hexahedron(0, 0, 1, 1) {};

Hexahedron::Hexahedron(GLfloat _x, GLfloat _y, GLfloat _hight, GLfloat _width) :Hexahedron(_x, _y, 0, _hight, _width){}

Hexahedron::Hexahedron(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _hight, GLfloat _width) :x(_x), y(_y), z(_z),
hight(_hight), width(_width)
{
	Coordinates coord;
	for (size_t i = 0; i < 6; i++)
		polygons.push_back(std::make_shared<Polygon_3D>());

	//
	coord.SetCoordinates(-hight + x, -width + z, -hight + y);
	coord.SetCoordinates(hight + x, -width + z, -hight + y);
	coord.SetCoordinates(hight + x, width + z, -hight + y);
	coord.SetCoordinates(-hight + x, width + z, -hight + y);
	polygons[0]->Change_Coordinates(coord);
	//
	coord.Clear();
	coord.SetCoordinates(-hight + x, -width + z, hight + y);
	coord.SetCoordinates(-hight + x, -width + z, -hight + y);
	coord.SetCoordinates(-hight + x, width + z, -hight + y);
	coord.SetCoordinates(-hight + x, width + z, hight + y);
	polygons[1]->Change_Coordinates(coord);
	//
	coord.Clear();
	coord.SetCoordinates(hight + x, -width + z, -hight + y);
	coord.SetCoordinates(hight + x, -width + z, hight + y);
	coord.SetCoordinates(hight + x, width + z, hight + y);
	coord.SetCoordinates(hight + x, width + z, -hight + y);
	polygons[2]->Change_Coordinates(coord);
	//
	coord.Clear();
	coord.SetCoordinates(hight + x, -width + z, hight + y);
	coord.SetCoordinates(-hight + x, -width + z, hight + y);
	coord.SetCoordinates(-hight + x, width + z, hight + y);
	coord.SetCoordinates(hight + x, width + z, hight + y);
	polygons[3]->Change_Coordinates(coord);
	//
	coord.Clear();
	coord.SetCoordinates(hight + x, -width + z, hight + y);
	coord.SetCoordinates(hight + x, -width + z, -hight + y);
	coord.SetCoordinates(-hight + x, -width + z, -hight + y);
	coord.SetCoordinates(-hight + x, -width + z, hight + y);
	polygons[4]->Change_Coordinates(coord);
	//
	coord.Clear();
	coord.SetCoordinates(-hight + x, width + z, hight + y);
	coord.SetCoordinates(-hight + x, width + z, -hight + y);
	coord.SetCoordinates(hight + x, width + z, -hight + y);
	coord.SetCoordinates(hight + x, width + z, hight + y);
	polygons[5]->Change_Coordinates(coord);
}

Hexahedron::~Hexahedron()
{
	_texture_id.reset();
	polygons.clear();
}


bool Hexahedron::Change_Texture(const std::string &filename)
{
	bool fl = 0;
	for (size_t i = 0; i < polygons.size(); i++) {
		if (polygons[i]->Change_Texture(filename)) {
			fl = 1;
		};
	}
	return fl;
}

bool Hexahedron::Change_Texture(const std::vector<unsigned char> &data, size_t _w, size_t _h)
{
	bool fl = 0;
	for (size_t i = 0; i < polygons.size(); i++) {
		if (polygons[i]->Change_Texture(data, _w, _h)) {
			fl = 1;
		};
	}
	return fl;
}

bool Hexahedron::Change_Texture(void *data, size_t _w, size_t _h)
{
	bool fl = 0;
	for (size_t i = 0; i < polygons.size(); i++) {
		if (polygons[i]->Change_Texture(data, _w, _h)) {
			fl = 1;
		};
	}
	return fl;
}

bool Hexahedron::Change_Texture(const Polygon_3D &_polygon)
{
	bool fl = 0;
	for (size_t i = 0; i < polygons.size(); i++) {
		if (polygons[i]->Change_Texture(_polygon)) {
			fl = 1;
		};
	}
	return fl;
}

void Hexahedron::Change_Color(const RGBA &_color)
{
	for (size_t i = 0; i < polygons.size(); i++) {
		polygons[i]->Change_Color(_color);
	}
}

void Hexahedron::Change_Coordinates(const Coordinates &_coord)
{
	for (size_t i = 0; i < polygons.size(); i++) {
		polygons[i]->Change_Coordinates(_coord);
	}
}

void Hexahedron::Swap_Coordinates(std::vector<GLfloat> &x, std::vector<GLfloat> &y, std::vector<GLfloat> &z)
{
	for (size_t i = 0; i < polygons.size(); i++) {
		polygons[i]->Swap_Coordinates(x, y, z);
	}
}


void Hexahedron::Render()
{
	for (size_t i = 0; i < polygons.size(); i++) {
		polygons[i]->Render();
	}
}
