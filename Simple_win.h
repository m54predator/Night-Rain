#ifndef _SIMPLE_WIN_H
#define _SIMPLE_WIN_H

#include <array>

#include "Window.h"
#include "Scene.h"
#include "Shaders_Handler.h"

class Simple_win :
		public Window
{
public:
	Simple_win();

	virtual void Create();
	virtual void Create(int _wind_x, int _wind_y);
	virtual void Create(int _wind_x, int _wind_y, int _wind_wd, int _wind_hd);
	void init();
	void Display();

private:
	std::array<GLfloat, 16> persp;
	Shaders_Handler shader_handler;
	void Perspective(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat _near, GLfloat _far);
};

#endif
