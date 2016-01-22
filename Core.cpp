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

void Core::Search(std::string info, std::fstream &in)
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

void Core::Run()
{
	for (size_t i = 0; i < windows.size(); i++)
		windows[i]->Run();
}