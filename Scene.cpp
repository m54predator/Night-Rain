//#include "include\GL\glut.h"
#include "Scene.h"
//#include "Scene_Object.h"
//#include "Object_Static_2D.h"
//#include "Graphic_2D.h"
//#include "Point_2D.h"
//#include "Polygon_3D.h"

Scene::Scene()
{
	_color.Set_RGBA(0, 0, 0, 1);
}

Scene::~Scene()
{
}

void Scene::Render()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);

	glClearColor(_color.r, _color.g, _color.b, _color.a);
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