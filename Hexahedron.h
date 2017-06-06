#ifndef _HEXAHEDRON_H
#define _HEXAHEDRON_H

#include <vector>
#include <string>
#include <memory>
#include "Scene_Object.h"
#include "Polygon_3D.h"


class Hexahedron :
	public Scene_Object
{
public:
	Hexahedron();
	Hexahedron(GLfloat _x, GLfloat _y, GLfloat _hight, GLfloat _width);
	Hexahedron(GLfloat _x, GLfloat _y, GLfloat _z, GLfloat _hight, GLfloat _width);
	~Hexahedron() override;

	void Render() override;
	void Change_Color(const RGBA &_color) override;
	void Change_Coordinates(const Coordinates &_coord) override;
	void Swap_Coordinates(std::vector<GLfloat> &x, std::vector<GLfloat> &y, std::vector<GLfloat> &z);
	bool Change_Texture(const std::vector<unsigned char> &data, size_t _w, size_t _h);
	bool Change_Texture(void *data, size_t _w, size_t _h);
	bool Change_Texture(const Polygon_3D &_polygon);
	bool Change_Texture(const std::string &filename);

private:
	std::shared_ptr<Texture> _texture_id;
	std::vector<std::shared_ptr<Polygon_3D>> polygons;
	GLfloat x, y, z, hight, width;
};

#endif
