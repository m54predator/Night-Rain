#pragma once
#include "Window.h"

class Win_err :
	public Window
{
public:
	Win_err();
	Win_err(std::iostream &in, const char *text);
	virtual ~Win_err();
	void Create();
	void init();
	void Create(std::string str);
	void Display();
	void Mouse(int button, int state, int x, int y);

protected:

private:
	std::string err_txt;
};

