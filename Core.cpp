#include "Core.h"
#include "Win_err.h"
#include "Simple_win.h"

Core::Core()
	: path_proj("Game"), engine_mode("Game")
{
}

Core::Core(std::fstream &in)
	: Core()
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

Core::~Core()
{
	size_t windowSize = windows.size();
	for (size_t i = 0; i < windowSize; i++)
		delete windows[i];
}

void Core::Search(const std::string &info, std::fstream &in)
{
	if (!info.compare("Path")) in >> path_proj;
	if (!info.compare("Mode")) in >> engine_mode;
}

Window *Core::Create_window()
{
	Simple_win *win;
	win = new Simple_win();
	windows.push_back(win);
	win->Create();

	return win;
}

Window* Core::Create_window(int x, int y)
{
	Simple_win* win;
	win = new Simple_win();
	windows.push_back(win);
	win->Create(x, y);

	return win;
}

void Core::Run()
{
	bool run = true;

	uint32_t frames = 0;

	uint32_t lastTick = SDL_GetTicks();
	float unprocesed = 0.f;

	const float tickPerSecond = 60;
	const float msPerTick = 1000 / tickPerSecond;

	SDL_Event event;
	while (run) {
		uint32_t now = SDL_GetTicks();
		unprocesed += (now - lastTick) / msPerTick;

		if (unprocesed >= 1) {
			while (SDL_PollEvent(&event)) {
				//std::cout << event.window.type << std::endl;
				//if (event.type == SDL_WINDOWEVENT)
				//if (event.window.type == SDL_WINDOWEVENT_RESIZED) 
				//if (event.window.type == SDL_USEREVENT)
				//std::cout << "resize" << std::endl;

				switch (event.type){
				case SDL_KEYDOWN:
					std::cout << "Key press detected\n";
					std::cout << SDL_GetKeyName(event.key.keysym.sym) << std::endl;
					break;

				case SDL_KEYUP:
					//		printf("Key release detected\n");

					break;

				case SDL_SYSWMEVENT:
					printf("windows event\n");
					break;
				case SDL_QUIT:
					run = 0;
					break;

				default:
					//printf("Event is run\n");
					break;
				}
			}
			unprocesed -= 1;
			for (size_t i = 0; i < windows.size(); i++)
				windows[i]->Display();

			frames++;
			if (!(frames % 60)){
				std::cout << "frame " << frames << std::endl;
			}

		}

		uint32_t now2 = SDL_GetTicks();
		if (now2 - lastTick < msPerTick){
			long a = msPerTick - (now2 - lastTick);
			SDL_WaitEventTimeout(NULL, a);
		}
		lastTick = now;

	}

}