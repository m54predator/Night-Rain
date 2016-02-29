#include "Scene.h"

Scene::Scene()
{
	_color.Set_RGBA(0, 0, 0, 1);
	camera.SetCoordinates(0, 0, 0);
}

Scene::~Scene()
{
}

void Scene::Render()
{
	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	

	glClearColor(_color.r, _color.g, _color.b, _color.a);
	glTranslatef(camera.x[0], camera.y[0], camera.z[0]);
	//glRotatef(camera.z[0], 1, 0, 0);
	//glRotatef(ry, 0, 1, 0);

	size_t SizeObject = Objects.size();
	for (size_t i = 0; i < SizeObject; i++)
		Objects[i]->Render();
}

void Scene::SetObject(Scene_Object *new_object)
{
	Objects.push_back(new_object);
}

void Scene::Change_Color(const RGBA &color)
{
	_color = color;
}