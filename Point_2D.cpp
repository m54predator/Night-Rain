#include "Point_2D.h"


Point_2D::Point_2D()
{
	coord.x.push_back(0);
	coord.y.push_back(0);
	size = 5;
}

Point_2D::Point_2D(GLfloat x, GLfloat y, RGBA _color)
{
	coord.x.push_back(x);
	coord.y.push_back(y);
	color = _color;
	size = 5;
}

Point_2D::~Point_2D()
{
}

void Point_2D::Change_Color(const RGBA &_color)
{
	color = _color;
}

void Point_2D::Change_Coordinats(const Coordinates &_coord)
{
	coord = _coord;
}

void Point_2D::Change_Coordinats(GLfloat x, GLfloat y)
{
	if (coord.x.size() > 0) coord.x[0] += x; else coord.x.push_back(x);
	if (coord.y.size() > 0) coord.y[0] += y; else coord.y.push_back(y);
}

void Point_2D::Set_Coordinats(GLfloat x, GLfloat y)
{
	if (coord.x.size() > 0) coord.x[0] = x; else coord.x.push_back(x);
	if (coord.y.size() > 0) coord.y[0] = y; else coord.y.push_back(y);
}

void Point_2D::Change_Size(GLfloat _size)
{
	size = _size;
}

void Point_2D::Render()
{
	glColor3f(color.r, color.g, color.b);
	glPointSize(size);
	glBegin(GL_POINTS);
	glVertex2f(coord.x[0], coord.y[0]);
	glEnd();
}
