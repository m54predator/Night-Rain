#include "Polygon_3D.h"
#include "Polygon_3D.h"


Polygon_3D::Polygon_3D()
{
	color.Set_RGBA(1, 1, 1, 1);
	for (int i = 0; i < 4; i++) {
		coord.x.push_back(0);
		coord.y.push_back(0);
		coord.z.push_back(0);
	}
}


Polygon_3D::~Polygon_3D()
{
}

void Polygon_3D::Change_Texture(const std::string &fname)
{
	texture_path = fname;

	//texture = auxDIBImageLoad(texture_path.c_str());
	glGenTextures(1, &texture_referens);
	glBindTexture(GL_TEXTURE_2D, texture_referens);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexImage2D(GL_TEXTURE_2D, 0, 3, texture->sizeX, texture->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture->data);
}

void Polygon_3D::Change_Color(const RGBA &_color)
{
	color = _color;
}

void Polygon_3D::Change_Coordinats(const Coordinates &_coord)
{
	coord = _coord;
}

void Polygon_3D::Render()
{
	size_t i, size;

	glColor3f(color.r, color.g, color.b);
	glBindTexture(GL_TEXTURE_2D, texture_referens);
	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 0.0, 0.0);
	glVertex3f(coord.x[0], coord.y[0], coord.z[0]);
	glTexCoord3f(1.0, 0.0, 4.0);
	glVertex3f(coord.x[1], coord.y[1], coord.z[1]);
	glTexCoord3f(1.0, 1.0, 1.0);
	glVertex3f(coord.x[2], coord.y[2], coord.z[2]);
	glTexCoord3f(0.0, 1.0, 0.0);
	glVertex3f(coord.x[3], coord.y[3], coord.z[3]);
	glEnd();
}
