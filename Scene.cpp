#include "Scene.h"

#include "Object_Static_2D.h"
#include "Graphic_2D.h"
#include "Point_2D.h"
#include "Polygon_3D.h"

//#include "glaux.h"

Scene::Scene()
{
	_color.Set_RGBA(0, 0, 0, 1);
	camera.SetCoordinates(0, 0, 0);
	lookat_x = lookat_y = 0;
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
	std::vector<GLfloat> look_matrix, eye, center, up;
	GLfloat *set_matrix = new GLfloat[16];

	eye.resize(3);
	center.resize(3);
	up.resize(3);
	look_matrix.resize(16);
	eye[0] = camera.x[0];
	eye[1] = camera.y[0];
	eye[2] = camera.z[0];
	center[0] = camera.x[0] - sin(1.0 * lookat_x / 180 * M_PI);
	center[1] = camera.y[0] + (tan(1.0 * lookat_y / 180 * M_PI));
	center[2] = camera.z[0] - cos(1.0 * lookat_x / 180 * M_PI);
	up[0] = 0;
	up[1] = 1;
	up[2] = 0;
	glGetFloatv(GL_PROJECTION_MATRIX, set_matrix);
	look_matrix.assign(set_matrix, set_matrix + 16);
	_lookat.LookAt_Set(&look_matrix, eye, center, up);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMultMatrixf(look_matrix.data());

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
