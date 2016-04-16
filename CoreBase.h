#ifndef _CORE_BASE_H
#define _CORE_BASE_H

#include <vector>

#include "Window.h"

#include "Data.h"

class CoreBase
{
public:
	CoreBase();
	explicit CoreBase(std::fstream &in);

	CoreBase(CoreBase &) = delete; //nocopy

	virtual ~CoreBase();

	Window *Create_window();
	Window *Create_window(int x, int y);
	Window *Create_window(int x, int y, int wd, int hg);
	Data _data;

private:
	std::string core_info, path_proj, engine_mode;
	Window *win;
	void Close_All_Windows();

	void Search(const std::string &info, std::fstream &in);

	void *addNewSimpleWin();
};


#endif
