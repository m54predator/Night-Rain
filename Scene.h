#pragma once
#include <vector>
#include "Scene_Object.h"
#include "LookAt.h"

class Scene
{
public:
	std::vector<Scene_Object *> Objects;
	RGBA _color;

	Scene();
	~Scene();
	void Render();
	void SetObject(Scene_Object *new_object);
	void Change_Color(const RGBA &color);
	Coordinates camera;
	Sint32 lookat_x, lookat_y;
private:
	LookAt _lookat;
};
