#ifndef _FUNCTION_2D_H
#define _FUNCTION_2D_H

#include "Scene_Object.h"

class Function_2D: public Scene_Object
{
public:
	Function_2D();
	~Function_2D();
	void Render();
	void Change_Color(const RGBA &_color);
	void Change_Coordinats(const Coordinates &_coord);
private:
	void Draw_Line(GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2, const RGBA &_color);
};

#endif
