#include "Floor.h"

//Floor::Floor()
//{
//	floor = new Shader("Floor");
//	float floorVertices[] = {
//		// positions          // texture Coords 
//		5.0f, -0.5f,  5.0f,  1.0f, 0.0f,
//		-5.0f, -0.5f,  5.0f,  0.0f, 0.0f,
//		-5.0f, -0.5f, -5.0f,  0.0f, 1.0f,
//
//		5.0f, -0.5f,  5.0f,  1.0f, 0.0f,
//		-5.0f, -0.5f, -5.0f,  0.0f, 1.0f,
//		5.0f, -0.5f, -5.0f,  1.0f, 1.0f
//	};
//	glGenVertexArrays(1, &floorVAO);
//	glGenBuffers(1, &floorVBO);
//	glBindVertexArray(floorVAO);
//	glBindBuffer(GL_ARRAY_BUFFER, floorVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(floorVertices), &floorVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	floorTexture = CreateTexture("../../../External/terrain/terrain.png");
//}
//void Floor::draw()
//{
//	glBindVertexArray(floorVAO);
//	glBindTexture(GL_TEXTURE_2D, floorTexture);
//}
//unsigned int Floor::CreateTexture(const std::string& strTexturePath)
//{
//	unsigned int textureId = -1;
//
//	// load image, create texture and generate mipmaps
//	int width, height, nrChannels;
//	//stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
//	unsigned char* data = stbi_load(strTexturePath.c_str(), &width, &height, &nrChannels, 0);
//	if (data) {
//		GLenum format;
//		if (nrChannels == 1)
//			format = GL_RED;
//		else if (nrChannels == 3)
//			format = GL_RGB;
//		else if (nrChannels == 4)
//			format = GL_RGBA;
//
//		glGenTextures(1, &textureId);
//		glBindTexture(GL_TEXTURE_2D, textureId);
//		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//
//		// set the texture wrapping parameters
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, format == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
//		// set texture filtering parameters
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	}
//	else {
//		std::cout << "Failed to load texture: " << strTexturePath << std::endl;
//	}
//	stbi_image_free(data);
//
//	return textureId;
//}
