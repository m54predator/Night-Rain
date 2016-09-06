#ifndef _SHADERS_HANDLER_H
#define _SHADERS_HANDLER_H

#include <vector>
#include <memory>
#include <string>

#include "Shader_Programm.h"

class Shaders_Handler
{
public:
	Shaders_Handler();
	~Shaders_Handler() = default;
	std::shared_ptr<Shader_Programm> Add_Shaders(const std::string &fragShader, const std::string &vertexShader);
	void All_Compile();
	void Init();

	std::vector<std::shared_ptr<Shader_Programm>> user_shaders;
	std::unique_ptr<Shader_Programm> shader_color, shader_texture, shader_texcoords;
private:
	bool init;
};

#endif