#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include <vector>
#include <string>
#include <GL/glew.h>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <sstream>
#include <fstream>
#include <iostream>


class Shader
{
public:
    Shader(const std::string& fileName);
    ~Shader();

    void Use() const;
    unsigned int GetID() const;

    // MVP
    unsigned int loc_model_matrix;
    unsigned int loc_view_matrix;
    unsigned int loc_projection_matrix;

    // utility uniform functions
    void SetInt(const char* name, int value) const;
    void SetFloat(const std::string& name, float value) const;
    void SetVec3(const std::string& name, const glm::vec3& value) const;
    void SetVec3(const std::string& name, float x, float y, float z) const;
    void SetMat4(const char* name, const glm::mat4& mat) const;

private:
    std::string LoadShader(const std::string& fileName);
    void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
    GLuint CreateShader(const std::string& text, unsigned int type);

private:
    unsigned int ID;
	unsigned int m_shaders[2];
	unsigned int m_uniforms[1];
    
};
