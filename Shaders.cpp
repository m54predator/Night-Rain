#include "Shaders.h"

Shader::Shader(const std::string &&code, bool vertOrFrag) : code(code),
type(vertOrFrag),
shader(Shaders_Func::glCreateShaderObjectARB(vertOrFrag ? GL_FRAGMENT_SHADER_ARB : GL_VERTEX_SHADER_ARB)),
state(SDL_FALSE)
{}

SDL_bool Shader::CompileShader() {
	state = CompileShader(shader, code.c_str());
	return state;
}

SDL_bool Shader::CompileShader(GLhandleARB shader, const char *source)
{
	GLint status;

	Shaders_Func::glShaderSourceARB(shader, 1, &source, NULL);
	Shaders_Func::glCompileShaderARB(shader);
	Shaders_Func::glGetObjectParameterivARB(shader, GL_OBJECT_COMPILE_STATUS_ARB, &status);
	if (status == 0) {
		GLint length;
		char *info;

		Shaders_Func::glGetObjectParameterivARB(shader, GL_OBJECT_INFO_LOG_LENGTH_ARB, &length);
		info = SDL_stack_alloc(char, length + 1);
		Shaders_Func::glGetInfoLogARB(shader, length, NULL, info);
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to compile shader:\n%s\n%s", source, info);
		SDL_stack_free(info);

		return SDL_FALSE;
	}
	else {
		return SDL_TRUE;
	}
}