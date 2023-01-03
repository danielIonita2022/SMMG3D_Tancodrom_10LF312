#include "VBO.h"
#include <vector>

class EBO
{
public:
	GLuint ID;
	
	// Constructor that generates an Elements Buffer Object and links it to indices
	EBO(std::vector <GLuint>& indices);
	
	void Bind();
	void Unbind();
	void Delete();
};
