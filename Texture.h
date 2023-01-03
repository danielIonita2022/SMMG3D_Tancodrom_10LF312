#pragma once
#include "Shader.h"
#include <stb_image.h>

class Texture
{
public:
	const char* type;
	GLuint unit;
	Texture(const char* image, const char* texType, GLuint slot, GLenum format, GLenum pixelType);
	GLuint getTextureID() const;
	void texUnit(Shader& shader, const char* uniform, GLuint unit);
	void Bind();
	void Unbind();
	void Delete();
	
private:
	GLuint textureId;
};

