#include "Texture.h"

Texture::Texture()
{
}

Texture::~Texture()
{
	glDeleteTextures(1, &texture_id);
}

bool Texture::Set_Texture(const unsigned char *data, size_t w, size_t h)
{
	std::vector<unsigned char> image;
	size_t width, height;
	image.resize(w * h * 4);

	std::copy(data, data + w * h * 4, image.begin());
	width = w;
	height = h;


	// Texture size must be power of two for the primitive OpenGL version this is written for. Find next power of two.
	size_t u2 = 1;
	while (u2 < width) {
		u2 *= 2;
	}
	size_t v2 = 1;
	while (v2 < height) {
		v2 *= 2;
	}
	// Ratio for power of two version compared to actual version, to render the non power of two image with proper size.
	double u3 = static_cast<double>(width) / u2;
	double v3 = static_cast<double>(height) / v2;

	// Make power of two version of the image.
	std::vector<unsigned char> image2(u2 * v2 * 4);
	for (size_t y = 0; y < height; y++) {
		for (size_t x = 0; x < width; x++) {
			for (size_t c = 0; c < 4; c++) {
				image2[4 * u2 * y + 4 * x + c] = image[4 * width * y + 4 * x + c];
			}
		}
	}

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D,
	             0,
	             4,
	             static_cast<GLsizei>(height),
	             static_cast<GLsizei>(width),
	             0,
	             GL_RGBA,
	             GL_UNSIGNED_BYTE,
	             &image[0]);

	return 0;
}