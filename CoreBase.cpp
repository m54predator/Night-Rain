#include "CoreBase.h"

// Class, engine core

#include "Win_err.h"
#include "Simple_win.h"

CoreBase::CoreBase()
	: path_proj("Game"), engine_mode("Game"), win(nullptr)
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
	win = std::make_shared<Win_err>(inp, "Exception opening/reading/closing file\n");
	inp.close();

	std::string win_path = std::string(path_proj) + "/Wind.config";
	inp >> win_path;
}


void CoreBase::Search(const std::string &info, std::fstream &in)
{
	if (!info.compare("Path")) {
		in >> path_proj;
	}
	if (!info.compare("Mode")) {
		in >> engine_mode;
	}
}

std::shared_ptr<Simple_win> CoreBase::addNewSimpleWin()
{
	auto win = std::make_shared<Simple_win>();
	_data.windows.push_back(win);
	return win;
}

std::shared_ptr<Window> CoreBase::Create_window()
{
	std::shared_ptr<Simple_win> win = addNewSimpleWin();
	win->Create();
	return win;
}

std::shared_ptr<Window> CoreBase::Create_window(int x, int y)
{
	std::shared_ptr<Simple_win> win = addNewSimpleWin();
	win->Create(x, y);

	return win;
}

std::shared_ptr<Window> CoreBase::Create_window(int x, int y, int wd, int hg)
{
	std::shared_ptr<Simple_win> win = addNewSimpleWin();
	win->Create(x, y, wd, hg);

	return win;
}

std::shared_ptr<Window> CoreBase::Create_window(int x, int y, int wd, int hg, Uint32 flags)
{
	std::shared_ptr<Simple_win> win = addNewSimpleWin();
	win->Create(x, y, wd, hg, flags);

	return win;
}

void CoreBase::Close_All_Windows()
{
	size_t i;
	_data.run = false;
	for (i = 0; i < _data.windows.size(); i++) {
		_data.windows[i]->Close();
	}
}
