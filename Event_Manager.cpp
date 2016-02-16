#include "Event_Manager.h"


Event_Manager::Event_Manager()
{
}


Event_Manager::~Event_Manager()
{
}

NR_event* Event_Manager::Set_event(Callback<Data*> *_function)
{
	NR_event *newEvent = new NR_event();
	newEvent->Create(_function);
	Eventlist.push_back(newEvent);
	return newEvent;
}

NR_event* Event_Manager::Set_event(Callback<Data*> *_function, int _timer)
{
	NR_event *newEvent = new NR_event();
	newEvent->Create(_function, _timer);
	Eventlist.push_back(newEvent);
	return newEvent;
}

NR_event* Event_Manager::Set_user_event(Callback<Data*> *_function, Uint32 _key)
{
	NR_event *newEvent = new NR_event();
	newEvent->Create(_function, _key);
	User_Event_List.push_back(newEvent);
	return newEvent;
}

void Event_Manager::Cheack(Data *_data)
{
	size_t i, n = User_Event_List.size();
	while (SDL_PollEvent(&event)){
		if (event.type == SDL_KEYDOWN)
		for (i = 0; i < n; i++)
			if ((User_Event_List[i]->run) && (User_Event_List[i]->key == event.key.keysym.sym)) User_Event_List[i]->function->operator()(_data);
	}

	n = Eventlist.size();
	for (i = 0; i < n; i++)
		if ((Eventlist[i]->timer) && (Eventlist[i]->run) && (_data->_tick % Eventlist[i]->timer == 0)) Eventlist[i]->function->operator()(_data);

}
