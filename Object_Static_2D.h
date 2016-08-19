#ifndef _OBJECT_STATIC_2D_H
#define _OBJECT_STATIC_2D_H

#include <vector>
#include <string>
#include <memory>
#include "Scene_Object.h"


class Object_Static_2D
	: public Scene_Object
{
public:
	Object_Static_2D();

	void Render() override;
	void Change_Color(const RGBA &_color) override;
	void Change_Coordinates(const Coordinates &_coord) override;

	void Change_Texture(const std::string &filename);
	void Set_Object(const std::shared_ptr<Scene_Object> &_scene_object);

private:
	GLuint texture_id;
	std::string texture_path;
	std::vector<std::shared_ptr<Scene_Object>> scene_objects;
};

#endif
