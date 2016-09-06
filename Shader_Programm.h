#ifndef _SHADERS_PROGRAMM_H
#define _SHADERS_PROGRAMM_H

#include "Shaders.h"

class Shader_Programm {
public:
	GLhandleARB program;
	Shader vert_shader;
	Shader frag_shader;

	Shader_Programm(const Shader &fragShader, const Shader &vertexShader);

	SDL_bool CompileShaderProgram();

private:
	static SDL_bool CompileShaderProgram(Shader_Programm * shaderProgramm);
};

#endif