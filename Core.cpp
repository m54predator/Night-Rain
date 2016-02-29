#include "Core.h"


Core<class User_Data>::Core()
	: path_proj("Game"), engine_mode("Game")
{
	_event_manager = new Event_Manager<User_Data>();
	_data = new Data();
	//close_windows_call->operator=([](int _tick){
	//	Close_All_Windows();
	//});
}
template<class User_Data>
Core<User_Data>::Core(std::fstream &in)
	: Core<User_Data>()
{
	//in.open("Core.config");

	while (!in.eof()) {
		in >> core_info;
		Search(core_info, in);
	}
	//in.close();
	std::fstream inp;
	inp.open("Win_err.config", std::ios::in);
	win = new Win_err(inp, "Exception opening/reading/closing file\n");
	inp.close();

	std::string win_path = std::string(path_proj) + "/Wind.config";
	inp >> win_path;

	/*
	inp.exceptions(std::fstream::failbit | std::fstream::badbit);
	try {
		inp.open(win_path, std::ios::in);
		inp.close();
	}
	catch (std::fstream::failure e) {
		win->Create();
	}
	*/
	//win->Create("Error text");
	//win->Close();
}

Core<class User_Data>::~Core()
{
	size_t windowSize = _data->windows.size();
	for (size_t i = 0; i < windowSize; i++)
		delete _data->windows[i];
}

void Core<class User_Data>::Search(const std::string &info, std::fstream &in)
{
	if (!info.compare("Path")) in >> path_proj;
	if (!info.compare("Mode")) in >> engine_mode;
}

Window *Core<class User_Data>::Create_window()
{
	Simple_win *win;
	win = new Simple_win();
	_data->windows.push_back(win);
	win->Create();

	return win;
}

Window* Core<class User_Data>::Create_window(int x, int y)
{
	Simple_win* win;
	win = new Simple_win();
	_data->windows.push_back(win);
	win->Create(x, y);

	return win;
}

Window* Core<class User_Data>::Create_window(int x, int y, int wd, int hg)
{
	Simple_win* win;
	win = new Simple_win();
	_data->windows.push_back(win);
	win->Create(x, y, wd, hg);

	return win;
}

bool Core<class User_Data>::Run(User_Data *_user_data)
{
	
	uint32_t frames = 0;

	uint32_t lastTick = SDL_GetTicks();
	float unprocesed = 0.f;

	const float tickPerSecond = 60;
	const float msPerTick = 1000 / tickPerSecond;

	_data->run = true;
	while (_data->run) {
		uint32_t now = SDL_GetTicks();
		unprocesed += (now - lastTick) / msPerTick;

		if (unprocesed >= 1) {
			_event_manager->Cheack(_data, _user_data);
			unprocesed -= 1;
			for (size_t i = 0; i < _data->windows.size(); i++)
				_data->windows[i]->Display();

			frames++;
			if (!(frames % 60)){
				std::cout << "frame " << frames << std::endl;
				_data->_tick++;
			}

		}

		uint32_t now2 = SDL_GetTicks();
		if (now2 - lastTick < msPerTick){
			long a = msPerTick - (now2 - lastTick);
			SDL_WaitEventTimeout(NULL, a);
		}
		lastTick = now;
		
	}
	return 0;
}

void Core<class User_Data>::Close_All_Windows()
{
	size_t i;
	_data->run = false;
	for (i = 0; i < _data->windows.size(); i++)
		_data->windows[i]->Close();
}