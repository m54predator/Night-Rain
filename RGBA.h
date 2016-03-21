#ifndef _RGBA_H
#define _RGBA_H

#include <SDL_opengl.h>

class RGBA
{
public:
	RGBA();
	~RGBA();

	GLfloat r, g, b, a;
	RGBA &operator=(const RGBA &left)
	{
		if (this != &left) {
			r = left.r;
			g = left.g;
			b = left.b;
			a = left.a;
		}

		return *this;
	}
	void Set_RGBA(GLfloat _r, GLfloat _g, GLfloat _b, GLfloat _a);
	void Set_RGBA(GLfloat _x);
};
#endif