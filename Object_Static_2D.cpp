#include "Object_Static_2D.h"

Object_Static_2D::Object_Static_2D()
{
	color.Set_RGBA(1, 1, 1, 1);
	for (int i = 0; i < 4; i++) {
		coord.x.push_back(0);
		coord.y.push_back(0);
	}
}

Object_Static_2D::~Object_Static_2D()
{
	size_t i, size = scene_objects.size();
	for (i = 0; i < size; i++)
		delete scene_objects[i];
}

void Object_Static_2D::Change_Texture(const std::string &fname)
{
	texture_path = fname;

	//texture = auxDIBImageLoad(texture_path.c_str());
	glGenTextures(1, &texture_referens);
	glBindTexture(GL_TEXTURE_2D, texture_referens);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexImage2D(GL_TEXTURE_2D, 0, 3, texture->sizeX, texture->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture->data);
}

void Object_Static_2D::Change_Color(const RGBA &_color)
{
	color = _color;
}

void Object_Static_2D::Change_Coordinats(const Coordinates &_coord)
{
	coord = _coord;
}

void Object_Static_2D::Render()
{
	size_t i, size;

	glColor3f(color.r, color.g, color.b);
	glBindTexture(GL_TEXTURE_2D, texture_referens);
	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 0.0, 0.0);
	glVertex2f(coord.x[0], coord.y[0]);
	glTexCoord3f(1.0, 0.0, 4.0);
	glVertex2f(coord.x[1], coord.y[1]);
	glTexCoord3f(1.0, 1.0, 1.0);
	glVertex2f(coord.x[2], coord.y[2]);
	glTexCoord3f(0.0, 1.0, 0.0);
	glVertex2f(coord.x[3], coord.y[3]);
	glEnd();

	size = scene_objects.size();
	for (i = 0; i < size; i++)
		scene_objects[i]->Render();

}

void Object_Static_2D::Set_Object(Scene_Object *_scene_object)
{
	scene_objects.push_back(_scene_object);
}
