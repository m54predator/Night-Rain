#pragma once
#include <vector>
#include "Scene_Object.h"
#include "Graphic_2D.h"
#include "Point_2D.h"


class Scene
{
public:
	std::vector<Scene_Object *> Objects;
	RGBA _color;

	Scene();
	~Scene();
	void Render();
	void SetObject(Scene_Object *new_object);
	void Change_Color(RGBA color);
};
