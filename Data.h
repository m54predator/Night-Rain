#include "Win_err.h"
#include "Simple_win.h"
#pragma once
class Data
{
public:
	Data();
	~Data();
	bool run;
	Uint32 _tick;
	std::vector<Window *> windows;
};

