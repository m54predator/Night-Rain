#include "Win_err.h"
#include "Simple_win.h"
#pragma once
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

