#pragma once
#include <string>
#include <vector>
#include <GLM.hpp>
#include <GL/glew.h>
#include <glfw3.h>
#include "Shader.h"
class Floor
{
public:
	Floor();
	~Floor();
	unsigned int CreateTexture(const std::string& strTexturePath);
	void draw();
private:
	Shader* floor;
	unsigned int floorVAO;
	unsigned int floorVBO;
	unsigned int floorTexture;
	
};

