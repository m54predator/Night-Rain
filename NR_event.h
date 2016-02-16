#pragma once
#include "SDL.h"
#include "Callback.h"
#include "Data.h"

class NR_event
{
public:
	int timer;
	Uint32 key;
	bool run;
	Callback<Data*> *function;
	NR_event();
	~NR_event();
	void Create(Callback<Data*> *_function);
	void Create(Callback<Data*> *_function, int _timer);
	void Create(Callback<Data*> *_function, Uint32 _key);
};

