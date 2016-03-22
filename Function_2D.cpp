#include "Function_2D.h"
#include <cmath>
#include <algorithm>

Function_2D::Function_2D()
{
}

Function_2D::~Function_2D()
{
}

void Function_2D::Render()
{
	size_t size = std::min(coord.x.size(), coord.y.size());

	glColor3f(color.r, color.g, color.b);
	glBegin(GL_LINES);
	for (size_t i = 0; i < size; i++)
		glVertex2d(coord.x[i], coord.y[i]);
	glEnd();

}

void Function_2D::Change_Color(const RGBA &_color)
{
	color = _color;
}

void Function_2D::Change_Coordinates(const Coordinates &_coord)
{
	coord = _coord;
}

void Function_2D::Draw_Line(GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2, const RGBA &_color)
{
	glColor3f(_color.r, _color.g, _color.b);
	glBegin(GL_LINES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
}
