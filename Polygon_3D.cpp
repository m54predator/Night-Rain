#include "Polygon_3D.h"


Polygon_3D::Polygon_3D()
{
	color.Set_RGBA(1, 1, 1, 1);
	for (int i = 0; i < 4; i++) {
		coord.x.push_back(0);
		coord.y.push_back(0);
		coord.z.push_back(0);
	}
}

Polygon_3D::~Polygon_3D()
{
}

bool Polygon_3D::Change_Texture(void *data, size_t w, size_t h)
{
	std::vector<unsigned char> image;
	unsigned width, height;
	image.resize(w * h * 4);

	std::copy((unsigned char *) data, ((unsigned char *) data) + w * h * 4, image.begin());
	width = w;
	height = h;


	// Texture size must be power of two for the primitive OpenGL version this is written for. Find next power of two.
	size_t u2 = 1;
	while (u2 < width) u2 *= 2;
	size_t v2 = 1;
	while (v2 < height) v2 *= 2;
	// Ratio for power of two version compared to actual version, to render the non power of two image with proper size.
	double u3 = (double) width / u2;
	double v3 = (double) height / v2;

	// Make power of two version of the image.
	std::vector<unsigned char> image2(u2 * v2 * 4);
	for (size_t y = 0; y < height; y++)
		for (size_t x = 0; x < width; x++)
			for (size_t c = 0; c < 4; c++) {
				image2[4 * u2 * y + 4 * x + c] = image[4 * width * y + 4 * x + c];
			}
	if (texture_referens) glDeleteTextures(1, &texture_referens);
	glGenTextures(1, &texture_referens);
	glBindTexture(GL_TEXTURE_2D, texture_referens);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, height, width, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);

	return 0;
}

bool Polygon_3D::Change_Texture(const std::string &fname)
{

	texture_path = fname;

	std::vector<unsigned char> image, buffer;
	unsigned width, height;
	unsigned error;

	lodepng::load_file(buffer, texture_path);
	error = lodepng::decode(image, width, height, buffer);

	return Change_Texture(&*image.begin(), width, height);
}

void Polygon_3D::Change_Color(const RGBA &_color)
{
	color = _color;
}

void Polygon_3D::Change_Coordinats(const Coordinates &_coord)
{
	coord = _coord;
}

void Polygon_3D::Render()
{
	size_t i, size;

	glColor3f(color.r, color.g, color.b);
	glBindTexture(GL_TEXTURE_2D, texture_referens);
	glBegin(GL_QUADS);
	glTexCoord3f(0.0, 0.0, 0.0);
	glVertex3f(coord.x[0], coord.y[0], coord.z[0]);
	glTexCoord3f(1.0, 0.0, 1.0);
	glVertex3f(coord.x[1], coord.y[1], coord.z[1]);
	glTexCoord3f(1.0, 1.0, 1.0);
	glVertex3f(coord.x[2], coord.y[2], coord.z[2]);
	glTexCoord3f(0.0, 1.0, 0.0);
	glVertex3f(coord.x[3], coord.y[3], coord.z[3]);
	glEnd();
}