#pragma once

// Class, engine core
#include <SDL.h>
#include <SDL_opengl.h>

#include "Window.h"
#include <vector>
//#include "Spline.h"
#include "Win_err.h"
#include "Simple_win.h"
#include "Event_Manager.h"

class Core
{
public:
	std::vector<Window *> windows;

	Core();
	Core(std::fstream &in);
	~Core();

	Window *Create_window();
	Window *Create_window(int x, int y);
	void Run();
	Event_Manager *_event_manager;
	bool run;
	Callback *close_windows_call;
	

private:
	std::string core_info, path_proj, engine_mode;
	Window *win;
	void Close_All_Windows();

	void Search(const std::string &info, std::fstream &in);
};