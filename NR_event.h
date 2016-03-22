#ifndef _NR_EVENT_H
#define _NR_EVENT_H

#include "SDL.h"
#include "Callback.h"
#include "Data.h"

template<class User_Data_T>
class NR_event
{
public:
	int timer;
	Uint32 key;
	bool run;
	Callback<Data *, User_Data_T *> *function;
	NR_event()
	{ }

	~NR_event()
	{ }

	void Create(Callback<Data *, User_Data_T *> *_function)
	{
		function = _function;
		timer = 1;
		run = true;
	};

	void Create(Callback<Data *, User_Data_T *> *_function, int _timer)
	{
		function = _function;
		timer = _timer;
		run = true;
	};

	void Create(Callback<Data *, User_Data_T *> *_function, Uint32 _key)
	{
		function = _function;
		timer = 0;
		key = _key;
		run = true;
	};
};

#endif
