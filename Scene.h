#pragma once
#include <vector>
#include "Scene_Object.h"
#include "Object_Static_2D.h"
#include "Graphic_2D.h"
#include "Point_2D.h"
#include "Polygon_3D.h"


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
};
