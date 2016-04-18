#include "Scene.h"

#include "LookAt.h"

Scene::Scene()
{
	_color.Set_RGBA(0, 0, 0, 1);
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
	std::vector<GLfloat> look_matrix(16), eye(3), center(3), up(3);

	eye[0] = _camera.camX;
	eye[1] = _camera.camY;
	eye[2] = _camera.camZ;
	center[0] = _camera.lookAtX();
	center[1] = _camera.lookAtY();
	center[2] = _camera.lookAtZ();
	up[0] = _camera.upDirectX;
	up[1] = _camera.upDirectY;
	up[2] = _camera.upDirectZ;

	glGetFloatv(GL_PROJECTION_MATRIX, look_matrix.data());
	LookAt::LookAt_Set(look_matrix, eye, center, up);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMultMatrixf(look_matrix.data());

	for (auto & elem : Objects)
		elem->Render();
}

void Scene::SetObject(Scene_Object *new_object)
{
	Objects.push_back(new_object);
}

void Scene::Change_Color(const RGBA &color)
{
	_color = color;
}
