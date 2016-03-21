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
	Event_Manager();
	~Event_Manager();
	NR_event<User_Data> *Set_event(Callback<Data *, User_Data *> *_function);
	NR_event<User_Data> *Set_event(Callback<Data *, User_Data *> *_function, int _timer);
	NR_event<User_Data> *Set_user_event(Callback<Data *, User_Data *> *_function, Uint32 _key, User_Data *_user_data);
	void Cheack(Data *_data, User_Data *_user_data);
};
#endif
