#ifndef _RGBA_H
#define _RGBA_H

#include <SDL_opengl.h>

class RGBA
{
public:
	RGBA();

	void Set_RGBA(GLfloat _r, GLfloat _g, GLfloat _b, GLfloat _a);
	void Set_RGBA(GLfloat _x);

	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat a;
};

#endif
