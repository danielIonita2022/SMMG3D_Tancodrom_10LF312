#include "Model.h"

Model::Model(const char* objFile, const char* texFile, glm::vec3 position)
{
	std::vector<Vertex> verticesVec = loadOBJ(objFile);
	
	Texture textures[]{ Texture(texFile, "texture1", 0, GL_RGBA, GL_UNSIGNED_BYTE) };
	std::vector<Texture> texturesVec(textures, textures + sizeof(textures) / sizeof(textures[0]));

	std::vector <GLuint> indices{};
	for (int i = 0; i < verticesVec.size(); i++)
	{
		indices.push_back(i);
	}
	std::cout << "There are " << indices.size() << " indices" << '\n';
	
	this->meshes.push_back(Mesh(verticesVec, indices, texturesVec));
	
	this->position = position;
}

void Model::DrawModel(Shader& shader, Camera& camera, glm::mat4 model)
{
	for (int i = 0; i < meshes.size(); i++)
	{
		meshes[i].Draw(shader, camera, glm::translate(model, position));
	}
}
