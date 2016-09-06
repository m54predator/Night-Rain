#include "Shader_Programm.h"

Shader_Programm::Shader_Programm(const Shader &fragShader, const Shader &vertexShader) : frag_shader(fragShader), 
vert_shader(vertexShader) 
{}

SDL_bool Shader_Programm::CompileShaderProgram() {
	return CompileShaderProgram(this);
}

SDL_bool Shader_Programm::CompileShaderProgram(Shader_Programm * shaderProgramm)
{
	const int num_tmus_bound = 4;
	int i;
	GLint location;

	glGetError();

	/* Create one program object to rule them all */
	shaderProgramm->program = Shaders_Func::glCreateProgramObjectARB();

	/* ... and in the darkness bind them */
	Shaders_Func::glAttachObjectARB(shaderProgramm->program, shaderProgramm->vert_shader.shader);
	Shaders_Func::glAttachObjectARB(shaderProgramm->program, shaderProgramm->frag_shader.shader);
	Shaders_Func::glLinkProgramARB(shaderProgramm->program);

	/* Set up some uniform variables */
	Shaders_Func::glUseProgramObjectARB(shaderProgramm->program);
	for (i = 0; i < num_tmus_bound; ++i) {
		char tex_name[5];
		SDL_snprintf(tex_name, SDL_arraysize(tex_name), "tex%d", i);
		location = Shaders_Func::glGetUniformLocationARB(shaderProgramm->program, tex_name);
		if (location >= 0) {
			Shaders_Func::glUniform1iARB(location, i);
		}
	}
	Shaders_Func::glUseProgramObjectARB(0);

	return (glGetError() == GL_NO_ERROR) ? SDL_TRUE : SDL_FALSE;
}