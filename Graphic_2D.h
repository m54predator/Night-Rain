#pragma once
#include "Scene_Object.h"
#include "Point_2D.h"
#include "Function_2D.h"
class Graphic_2D :
	public Scene_Object
{
public:
	Graphic_2D();
	~Graphic_2D();
	void Render();
	void Change_Color(RGBA _color);
	void Change_Coordinats(Coordinates _coord);
	void Change_Size(GLfloat _x, GLfloat _y, GLfloat _step);
	void Set_Object(Scene_Object *_scene_object);
	void Set_Point(GLfloat x, GLfloat y, RGBA _color);
	void Set_Points(std::vector<Point_2D*> _points, RGBA _color);

private:
	void Draw_Line(GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2, RGBA _color);
	GLdouble size_x, size_y, size_step, size_segment;
	std::vector<Scene_Object*> scene_objects;
	void Draw_Coordinat();
};

