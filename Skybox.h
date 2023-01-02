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
	Skybox();
	void draw(const glm::mat4& view, const glm::mat4& projection);
	Shader* getShader() const;

private:
    Shader* shader;
	unsigned int cubemapTexture;
	GLuint skyboxVAO;
	GLuint skyboxVBO;
    std::vector<std::string> faces
    {
            "../../../External/skybox/right.jpg",
            "../../../External/skybox/left.jpg",
            "../../../External/skybox/top.jpg",
            "../../../External/skybox/bottom.jpg",
            "../../../External/skybox/front.jpg",
            "../../../External/skybox/back.jpg"
    };

	GLuint loadCubemap(const std::vector<std::string>& faces);
};