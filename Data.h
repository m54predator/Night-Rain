#pragma once

#include "Window.h"

class Data
{
public:
	Data();
	~Data();
	bool run;
	Sint32 mouse_motion_x, mouse_motion_y;
	Uint32 _tick;
	std::vector<Window *> windows;
};

