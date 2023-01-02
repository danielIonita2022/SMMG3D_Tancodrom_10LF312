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
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void Use() const;
    unsigned int GetID() const;
    void Init(const char* vertexPath, const char* fragmentPath);

    // MVP
    unsigned int loc_model_matrix;
    unsigned int loc_view_matrix;
    unsigned int loc_projection_matrix;

    // utility uniform functions
    void SetInt(const std::string& name, int value) const;
    void SetFloat(const std::string& name, float value) const;
    void SetVec3(const std::string& name, const glm::vec3& value) const;
    void SetVec3(const std::string& name, float x, float y, float z) const;
    void SetMat4(const std::string& name, const glm::mat4& mat) const;

private:
    void CheckCompileErrors(unsigned int shaderStencilTesting, std::string type);
    
    unsigned int ID;
    
};
