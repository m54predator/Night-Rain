#ifndef _POINT_2D_H
#define _POINT_2D_H

#include "Scene_Object.h"

class Point_2D
	: public Scene_Object
{
public:
	Point_2D();
	Point_2D(GLfloat x, GLfloat y, RGBA _color);
	~Point_2D();

	void Render() override;
	void Change_Color(const RGBA &_color) override;
	void Change_Coordinates(const Coordinates &_coord) override;

	void Change_Coordinates(GLfloat x, GLfloat y);
	void Set_Coordinates(GLfloat x, GLfloat y);
	void Change_Size(GLfloat _size);
private:
	GLfloat size;
};

#endif
