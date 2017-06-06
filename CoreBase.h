#ifndef _CORE_BASE_H
#define _CORE_BASE_H

#include <vector>

#include "Window.h"
#include "Simple_win.h"

#include "Data.h"

class CoreBase
{
public:
	CoreBase();
	explicit CoreBase(std::fstream &in);

	CoreBase(CoreBase &) = delete; //nocopy

	virtual ~CoreBase() = default;

	std::shared_ptr<Window> Create_window();
	std::shared_ptr<Window> Create_window(int x, int y);
	std::shared_ptr<Window> Create_window(int x, int y, int wd, int hg);
	std::shared_ptr<Window> Create_window(int x, int y, int wd, int hg, Uint32 flags);
	Data _data;

private:
	std::string core_info, path_proj, engine_mode;
	std::shared_ptr<Window> win;
	void Close_All_Windows();

	void Search(const std::string &info, std::fstream &in);

	std::shared_ptr<Simple_win> addNewSimpleWin();
};


#endif
