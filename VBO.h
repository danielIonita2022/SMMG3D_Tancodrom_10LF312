#pragma once
#include "Vertex.h"
#include <GL/glew.h>
#include <glfw3.h>
#include <vector>

class VBO
{
public:
	GLuint ID;
	
	// Constructor that generates a Vertex Buffer Object and links it to vertices
	VBO(std::vector <Vertex>& vertices);
	
	void Bind();
	void Unbind();
	void Delete();
};
