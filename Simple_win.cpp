#include "Simple_win.h"

Simple_win::Simple_win()
{
	main_scene = std::make_unique<Scene>();
	std::fill(std::begin(persp), std::end(persp), 0);
	persp[14] = -1.0f;
}

void Simple_win::Mouse(int button, int state, int x, int y)
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

void Simple_win::Display()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMultMatrixf(persp.data());
	SDL_GL_MakeCurrent(Wind_reference, glcontext);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	glEnable(GL_TEXTURE_2D);
	/* Object */
	main_scene->Render();
	/* Object */

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glPopMatrix();
	SDL_GL_SwapWindow(Wind_reference);
}

void Simple_win::init()
{
	Perspective(-0.2F * (Wind_Wd / Wind_Hg), 0.2F * (Wind_Wd / Wind_Hg), 0.2F, -0.2F, 1, 100);
	glClearColor(0, 0, 0, 0);
	SDL_SetRelativeMouseMode(SDL_TRUE);

	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
}

void Simple_win::KeyBoard(unsigned char key, int x, int y)
{
}

void Simple_win::Create()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}

	Wind_reference =
			SDL_CreateWindow(window_name.c_str(), 0, 0, Wind_Wd, Wind_Hg, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	glcontext = SDL_GL_CreateContext(Wind_reference);
	init();

}

void Simple_win::Create(int _wind_x, int _wind_y)
{

	Wind_x = _wind_x;
	Wind_y = _wind_y;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}

	Wind_reference = SDL_CreateWindow(window_name.c_str(),
	                                  Wind_x,
	                                  Wind_y,
	                                  Wind_Wd,
	                                  Wind_Hg,
	                                  SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	glcontext = SDL_GL_CreateContext(Wind_reference);
	init();
}

void Simple_win::Create(int _wind_x, int _wind_y, int _wind_wd, int _wind_hd)
{
	Wind_x = _wind_x;
	Wind_y = _wind_y;
	Wind_Wd = _wind_wd;
	Wind_Hg = _wind_hd;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}

	Wind_reference = SDL_CreateWindow(window_name.c_str(),
	                                  Wind_x,
	                                  Wind_y,
	                                  Wind_Wd,
	                                  Wind_Hg,
	                                  SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	glcontext = SDL_GL_CreateContext(Wind_reference);
	init();
}

void Simple_win::Perspective(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat _near, GLfloat _far)
{
	persp[0] = (2.0f * _near) / (right - left);
	// persp[1] = 0;
	persp[2] = (right + left) / (right - left);
	// persp[3] = 0;
	// persp[4] = 0;
	persp[5] = (2.0f * _near) / (top - bottom);
	persp[6] = (top + bottom) / (top - bottom);
	// persp[7] = 0;
	// persp[8] = 0;
	// persp[9] = 0;
	persp[10] = -(_far + _near) / (_far - _near);
	persp[11] = -(2.0f * _far * _near) / (_far - _near);
	// persp[12] = 0;
	// persp[13] = 0;
	// persp[14] = -1.0F; // set in ctor
	// persp[15] = 0;
}
