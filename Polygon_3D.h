#ifndef _POLYGON_3D_H
#define _POKYGON_3D_H

#include "Scene_Object.h"
#include <vector>

class Polygon_3D
	: public Scene_Object
{
public:
	Polygon_3D();
	~Polygon_3D();
	void Render();
	bool Change_Texture(const std::string &fname);
	bool Change_Texture(void *data, size_t w, size_t h);
	void Change_Color(const RGBA &_color);
	void Change_Coordinats(const Coordinates &_coord);
	std::string error_load_texture;
private:
	GLuint texture_referens;
	std::string texture_path;
};

#endif
