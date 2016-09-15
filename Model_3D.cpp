#include "Model_3D.h"

Model_3D::Model_3D()
{
	coord.x.resize(4, 0);
	coord.y.resize(4, 0);
	coord.z.resize(4, 0);
}

Model_3D::~Model_3D()
{
}


void Model_3D::Change_Color(const RGBA &_color)
{
	color = _color;
}

void Model_3D::Change_Coordinates(const Coordinates &_coord)
{
	coord = _coord;
}

void Model_3D::Render()
{
	for (auto &elm : polygons)
		elm.Render();
}

void Model_3D::Add_Polygon(std::vector<GLfloat> &x, std::vector<GLfloat> &y, std::vector<GLfloat> &z)
{
	polygons.resize(polygons.size() + 1);
	polygons.back().Swap_Coordinates(x, y, z);
}