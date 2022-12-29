#pragma once
#include "Shader.h"
#include <stb_image.h>

class Texture
{
public:
	Texture(const std::string& strTexturePath);
	~Texture();
	void texUnit(Shader& shader, const char* uniform, GLuint unit);
	// Binds a texture
	void Bind();
	// Unbinds a texture
	void Unbind();
	// Deletes a texture
	void Delete();
private:
	GLuint textureId;
};

