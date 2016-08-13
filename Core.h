#ifndef _CORE_H
#define _CORE_H

#include "EventManager.h"
#include "CoreBase.h"

template<class User_Data_T>
class Core: public CoreBase
{
public:
	Core()
		: CoreBase()
	{
		_event_manager = std::make_shared<EventManager<User_Data_T>>();
	}

	Core(std::fstream &in)
		: CoreBase(in)
	{ }

	~Core() = default;

	bool Run(std::shared_ptr<User_Data_T> _user_data)
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
				_event_manager->Check(_data, _user_data);
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
				int maxWaitInMs = (int) (msPerTick - (now2 - lastTick));
				SDL_WaitEventTimeout(NULL, maxWaitInMs);
			}
			lastTick = now;

		}
		return 0;
	}

	std::shared_ptr<EventManager<User_Data_T>> getEventManager() const
	{
		return _event_manager;
	}

private:
	std::shared_ptr<EventManager<User_Data_T>> _event_manager;
};

#endif
