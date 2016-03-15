#pragma once
#include "Window.h"
#include "Scene.h"

class Simple_win
	: public Window
{
public:
	Simple_win();
	virtual ~Simple_win();
	virtual void Create();
	virtual void Create(int _wind_x, int _wind_y);
	virtual void Create(int _wind_x, int _wind_y, int _wind_wd, int _wind_hd);
	void init();
	void Display();

	void Mouse(int button, int state, int x, int y);
	void KeyBoard(unsigned char key, int x, int y);

private:
	std::string *err_txt;
	GLfloat *persp;
	void Perspective(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat _near, GLfloat _far);
};
