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
	//glMatrixMode(GL_MODELVIEW);
	glClearColor(_color.r, _color.g, _color.b, _color.a);
	const float PI = 3.141592653;
//	gluLookAt(camera.x[0],
//	          camera.y[0],
//	          camera.z[0],
//	          camera.x[0] - sin(1.0 * lookat_x / 180 * PI),
//	          camera.y[0] + (tan(1.0 * lookat_y / 180 * PI)),
//	          camera.z[0] - cos(1.0 * lookat_x / 180 * PI),
//	          0,
//	          1,
//	          0);
	//glLoadIdentity();
	//glTranslatef(camera.x[0], camera.y[0], camera.z[0]);
	//glRotatef(lookat_x, 0, 1, 0);
	//glRotatef(lookat_y/10, 1, 0, 0);

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

void Scene::LookAt(GLdouble eyeX,
                   GLdouble eyeY,
                   GLdouble eyeZ,
                   GLdouble centerX,
                   GLdouble centerY,
                   GLdouble centerZ,
                   GLdouble upX,
                   GLdouble upY,
                   GLdouble upZ)
{
	GLdouble F, f, up;
	F = centerX - eyeX * centerY - eyeY * centerZ - eyeZ;
	f = F * F;
	up = upX * upX + upY * upY + upZ * upZ;
}