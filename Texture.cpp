#include "Texture.h"

Texture::~Texture()
{
	glDeleteTextures(1, &texture_id);
}

bool Texture::Set_Texture(const unsigned char *data, size_t w, size_t h)
{
	// Texture size must be power of two for the primitive OpenGL version this is written for. Find next power of two.
	//size_t u2 = 1;
	//while (u2 < w) {
	//	u2 *= 2;
	//}
	//size_t v2 = 1;
	//while (v2 < h) {
	//	v2 *= 2;
	//}

	//// Make power of two version of the image.
	//std::vector<unsigned char> image2(u2 * v2 * 4);
	//for (size_t y = 0; y < h; y++) {
	//	for (size_t x = 0; x < w; x++) {
	//		for (size_t c = 0; c < 4; c++) {
	//			image2[4 * u2 * y + 4 * x + c] = data[4 * w * y + 4 * x + c];
	//		}
	//	}
	//}

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D,
	             0,
	             4,
	             static_cast<GLsizei>(h),
	             static_cast<GLsizei>(w),
	             0,
	             GL_RGBA,
	             GL_UNSIGNED_BYTE,
				 data);

	return 0;
}