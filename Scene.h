#ifndef _SCENE_H
#define _SCENE_H

#include <vector>
#include <memory>
#include "Scene_Object.h"

#include "Camera.h"

class Scene
{
public:
	Scene();

	void Render();
	void SetObject(Scene_Object *new_object);
	void SetObject(std::vector<Scene_Object> new_object);
	void Change_Color(const RGBA &_color);

	RGBA color;
	std::shared_ptr<Camera> camera;
	std::vector<Scene_Object *> objects;
};

#endif
