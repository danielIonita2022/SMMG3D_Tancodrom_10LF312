#pragma once
#include <string>
#include <vector>
#include <GLM.hpp>
#include <GL/glew.h>
#include <glfw3.h>
#include "Shader.h"
#include <stb_image.h>

class Skybox
{
public:
	Skybox(const std::vector<std::string>& skyboxFaces);
	void draw(const glm::mat4& view, const glm::mat4& projection);
	Shader* getShader() const;
	void setCubemapTexture(unsigned int cubemapTex);
	GLuint loadCubemap(const std::vector<std::string>& faces);

private:
    Shader* shader;
	unsigned int cubemapTexture;
	GLuint skyboxVAO;
	GLuint skyboxVBO;

	
};