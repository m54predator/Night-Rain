#pragma once
#include <string>
#include "RGBA.h"
#include "Coordinates.h"
class Scene_Object
{
public:
	Scene_Object();
	virtual ~Scene_Object();
	virtual void Render() = 0;
	virtual void Change_Color(const RGBA &_color) = 0;
	virtual void Change_Coordinats(const Coordinates &_coord) = 0;
protected:
	RGBA color;
	Coordinates coord;
};
