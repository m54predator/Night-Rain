#include "Window.h"

Window::Window() :
		Wind_x(0), Wind_y(0), Wind_Wd(1280), Wind_Hg(600),
		Wind_reference(nullptr),
		window_name("Window")
{
	main_scene = std::make_shared<Scene>();
}

Window::Window(std::iostream &in) :
		Window()
{
	while (!in.eof()) {
		in >> window_info;
		Search(window_info, in);
	}
}

void Window::Close()
{
	SDL_DestroyWindow(Wind_reference);
}

void Window::Search(const std::string &info, std::iostream &in)
{
	if (!info.compare("Width")) {
		in >> Wind_Wd;
	}
	if (!info.compare("Height")) {
		in >> Wind_Hg;
	}
	if (!info.compare("Window_X")) {
		in >> Wind_x;
	}
	if (!info.compare("Window_Y")) {
		in >> Wind_y;
	}
	if (!info.compare("Window_Name")) {
		std::getline(in, window_name);
	}
}

void Window::Reshape(int width, int height)
{
	Wind_Wd = width;
	Wind_Hg = height;
}

void Window::PrintString(void *font, std::string str)
{
	/*glutReshapeFunc(&Window::Reshape);
	char* c = str;
	while (*c)
	{
		glutBitmapCharacter(font, *c);
		//glutStrokeCharacter(font, *c);
		c++;
	}*/
}

void Window::Run()
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
				std::cout << (event.type == SDL_WINDOWEVENT) << std::endl;
				if (event.type == SDL_QUIT) {
					run = false;
				}
			}
			unprocesed -= 1;
			Display();
			frames++;
			if (!(frames % 60)) {
				std::cout << "frame " << frames << std::endl;
			}
		}

		uint32_t now2 = SDL_GetTicks();
		if (now2 - lastTick < msPerTick) {
			SDL_WaitEventTimeout(&event, msPerTick - (now2 - lastTick));
		}
		lastTick = now;
	}
}

void Window::SetRelativeMouseMode(bool mode)
{
	SDL_SetRelativeMouseMode(mode ? SDL_TRUE : SDL_FALSE);
}
