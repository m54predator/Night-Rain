#ifndef _WINDOW_H
#define _WINDOW_H

#include <fstream>
#include <iostream> 
#include <string>

#include <SDL.h>
#include <memory>

#include "Scene.h"

class Window
{
public:
	std::shared_ptr<Scene> main_scene;

	Window();
	explicit Window(std::iostream &in);
	virtual ~Window() = default;

	virtual void Create() = 0;
	void Reshape(int width, int height);
	virtual void Display() = 0;
	//virtual void Mouse(int button, int state, int x, int y) abstract;
	virtual void init() = 0;
	void Close();
	void Run();
	void SetRelativeMouseMode(bool mode);

protected:
	int Wind_x, Wind_y, Wind_Wd, Wind_Hg;
	SDL_Window *Wind_reference;
	SDL_GLContext glcontext;
	std::string window_name;

	void PrintString(void *font, std::string str);
private:

	std::string window_info, window_value;

	void Search(const std::string &info, std::iostream &in);
};

#endif
