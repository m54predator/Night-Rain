#include "Shaders_Handler.h"

Shaders_Handler::Shaders_Handler() : init(false)
{};

void Shaders_Handler::Init()
{
	Shaders_Func::InitShaders();
	Shaders_Func::glCreateShaderObjectARB(GL_FRAGMENT_SHADER_ARB);
	Shader shad(std::string(
		"varying vec4 v_color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n"
		"    v_color = gl_Color;\n"
		"}"), 1);
	shader_color = std::make_unique<Shader_Programm>(Shader(std::string(
		"varying vec4 v_color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n"
		"    v_color = gl_Color;\n"
		"}"), 1),
		Shader(std::string("varying vec4 v_color;\n"
		"\n"
		"void main()\n"
		"{\n"
		"    gl_FragColor = v_color;\n"
		"}"), 0));

	shader_texture = std::make_unique<Shader_Programm>(
		Shader(std::string("varying vec4 v_color;\n"
		"varying vec2 v_texCoord;\n"
		"\n"
		"void main()\n"
		"{\n"
		"    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n"
		"    v_color = gl_Color;\n"
		"    v_texCoord = vec2(gl_MultiTexCoord0);\n"
		"}"), 1),
		Shader(std::string("varying vec4 v_color;\n"
		"varying vec2 v_texCoord;\n"
		"uniform sampler2D tex0;\n"
		"\n"
		"void main()\n"
		"{\n"
		"    gl_FragColor = texture2D(tex0, v_texCoord) * v_color;\n"
		"}"), 0));
	shader_texcoords = std::make_unique<Shader_Programm>(
		Shader(std::string("varying vec2 v_texCoord;\n"
		"\n"
		"void main()\n"
		"{\n"
		"    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n"
		"    v_texCoord = vec2(gl_MultiTexCoord0);\n"
		"}"), 1),
		Shader(std::string("varying vec2 v_texCoord;\n"
		"\n"
		"void main()\n"
		"{\n"
		"    vec4 color;\n"
		"    vec2 delta;\n"
		"    float dist;\n"
		"\n"
		"    delta = vec2(0.5, 0.5) - v_texCoord;\n"
		"    dist = dot(delta, delta);\n"
		"\n"
		"    color.r = v_texCoord.x;\n"
		"    color.g = v_texCoord.x * v_texCoord.y;\n"
		"    color.b = v_texCoord.y;\n"
		"    color.a = 1.0 - (dist * 4.0);\n"
		"    gl_FragColor = color;\n"
		"}"), 0));
	init = true;
}

std::shared_ptr<Shader_Programm> Shaders_Handler::Add_Shaders(const std::string &fragShader, const std::string &vertexShader)
{
	user_shaders.push_back(std::make_shared<Shader_Programm>(Shader(std::string(fragShader), 1), Shader(std::string(vertexShader), 0)));
	return user_shaders.back();
}

void Shaders_Handler::All_Compile()
{
	if (!init) this->Init();
	shader_color->CompileShaderProgram();
	shader_texture->CompileShaderProgram(); 
	shader_texcoords->CompileShaderProgram();
	for (auto &i : user_shaders)
		i->CompileShaderProgram();
}