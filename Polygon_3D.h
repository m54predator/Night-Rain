#ifndef _POLYGON_3D_H
#define _POLYGON_3D_H

#include <vector>
#include <string>
#include <memory>
#include "Scene_Object.h"
#include "Texture.h"


class Polygon_3D
	: public Scene_Object
{
public:
	Polygon_3D();
	~Polygon_3D();

	void Render() override;
	void Change_Color(const RGBA &_color) override;
	void Change_Coordinates(const Coordinates &_coord) override;
	bool Change_Texture(const std::vector<unsigned char> &data, size_t _w, size_t _h);
	bool Change_Texture(void *data, size_t _w, size_t _h);
	bool Change_Texture(const Polygon_3D &_polygon);
	bool Change_Texture(const std::string &filename);
	
private:
	std::shared_ptr<Texture> _texture_id;
	
};

#endif
