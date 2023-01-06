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
	Model(const char* objFile, const char* texFileBark, const char* texFileLeaves, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));
	Model(const Model& oldModel, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));
	Model(const Model& oldModel, const char* newTexture, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));
	void DrawModel(Shader& shader, Camera& camera, glm::mat4 model, bool tank2 = false);
};

