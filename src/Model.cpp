 #include "Model.h"

Model::Model(const char* objFile, const char* texFile, glm::vec3 position)
{
	std::vector<Vertex> verticesVec = loadOBJ(objFile);
	
	Texture textures[]{ Texture(texFile, "texture1", 0, GL_RGBA, GL_UNSIGNED_BYTE) };
	std::vector<Texture> texturesVec(textures, textures + sizeof(textures) / sizeof(Texture));

	std::vector <GLuint> indices{};
	for (int i = 0; i < verticesVec.size(); i++)
	{
		indices.push_back(i);
	}
	std::cout << "There are " << indices.size() << " indices" << '\n';
	
	this->meshes.push_back(Mesh(verticesVec, indices, texturesVec));
	
	this->position = position;
}

Model::Model(const char* objFile, const char* texFileBark, const char* texFileLeaves, glm::vec3 position)
{
	std::vector<Vertex> verticesVec = loadOBJ(objFile);
	Texture textures[]{
		Texture(texFileBark, "bark", 0, GL_RGBA, GL_UNSIGNED_BYTE),
		Texture(texFileLeaves, "leaves", 1, GL_RGBA, GL_UNSIGNED_BYTE)
	};
	std::vector<Texture> texturesVec(textures, textures + sizeof(textures) / sizeof(Texture));
	std::vector <GLuint> indices{};
	for (int i = 0; i < verticesVec.size(); i++)
	{
		indices.push_back(i);
	}
	std::cout << "There are " << indices.size() << " indices" << '\n';
	
	this->meshes.push_back(Mesh(verticesVec, indices, texturesVec));

	this->position = position;
}

Model::Model(const Model& oldModel, glm::vec3 position)
{
	meshes.push_back(oldModel.meshes[0]);
	this->position = position;
}

Model::Model(const Model& oldModel, const char* newTexture, glm::vec3 position)
{
	meshes.push_back(oldModel.meshes[0]);
	meshes[0].textures[0] = Texture(newTexture, "texture1", 0, GL_RGBA, GL_UNSIGNED_BYTE);
	this->position = position;
}

void Model::DrawModel(Shader& shader, Camera& camera, glm::mat4 model, bool tank2)
{
	for (int i = 0; i < meshes.size(); i++)
	{
		if(!tank2)
		meshes[i].Draw(shader, camera, glm::translate(model, position));
		else
		{
			meshes[i].Draw(shader, camera, glm::translate(model, position), tank2);
		}
	}
}
