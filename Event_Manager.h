#ifndef _EVENT_MANAGER_H
#define _EVENT_MANAGER_H

#include <vector>
#include "NR_event.h"

template<class User_Data>
class Event_Manager
{
public:
	SDL_Event event;
	std::vector<NR_event<User_Data> *> Eventlist, User_Event_List;
	Event_Manager(){}
	~Event_Manager(){}
	NR_event<User_Data> *Set_event(Callback<Data *, User_Data *> *_function)
	{
		NR_event<User_Data> *newEvent = new NR_event<User_Data>();
		newEvent->Create(_function);
		Eventlist.push_back(newEvent);
		return newEvent;
	};
	NR_event<User_Data> *Set_event(Callback<Data *, User_Data *> *_function, int _timer)
	{
		NR_event<User_Data> *newEvent = new NR_event<User_Data>();
		newEvent->Create(_function, _timer);
		Eventlist.push_back(newEvent);
		return newEvent;
	};
	NR_event<User_Data> *Set_user_event(Callback<Data *, User_Data *> *_function, Uint32 _key, User_Data *_user_data)
	{
		NR_event<User_Data> *newEvent = new NR_event<User_Data>();
		newEvent->Create(_function, _key);
		User_Event_List.push_back(newEvent);
		return newEvent;
	};
	void Cheack(Data *_data, User_Data *_user_data)
	{
		size_t i, n = User_Event_List.size();


		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN)
				for (i = 0; i < n; i++)
					if ((User_Event_List[i]->run) && (User_Event_List[i]->key == event.key.keysym.sym))
						User_Event_List[i]->function->operator()(_data, _user_data);
			if (event.type == SDL_MOUSEMOTION) {
				_data->mouse_motion_x = event.motion.xrel;
				_data->mouse_motion_y = event.motion.yrel;

				for (i = 0; i < n; i++)
					if ((User_Event_List[i]->run) && (User_Event_List[i]->key == SDL_MOUSEMOTION))
						User_Event_List[i]->function->operator()(_data, _user_data);
			}

		}

		n = Eventlist.size();
		for (i = 0; i < n; i++)
			if ((Eventlist[i]->timer) && (Eventlist[i]->run) && (_data->_tick % Eventlist[i]->timer == 0))
				Eventlist[i]->function->operator()(_data, _user_data);

	};
};

#endif
