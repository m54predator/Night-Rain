#include "Graphic_2D.h"


Graphic_2D::Graphic_2D()
{
	color.Set_RGBA(1, 1, 1, 1);
	coord.x.push_back(0);
	coord.y.push_back(0);
	size_x = size_y = 10;
	size_step = 0.1;
	size_segment = 0.02;
}


Graphic_2D::~Graphic_2D()
{
	size_t i, size = scene_objects.size();
	for (i = 0; i < size; i++)
		delete scene_objects[i];
}

void Graphic_2D::Render()
{
	size_t i, size;

	Draw_Coordinat();

	size = scene_objects.size();
	for (i = 0; i < size; i++)
		scene_objects[i]->Render();
}


void Graphic_2D::Change_Color(const RGBA &_color)
{
	color = _color;
}

void Graphic_2D::Change_Coordinats(const Coordinates &_coord)
{
	coord = _coord;
}

void Graphic_2D::Change_Size(GLfloat _x, GLfloat _y, GLfloat _step)
{
	size_x = _x;
	size_y = _y;
	size_step = _step;
}

void Graphic_2D::Draw_Line(GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2, const RGBA &_color){
	glColor3f(_color.r, _color.g, _color.b);
	glBegin(GL_LINES);
	glVertex2d(x1, y1);
	glVertex2d(x2, y2);
	glEnd();
}

void Graphic_2D::Draw_Coordinat()
{
	GLfloat i;
	Draw_Line(size_x, -size_x, 0, 0, color);
	Draw_Line(0, 0, size_y, -size_y, color);
	i = -size_x;
	while (i <= size_x)
	{
		Draw_Line(i, i, -size_segment, size_segment, color);
		i += size_step;
	}

	i = -size_y;
	while (i <= size_y)
	{
		Draw_Line(-size_segment, size_segment, i, i, color);
		i += size_step;
	}
}

void Graphic_2D::Set_Object(Scene_Object *_scene_object)
{
	scene_objects.push_back(_scene_object);
}

void Graphic_2D::Set_Point(GLfloat x, GLfloat y, const RGBA &_color)
{
	Point_2D *_point = new Point_2D(x, y, _color);
	Set_Object(_point);
}

void Graphic_2D::Set_Points(std::vector<Point_2D*> _points, const RGBA &_color)
{
	size_t i, size;
	size = _points.size();
	for (i = 0; i < size; i++)
		Set_Object(_points[i]);
}
