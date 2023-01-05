#pragma once
#include "Mesh.h"
#include "OBJLoader.h"
class Model
{
private:
	std::vector<Mesh> meshes;
	glm::vec3 position;

public:
	Model(const char* objFile, const char* texFile, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));
	void DrawModel(Shader& shader, Camera& camera, glm::mat4 model);
};

