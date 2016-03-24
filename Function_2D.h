#ifndef _FUNCTION_2D_H
#define _FUNCTION_2D_H

#include "Scene_Object.h"

class Function_2D: public Scene_Object
{
public:
	void Render() override;
	void Change_Color(const RGBA &_color) override;
	void Change_Coordinates(const Coordinates &_coord) override;

private:
	void Draw_Line(GLfloat x1, GLfloat x2, GLfloat y1, GLfloat y2, const RGBA &_color);
};

#endif
