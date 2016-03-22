#ifndef _CORE_H
#define _CORE_H

#include "Event_Manager.h"
#include "CoreBase.h"

template<class User_Data>
class Core : public CoreBase
{
public:
	Core() : CoreBase()
	{
		_event_manager = new Event_Manager<User_Data>();
	}

	Core(std::fstream &in) : CoreBase(in) {}

	~Core()
	{
		delete _event_manager;
	}

	bool Run(User_Data *_user_data)
	{

		uint32_t frames = 0;

		uint32_t lastTick = SDL_GetTicks();
		float unprocesed = 0.f;

		const float tickPerSecond = 60;
		const float msPerTick = 1000 / tickPerSecond;

		_data.run = true;
		while (_data.run) {
			uint32_t now = SDL_GetTicks();
			unprocesed += (now - lastTick) / msPerTick;

			if (unprocesed >= 1) {
				_event_manager->Cheack(&_data, _user_data);
				unprocesed -= 1;
				for (size_t i = 0; i < _data.windows.size(); i++)
					_data.windows[i]->Display();

				frames++;
				if (!(frames % 60)) {
					std::cout << "frame " << frames << std::endl;
					_data._tick++;
				}

			}

			uint32_t now2 = SDL_GetTicks();
			if (now2 - lastTick < msPerTick) {
				int maxWaitInMs = (int)(msPerTick - (now2 - lastTick));
				SDL_WaitEventTimeout(NULL, maxWaitInMs);
			}
			lastTick = now;

		}
		return 0;
	}

	Event_Manager<User_Data> * getEventManager() const { return _event_manager; }

private:
	Event_Manager<User_Data> *_event_manager;
};

#endif
