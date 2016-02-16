#pragma once
#include <vector>
#include "NR_event.h"
//#include <SDL.h>
#include "Window.h"

class Event_Manager
{
public:
	SDL_Event event;
	std::vector<NR_event*> Eventlist, User_Event_List;
	Event_Manager();
	~Event_Manager();
	NR_event* Set_event(Callback<Data*> *_function);
	NR_event* Set_event(Callback<Data*> *_function, int _timer);
	NR_event* Set_user_event(Callback<Data*> *_function, Uint32 _key);
	void Cheack(Data *_data);
};

