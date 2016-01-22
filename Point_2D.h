#pragma once
#include "Scene_Object.h"

class Point_2D
	: public Scene_Object
{
public:
	Point_2D();
	Point_2D(GLfloat x, GLfloat y, RGBA _color);
	~Point_2D();
	void Render();
	void Change_Color(const RGBA &_color);
	void Change_Coordinats(const Coordinates &_coord);
	void Change_Coordinats(GLfloat x, GLfloat y);
	void Change_Size(GLfloat _size);
private:
	GLfloat size;
};
