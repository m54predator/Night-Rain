#ifndef _SCENE_H
#define _SCENE_H

#include <vector>
#include "Scene_Object.h"
#include "LookAt.h"
#include "Camera.h"

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
	Camera _camera;
private:
	LookAt _lookat;
};

#endif
