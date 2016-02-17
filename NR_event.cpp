#include "NR_event.h"


NR_event<class User_Data>::NR_event()
{
}


NR_event<class User_Data>::~NR_event()
{
}

void NR_event<class User_Data>::Create(Callback<Data*, User_Data*> *_function)
{
	function = _function;
	timer = 1; run = true;
}

void NR_event<class User_Data>::Create(Callback<Data*, User_Data*> *_function, int _timer)
{
	function = _function;
	timer = _timer; 
	run = true;
}

void NR_event<class User_Data>::Create(Callback<Data*, User_Data*> *_function, Uint32 _key)
{
	function = _function;
	timer = 0;
	key = _key;
	run = true;
}