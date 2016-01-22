#include "Simple_win.h"
#include "Scene.h"


Simple_win::Simple_win()
	: Window()
{
	main_scene = new Scene();
}

Simple_win::~Simple_win()
{
	delete main_scene;
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
	SDL_GL_MakeCurrent(Wind_reference, glcontext);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	//glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	/* Object */
	main_scene->Render();
	/* Object */

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);


	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	//gluOrtho2D(0, Wind_Wd, 0, Wind_Hg);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	SDL_GL_SwapWindow(Wind_reference);
}
void Simple_win::init()
{

}

void Simple_win::KeyBoard(unsigned char key, int x, int y)
{
	/*
	switch (key)
	{
	case VK_ESCAPE: { glutDestroyWindow(Wind_reference); break; }
	}
	glutPostRedisplay();
	*/
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

void Simple_win::Create(int x, int y)
{

	Wind_x = x; Wind_y = y;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
	}

	Wind_reference = SDL_CreateWindow(window_name.c_str(), Wind_x, Wind_y, Wind_Wd, Wind_Hg, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	glcontext = SDL_GL_CreateContext(Wind_reference);
	init();
}


