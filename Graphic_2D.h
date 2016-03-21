#ifndef _GRAPHIC_2D_H
#define _GRAPHIC_2D_H

#include "Scene_Object.h"
#include "Point_2D.h"
#include "Function_2D.h"
class Graphic_2D:
	public Scene_Object
{
public:
	Graphic_2D();
	~Graphic_2D();
	void Render();
	void Change_Color(const RGBA &_color);
	void Change_Coordinats(const Coordinates &_coord);
	void Change_Size(GLfloat _x, GLfloat _y, GLfloat _step);
	void Set_Object(Scene_Object *_scene_object);
	void Set_Point(GLfloat x, GLfloat y, const RGBA &_color);
	void Set_Points(std::vector<Point_2D *> _points, const RGBA &_color);

private:
	void Draw_Line(GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2, const RGBA &_color);
	GLdouble size_x, size_y, size_step, size_segment;
	std::vector<Scene_Object *> scene_objects;
	void Draw_Coordinat();
};

#endif
