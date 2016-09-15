#ifndef _EVENT_MANAGER_H
#define _EVENT_MANAGER_H

#include <vector>
#include <memory>
#include "NR_event.h"

template<class User_Data_T>
class EventManager
{
public:
	EventManager() = default;

	~EventManager() = default;

	std::shared_ptr<NR_event<User_Data_T>> Set_event(const std::shared_ptr<std::function<void(Data &, std::shared_ptr<User_Data_T> &)>> &_function)
	{
		std::shared_ptr<NR_event<User_Data_T>> newEvent = std::make_shared<NR_event<User_Data_T>>();
		newEvent->Create(_function);
		EventList.push_back(newEvent);
		return newEvent;
	}

	std::shared_ptr<NR_event<User_Data_T>> Set_event(const std::shared_ptr<std::function<void(Data &, std::shared_ptr<User_Data_T> &)>> &_function, int _timer)
	{
		std::shared_ptr<NR_event<User_Data_T>> newEvent = std::make_shared<NR_event<User_Data_T>>();
		newEvent->Create(_function, _timer);
		EventList.push_back(newEvent);
		return newEvent;
	}

	std::shared_ptr<NR_event<User_Data_T>> Set_user_event(const std::shared_ptr<std::function<void(Data &, std::shared_ptr<User_Data_T> &)>> &_function,
	                                      Uint32 _key,
	                                      std::shared_ptr<User_Data_T> _user_data)
	{
		std::shared_ptr<NR_event<User_Data_T>> newEvent = std::make_shared<NR_event<User_Data_T>>();
		newEvent->Create(_function, _key);
		UserEventList.push_back(newEvent);
		return newEvent;
	}

	void Check(Data &_data, std::shared_ptr<User_Data_T> &_user_data)
	{
		size_t n = UserEventList.size();


		while (SDL_PollEvent(&SDLEvent)) {
			if (SDLEvent.type == SDL_KEYDOWN)
				for (size_t i = 0; i < n; i++)
					if ((UserEventList[i]->run) && (UserEventList[i]->key == SDLEvent.key.keysym.sym))
						UserEventList[i]->function->operator()(_data, _user_data);
			if ((SDLEvent.type >= SDL_MOUSEMOTION) && (SDLEvent.type <= SDL_MOUSEWHEEL))
			{
				_data.mouse_motion_x = SDLEvent.motion.xrel;
				_data.mouse_motion_y = SDLEvent.motion.yrel;
				_data.mouse_click_x = SDLEvent.button.x;
				_data.mouse_click_y = SDLEvent.button.y;
				_data.mouse_wheel = SDLEvent.wheel.y;
				for (size_t i = 0; i < n; i++)
					if ((UserEventList[i]->run) && (UserEventList[i]->key == SDLEvent.type))
						UserEventList[i]->function->operator()(_data, _user_data);
			}

		}

		n = EventList.size();
		for (size_t i = 0; i < n; i++)
			if ((EventList[i]->timer) && (EventList[i]->run) && (_data._tick % EventList[i]->timer == 0))
				EventList[i]->function->operator()(_data, _user_data);

	}

	SDL_Event SDLEvent;
	std::vector<std::shared_ptr<NR_event<User_Data_T>>> EventList, UserEventList;
};

#endif
