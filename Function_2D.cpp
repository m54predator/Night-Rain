#include "Function_2D.h"
#include <cmath>

#undef min
#undef max

Function_2D::Function_2D()
{
}


Function_2D::~Function_2D()
{
}



void Function_2D::Render()
{
	size_t i, size;
	size = std::fmin(coord.x.size(), coord.y.size());
	
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_LINES);
	for (i = 0; i < size; i++)
		glVertex2d(coord.x[i], coord.y[i]);
	glEnd();

}

void Function_2D::Change_Color(RGBA _color)
{
	color = _color;
}

void Function_2D::Change_Coordinats(Coordinates _coord)
{
	coord = _coord;
}

void Function_2D::Draw_Line(GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2, RGBA _color){
	glColor3f(_color.r, _color.g, _color.b);
	glBegin(GL_LINES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
}

