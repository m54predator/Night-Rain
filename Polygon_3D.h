#ifndef _POLYGON_3D_H
#define _POLYGON_3D_H

#include "Scene_Object.h"
#include <vector>
#include <string>

class Polygon_3D
	: public Scene_Object
{
public:
	Polygon_3D();
	~Polygon_3D();

	void Render() override;
	void Change_Color(const RGBA &_color) override;
	void Change_Coordinates(const Coordinates &_coord) override;

	bool Change_Texture(const std::string &filename);
	bool Change_Texture(void *data, size_t w, size_t h);
private:
	GLuint texture_id;
};

#endif
