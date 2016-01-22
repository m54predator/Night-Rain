#include "Window.h"

Window::Window()
{
	Wind_Wd = Wind_Hg = 0;
	Default();
}

Window::Window(std::iostream &in)
{
	Default();

	while (!in.eof()) {
		in >> window_info;
		Search(window_info, in);
	}
}

Window::~Window()
{ }

void Window::Close()
{
	SDL_DestroyWindow(Wind_reference);
}

void Window::Search(const std::string &info, std::iostream &in)
{
	if (!info.compare("Width")) in >> Wind_Wd;
	if (!info.compare("Height")) in >> Wind_Hg;
	if (!info.compare("Window_X")) in >> Wind_x;
	if (!info.compare("Window_Y")) in >> Wind_y;
	if (!info.compare("Window_Name")) std::getline(in, window_name);
}

void Window::Default()
{
	Wind_Hg = 600;
	Wind_Wd = 1280;
	Wind_x = Wind_y = 0;
	window_name = "Window";
}

void Window::Reshape(int Wid, int Heig)
{
	Wind_Wd = Wid;
	Wind_Hg = Heig;
	/*
	glViewport(0, 0, Wind_Wd, Wind_Hg);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(90, GLdouble(Wind_Wd) / Wind_Hg, 1, 200);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 1);
	glutPostRedisplay();
	*/
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
				if (event.type == SDL_QUIT) run = false;
			}
			unprocesed -= 1;
			Display();
			frames++;
			if (!(frames % 60)) std::cout << "frame " << frames << std::endl;
		}

		uint32_t now2 = SDL_GetTicks();
		if (now2 - lastTick < msPerTick) SDL_WaitEventTimeout(&event, msPerTick - (now2 - lastTick));
		lastTick = now;
	}
}