#ifndef _WINDOW_H
#define _WINDOW_H

#include <fstream>
#include <iostream> 
#include <string>
#include "Scene.h"

class Window
{
public:
	Scene *main_scene;

	Window();
	Window(std::iostream &in);
	virtual ~Window();

	virtual void Create() = 0;
	void Reshape(int Wid, int Heig);
	virtual void Display() = 0;
	//virtual void Mouse(int button, int state, int x, int y) abstract;
	virtual void init() = 0;
	void Close();
	void Run();

protected:
	int Wind_x, Wind_y, Wind_Wd, Wind_Hg;
	SDL_Window *Wind_reference;
	SDL_GLContext glcontext;
	std::string window_name;

	void PrintString(void *font, std::string str);
private:

	std::string window_info, window_value;

	void Search(const std::string &info, std::iostream &in);
	void Default();
};

#endif
