#include "RGBA.h"

RGBA::RGBA()
	: r(1), g(1), b(1), a(1)
{ }
RGBA::RGBA(GLfloat _r, GLfloat _g, GLfloat _b, GLfloat _a)
	: r(_r), g(_g), b(_b), a(_a)
{ }

RGBA::RGBA(GLfloat _x)
	: r(_x), g(_x), b(_x), a(_x)
{ }

void RGBA::Set_RGBA(GLfloat _r, GLfloat _g, GLfloat _b, GLfloat _a)
{
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

void RGBA::Set_RGBA(GLfloat _x)
{
	r = g = b = a = _x;
}
