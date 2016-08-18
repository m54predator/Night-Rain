#include "Scene.h"

#include "LookAt.h"

Scene::Scene()
	: color(0, 0, 0, 1)
{ 
	camera = std::make_shared<Camera>();
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
	glClearColor(color.r, color.g, color.b, color.a);
	std::vector<GLfloat> look_matrix(16), eye(3), center(3), up(3);

	eye[0] = camera->camX;
	eye[1] = camera->camY;
	eye[2] = camera->camZ;
	center[0] = camera->lookAtX();
	center[1] = camera->lookAtY();
	center[2] = camera->lookAtZ();
	up[0] = camera->upDirectX;
	up[1] = camera->upDirectY;
	up[2] = camera->upDirectZ;

	glGetFloatv(GL_PROJECTION_MATRIX, look_matrix.data());
	LookAt::LookAt_Set(look_matrix, eye, center, up);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMultMatrixf(look_matrix.data());

	for (auto &elem : objects) {
		elem->Render();
	}
}

void Scene::SetObject(Scene_Object &new_object)
{
	objects.push_back(&new_object);
}

void Scene::SetObject(std::vector<Scene_Object> &new_object)
{
	for (size_t i = 0; i < new_object.size(); ++i)
		objects.push_back(&new_object[i]);
}

void Scene::Change_Color(const RGBA &_color)
{
	color = _color;
}
