#include "Event_Manager.h"


Event_Manager::Event_Manager()
{
}


Event_Manager::~Event_Manager()
{
}

NR_event* Event_Manager::Set_event(Callback *_function)
{
	NR_event *newevent = new NR_event();
	newevent->Create(_function);
	Eventlist.push_back(newevent);
	return newevent;
}

NR_event* Event_Manager::Set_event(Callback *_function, int _timer)
{
	NR_event *newevent = new NR_event();
	newevent->Create(_function, _timer);
	Eventlist.push_back(newevent);
	return newevent;
}

NR_event* Event_Manager::Set_user_event(Callback *_function, Uint32 _key)
{
	NR_event *newevent = new NR_event();
	newevent->Create(_function, _key);
	User_Event_List.push_back(newevent);
	return newevent;
}

void Event_Manager::Cheack(int _tick)
{
	size_t i, n = User_Event_List.size();
	while (SDL_PollEvent(&event)){
		if (event.type == SDL_KEYDOWN) 
		for (i = 0; i < n; i++)
			if ((User_Event_List[i]->run) && (User_Event_List[i]->key == event.key.keysym.sym)) User_Event_List[i]->function->operator()(_tick);
	}

	n = Eventlist.size();
	for (i = 0; i < n; i++)
		if ((Eventlist[i]->timer) && (Eventlist[i]->run) && (_tick % Eventlist[i]->timer == 0)) Eventlist[i]->function->operator()(_tick);
	
}
