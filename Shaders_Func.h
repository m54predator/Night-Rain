#ifndef _SHADERS_FUNC_H
#define _SHADERS_FUNC_H

#include <SDL.h>
#include <SDL_opengl.h>

#include <string>

class Shaders_Func {
public:
	static PFNGLATTACHOBJECTARBPROC glAttachObjectARB;
	static PFNGLCOMPILESHADERARBPROC glCompileShaderARB;
	static PFNGLCREATEPROGRAMOBJECTARBPROC glCreateProgramObjectARB;
	static PFNGLCREATESHADEROBJECTARBPROC glCreateShaderObjectARB;
	static PFNGLDELETEOBJECTARBPROC glDeleteObjectARB;
	static PFNGLGETINFOLOGARBPROC glGetInfoLogARB;
	static PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB;
	static PFNGLGETUNIFORMLOCATIONARBPROC glGetUniformLocationARB;
	static PFNGLLINKPROGRAMARBPROC glLinkProgramARB;
	static PFNGLSHADERSOURCEARBPROC glShaderSourceARB;
	static PFNGLUNIFORM1IARBPROC glUniform1iARB;
	static PFNGLUSEPROGRAMOBJECTARBPROC glUseProgramObjectARB;

	static SDL_bool shaders_supported;

	static SDL_bool InitShaders();
};

#endif