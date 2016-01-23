#pragma once
#include "SDL.h"
#include "Callback.h"
class NR_event
{
public:
	int timer;
	Uint32 key;
	bool run;
	Callback *function;
	NR_event();
	~NR_event();
	void Create(Callback *_function);
	void Create(Callback *_function, int _timer);
	void Create(Callback *_function, Uint32 _key);
};

