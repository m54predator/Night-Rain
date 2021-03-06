#ifndef _DATA_H
#define _DATA_H

#include "Window.h"

class Data
{
public:
	bool run = false;
	Sint32 mouse_motion_x, mouse_motion_y, mouse_click_x, mouse_click_y, mouse_wheel;
	Uint32 _tick = 0;
	std::vector<std::shared_ptr<Window>> windows;
};

#endif
