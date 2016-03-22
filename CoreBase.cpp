#include "CoreBase.h"

// Class, engine core

#include "Win_err.h"
#include "Simple_win.h"

CoreBase::CoreBase()
	: path_proj("Game"), engine_mode("Game")
{ }

CoreBase::CoreBase(std::fstream &in)
	: CoreBase()
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
}

CoreBase::~CoreBase()
{
	size_t windowSize = _data.windows.size();
	for (size_t i = 0; i < windowSize; i++)
		delete _data.windows[i];
}

void CoreBase::Search(const std::string &info, std::fstream &in)
{
	if (!info.compare("Path")) in >> path_proj;
	if (!info.compare("Mode")) in >> engine_mode;
}

void *CoreBase::addNewSimpleWin()
{
	Simple_win *win = new Simple_win();
	_data.windows.push_back(win);
	return win;
}

Window *CoreBase::Create_window()
{
	addNewSimpleWin();
	Simple_win *win = static_cast<Simple_win *>(_data.windows.back());
	win->Create();

	return win;
}

Window *CoreBase::Create_window(int x, int y)
{
	addNewSimpleWin();
	Simple_win *win = static_cast<Simple_win *>(_data.windows.back());
	win->Create(x, y);

	return win;
}

Window *CoreBase::Create_window(int x, int y, int wd, int hg)
{
	addNewSimpleWin();
	Simple_win *win = static_cast<Simple_win *>(_data.windows.back());
	win->Create(x, y, wd, hg);

	return win;
}

void CoreBase::Close_All_Windows()
{
	size_t i;
	_data.run = false;
	for (i = 0; i < _data.windows.size(); i++)
		_data.windows[i]->Close();
}
