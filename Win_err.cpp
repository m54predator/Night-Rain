#include "Win_err.h"

Win_err::Win_err()
	: Window()
{
	main_scene = new Scene();
}

Win_err::Win_err(std::iostream &in, const char *text)
	: Window(in), err_txt("text")
{ }

Win_err::~Win_err()
{
}

void Win_err::Mouse(int button, int state, int x, int y)
{
	/*if (button == GLUT_LEFT_BUTTON)
		switch (state){
		case GLUT_DOWN: ld = 1; mx = x; my = y; break;
		case GLUT_UP: ld = 0; break;
	}
	if (button == GLUT_RIGHT_BUTTON)
		switch (state){
		case GLUT_DOWN: rd = 1; mx = x; my = y; break;
		case GLUT_UP: rd = 0; break;
	}*/
}

void Win_err::Display()
{
	SDL_GL_MakeCurrent(Wind_reference, glcontext);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	glDisable(GL_LIGHTING);

	/* Object */
	//PrintString(GLUT_STROKE_ROMAN, "Rectangle");
//	PrintString(GLUT_BITMAP_HELVETICA_12, err_txt);
	/* Object */
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
//	gluOrtho2D(0, Wind_Wd, 0, Wind_Hg);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	SDL_GL_SwapWindow(Wind_reference);
}

void Win_err::init()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.27, 0.06, 0.53, 1);

}

void Win_err::Create()
{
	SDL_DisplayMode displayMode;
	SDL_GetDesktopDisplayMode(0, &displayMode);

	Wind_x = displayMode.w / 4;
	Wind_y = displayMode.h / 4;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}

	Wind_reference =
		SDL_CreateWindow(window_name.c_str(), 0, 0, Wind_Wd, Wind_Hg, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	glcontext = SDL_GL_CreateContext(Wind_reference);
	init();

}

void Win_err::Create(const std::string &str)
{
	err_txt = str;
	Create();
}
