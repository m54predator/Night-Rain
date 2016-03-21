#ifndef _NR_EVENT_H
#define _NR_EVENT_H

#include "SDL.h"
#include "Callback.h"
#include "Data.h"

template<class User_Data>
class NR_event
{
public:
	int timer;
	Uint32 key;
	bool run;
	Callback<Data *, User_Data *> *function;
	NR_event();
	~NR_event();
	void Create(Callback<Data *, User_Data *> *_function);
	void Create(Callback<Data *, User_Data *> *_function, int _timer);
	void Create(Callback<Data *, User_Data *> *_function, Uint32 _key);
};

#endif
