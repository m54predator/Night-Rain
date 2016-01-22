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
	virtual void Create(int x, int y);
	void init();
	void Display();

	void Mouse(int button, int state, int x, int y);
	void KeyBoard(unsigned char key, int x, int y);

private:
	std::string *err_txt;
};
