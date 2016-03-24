#ifndef _SCENE_OBJECT_H
#define _SCENE_OBJECT_H

#include "RGBA.h"
#include "Coordinates.h"

class Scene_Object
{
public:
	virtual ~Scene_Object() = default;

	virtual void Render() = 0;
	virtual void Change_Color(const RGBA &_color) = 0;
	virtual void Change_Coordinates(const Coordinates &_coord) = 0;

	Coordinates Get_Coordinates();
protected:
	RGBA color;
	Coordinates coord;
};

#endif
