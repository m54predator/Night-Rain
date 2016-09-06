#include "Shaders_Func.h"

SDL_bool Shaders_Func::shaders_supported = SDL_FALSE;
PFNGLATTACHOBJECTARBPROC Shaders_Func::glAttachObjectARB = NULL;
PFNGLCOMPILESHADERARBPROC Shaders_Func::glCompileShaderARB = NULL;
PFNGLCREATEPROGRAMOBJECTARBPROC Shaders_Func::glCreateProgramObjectARB = NULL;
PFNGLCREATESHADEROBJECTARBPROC Shaders_Func::glCreateShaderObjectARB = NULL;
PFNGLDELETEOBJECTARBPROC Shaders_Func::glDeleteObjectARB = NULL;
PFNGLGETINFOLOGARBPROC Shaders_Func::glGetInfoLogARB = NULL;
PFNGLGETOBJECTPARAMETERIVARBPROC Shaders_Func::glGetObjectParameterivARB = NULL;
PFNGLGETUNIFORMLOCATIONARBPROC Shaders_Func::glGetUniformLocationARB = NULL;
PFNGLLINKPROGRAMARBPROC Shaders_Func::glLinkProgramARB = NULL;
PFNGLSHADERSOURCEARBPROC Shaders_Func::glShaderSourceARB = NULL;
PFNGLUNIFORM1IARBPROC Shaders_Func::glUniform1iARB = NULL;
PFNGLUSEPROGRAMOBJECTARBPROC Shaders_Func::glUseProgramObjectARB = NULL;

SDL_bool Shaders_Func::InitShaders() {
	/* Check for shader support */
	shaders_supported = SDL_FALSE;
	if (SDL_GL_ExtensionSupported("GL_ARB_shader_objects") &&
		SDL_GL_ExtensionSupported("GL_ARB_shading_language_100") &&
		SDL_GL_ExtensionSupported("GL_ARB_vertex_shader") &&
		SDL_GL_ExtensionSupported("GL_ARB_fragment_shader")) {
		glAttachObjectARB = (PFNGLATTACHOBJECTARBPROC)SDL_GL_GetProcAddress("glAttachObjectARB");
		glCompileShaderARB = (PFNGLCOMPILESHADERARBPROC)SDL_GL_GetProcAddress("glCompileShaderARB");
		glCreateProgramObjectARB = (PFNGLCREATEPROGRAMOBJECTARBPROC)SDL_GL_GetProcAddress("glCreateProgramObjectARB");
		glCreateShaderObjectARB = (PFNGLCREATESHADEROBJECTARBPROC)SDL_GL_GetProcAddress("glCreateShaderObjectARB");
		glDeleteObjectARB = (PFNGLDELETEOBJECTARBPROC)SDL_GL_GetProcAddress("glDeleteObjectARB");
		glGetInfoLogARB = (PFNGLGETINFOLOGARBPROC)SDL_GL_GetProcAddress("glGetInfoLogARB");
		glGetObjectParameterivARB = (PFNGLGETOBJECTPARAMETERIVARBPROC)SDL_GL_GetProcAddress("glGetObjectParameterivARB");
		glGetUniformLocationARB = (PFNGLGETUNIFORMLOCATIONARBPROC)SDL_GL_GetProcAddress("glGetUniformLocationARB");
		glLinkProgramARB = (PFNGLLINKPROGRAMARBPROC)SDL_GL_GetProcAddress("glLinkProgramARB");
		glShaderSourceARB = (PFNGLSHADERSOURCEARBPROC)SDL_GL_GetProcAddress("glShaderSourceARB");
		glUniform1iARB = (PFNGLUNIFORM1IARBPROC)SDL_GL_GetProcAddress("glUniform1iARB");
		glUseProgramObjectARB = (PFNGLUSEPROGRAMOBJECTARBPROC)SDL_GL_GetProcAddress("glUseProgramObjectARB");
		if (glAttachObjectARB &&
			glCompileShaderARB &&
			glCreateProgramObjectARB &&
			glCreateShaderObjectARB &&
			glDeleteObjectARB &&
			glGetInfoLogARB &&
			glGetObjectParameterivARB &&
			glGetUniformLocationARB &&
			glLinkProgramARB &&
			glShaderSourceARB &&
			glUniform1iARB &&
			glUseProgramObjectARB) {
			shaders_supported = SDL_TRUE;
		}
	}

	return shaders_supported;
}