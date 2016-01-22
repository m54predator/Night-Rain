#pragma once

// Class, engine core
#include <SDL.h>
#include <SDL_opengl.h>

#include "Window.h"
#include <vector>
//#include "Spline.h"

class Core
{
public:
	std::vector<Window *> windows;

	Core();
	Core(std::fstream &in);
	~Core();

	Window *Create_window();
	void Run();

private:
	std::string core_info, path_proj, engine_mode;
	Window *win;

	void Search(std::string info, std::fstream &in);
};