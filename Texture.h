#pragma once
#include "Shader.h"
#include <stb_image.h>

class Texture
{
public:
	Texture(const std::string& strTexturePath);
	GLuint getTextureID() const;
	// Unbinds a texture
	void Unbind();
	// Deletes a texture
	void Delete();
private:
	GLuint textureId;
};

