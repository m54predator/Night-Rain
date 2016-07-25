#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <SDL_opengl.h>
#include <vector>

class Texture
{
public:
	Texture();
	~Texture();
	bool Set_Texture(void *data, size_t _w, size_t _h);
	GLuint texture_id;
private:
	
};


#endif