#include "Polygon_3D.h"
#include "lodepng/lodepng.h"

Polygon_3D::Polygon_3D()
{
	coord.x.resize(4, 0);
	coord.y.resize(4, 0);
	coord.z.resize(4, 0);
}

Polygon_3D::~Polygon_3D()
{
	_texture_id.reset();
}


bool Polygon_3D::Change_Texture(const std::string &filename)
{
	std::vector<unsigned char> image, buffer;
	unsigned width, height;

	lodepng::load_file(buffer, filename);
	unsigned error = lodepng::decode(image, width, height, buffer);
	bool fl = _texture_id.operator bool();
	if (_texture_id.operator bool()) {
		_texture_id.reset();
	}
	_texture_id = std::make_shared<Texture>();
	return _texture_id->Set_Texture(&*image.begin(), height, width);
}

bool Polygon_3D::Change_Texture(const std::vector<unsigned char> &data, size_t _w, size_t _h)
{
	if (_texture_id.operator bool()) {
		_texture_id.reset();
	}
	_texture_id = std::make_shared<Texture>();
	return _texture_id->Set_Texture(data.data(), _w, _h);
}

bool Polygon_3D::Change_Texture(void *data, size_t _w, size_t _h)
{
	if (_texture_id.operator bool()) {
		_texture_id.reset();
	}
	_texture_id = std::make_shared<Texture>();
	return _texture_id->Set_Texture(reinterpret_cast<unsigned char *>( data), _w, _h);
}

bool Polygon_3D::Change_Texture(const Polygon_3D &_polygon)
{
	_texture_id = _polygon._texture_id;
	return false;
}

void Polygon_3D::Change_Color(const RGBA &_color)
{
	color = _color;
}

void Polygon_3D::Change_Coordinates(const Coordinates &_coord)
{
	coord = _coord;
}

void Polygon_3D::Render()
{
	glColor3f(color.r, color.g, color.b);
	if (_texture_id.operator bool())
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _texture_id->texture_id);
	}
	glBegin(GL_POLYGON);
	{
		if (coord.x.size() < 5){
			glTexCoord3f(0.0, 0.0, 0.0);
			glVertex3f(coord.x[0], coord.y[0], coord.z[0]);

			glTexCoord3f(1.0, 0.0, 1.0);
			glVertex3f(coord.x[1], coord.y[1], coord.z[1]);

			glTexCoord3f(1.0, 1.0, 1.0);
			glVertex3f(coord.x[2], coord.y[2], coord.z[2]);

			glTexCoord3f(0.0, 1.0, 0.0);
			glVertex3f(coord.x[3], coord.y[3], coord.z[3]);
		} else
			for (size_t i = 0; i < coord.x.size(); i++){
			glTexCoord3f(0.0, 1.0, 0.0);
			glVertex3f(coord.x[i], coord.y[i], coord.z[i]);
		}
	}
	glEnd();
	//glDisable(GL_TEXTURE_2D);
}
