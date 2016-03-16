#pragma once

#include "Window.h"

class Data
{
public:
	bool run = false;
	Sint32 mouse_motion_x, mouse_motion_y;
	Uint32 _tick = 0;
	std::vector<Window *> windows;
};
