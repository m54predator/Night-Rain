#ifndef _SHADERS_H
#define _SHADERS_H

#include "Shaders_Func.h"

class Shader {
public:
	std::string code;
	GLhandleARB shader;
	bool type;
	SDL_bool state;

	Shader(const std::string &&code, bool vertOrFrag);

	SDL_bool CompileShader();

private:
	static SDL_bool CompileShader(GLhandleARB shader, const char *source);
};



#endif