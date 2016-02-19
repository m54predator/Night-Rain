#pragma once
#include "Scene_Object.h"
#include <vector>
class Polygon_3D
	: public Scene_Object
{
public:
	Polygon_3D();
	~Polygon_3D();
	void Render();
	void Change_Texture(const std::string &fname);
	void Change_Color(const RGBA &_color);
	void Change_Coordinats(const Coordinates &_coord);
private:
	GLuint texture_referens;
	std::string texture_path;
};

