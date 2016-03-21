#ifndef _OBJECT_STATIC_2D_H
#define _OBJECT_STATIC_2D_H
#include "Scene_Object.h"
#include <vector>
class Object_Static_2D
	: public Scene_Object
{
public:
	Object_Static_2D();
	~Object_Static_2D();
	void Render();
	void Change_Texture(const std::string &fname);
	void Change_Color(const RGBA &_color);
	void Change_Coordinats(const Coordinates &_coord);
	void Set_Object(Scene_Object *_scene_object);
private:
	GLuint texture_referens;
	std::string texture_path;
	std::vector<Scene_Object *> scene_objects;
	//AUX_RGBImageRec *texture;
};
#endif