#pragma once
#include "Skybox.h"
#include "Camera.h"
#include "Texture.h"
#include "Mesh.h"

#pragma comment (lib, "glfw3dll.lib")
#pragma comment (lib, "glew32.lib")
#pragma comment (lib, "OpenGL32.lib")

const unsigned int SCR_WIDTH = 1500;
const unsigned int SCR_HEIGHT = 1000;
Camera* pCamera;
// timing
double deltaTime = 0.0f;	// time between current frame and last frame
double lastFrame = 0.0f;


Vertex vertices[] =
{ //               COORDINATES           /            COLORS          /           TexCoord         /       NORMALS         //
    Vertex{glm::vec3(-25.0f, 0.0f,  25.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
    Vertex{glm::vec3(-25.0f, 0.0f, -25.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
    Vertex{glm::vec3(25.0f, 0.0f, -25.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
    Vertex{glm::vec3(25.0f, 0.0f,  25.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
};

GLuint indices[] =
{
    0, 1, 2,
    0, 2, 3
};

Vertex grassVertices[] =
{
    Vertex{glm::vec3(0.0f,  1.0f,  0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
    Vertex{glm::vec3(0.0f, 0.0f,  0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
    Vertex{glm::vec3(1.0f, 0.0f,  0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
    Vertex{glm::vec3(1.0f,  1.0f,  0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
};

Vertex revgrassVertices[] =
{
    Vertex{glm::vec3(1.5f,  1.0f,  -0.55f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f)},
    Vertex{glm::vec3(1.5f, 0.0f,  -0.55f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 1.0f)},
    Vertex{glm::vec3(1.5f, 0.0f, 0.45f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 1.0f)},
    Vertex{glm::vec3(1.5f,  1.0f,  0.45f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(1.0f, 0.0f)}
};

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        pCamera->ProcessKeyboard(ECameraMovementType::FORWARD, (float)deltaTime);
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        pCamera->ProcessKeyboard(ECameraMovementType::BACKWARD, (float)deltaTime);
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        pCamera->ProcessKeyboard(ECameraMovementType::LEFT, (float)deltaTime);
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        pCamera->ProcessKeyboard(ECameraMovementType::RIGHT, (float)deltaTime);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        pCamera->ProcessKeyboard(ECameraMovementType::UP, (float)deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        pCamera->ProcessKeyboard(ECameraMovementType::DOWN, (float)deltaTime);

    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
        int width, height;
        glfwGetWindowSize(window, &width, &height);
        pCamera->Reshape(width, height);

    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    pCamera->Reshape(width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    pCamera->MouseControl((float)xpos, (float)ypos);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yOffset)
{
    pCamera->ProcessMouseScroll((float)yOffset);
}


void Initialize()
{
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char** argv)
{
    std::string strFullExeFileName = argv[0];
    std::string strExePath;
    const size_t last_slash_idx = strFullExeFileName.rfind('\\');
    if (std::string::npos != last_slash_idx) {
        strExePath = strFullExeFileName.substr(0, last_slash_idx);
    }

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Proiect", NULL, NULL);
    
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
    glewInit();
    Skybox skybox;
    
    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Initialize();
    glDepthMask(GL_FALSE);
    glDisable(GL_CULL_FACE);

    
    std::string image = strExePath + "\\terrain.png";
    Texture textures[]{Texture(image.c_str(), "texture1", 0, GL_RGBA, GL_UNSIGNED_BYTE)};
    GLuint floorTexId = textures[0].getTextureID();

	std::string grassImage = strExePath + "\\grass.png";
	Texture grassTextures[]{ Texture(grassImage.c_str(), "texture1", 0, GL_RGBA, GL_UNSIGNED_BYTE) };
	GLuint grassTexId = grassTextures[0].getTextureID();
    
    // positions of grass patches
    std::vector <glm::vec3> vegetation;
    float high = 15.0f;
    for (float i = -15.0f; i < high; i += 1.0f)
    {
        for (float j = -15.0f; j < high; j += 1.0f)
        {
            vegetation.emplace_back(glm::vec3(i, 0, j));
        }
    }
    
	Shader floorShader("Floor.vs", "Floor.fs");

    std::vector <Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
    std::vector <GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
    std::vector <Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
    
    std::vector <Vertex> grassVerts(grassVertices, grassVertices + sizeof(grassVertices) / sizeof(Vertex));
    std::vector <Texture> grassTex(grassTextures, grassTextures + sizeof(grassTextures) / sizeof(Texture));
    
    std::vector <Vertex> revGrassVerts(revgrassVertices, revgrassVertices + sizeof(revgrassVertices) / sizeof(Vertex));
    
    // Create floor mesh
    Mesh floor(verts, ind, tex);
	Mesh grass(grassVerts, ind, grassTex);
    Mesh revGrass(revGrassVerts, ind, grassTex);

    /*floorShader.Use();
    floorShader.SetInt("texture1", 0);*/

    pCamera = new Camera(SCR_WIDTH, SCR_HEIGHT, glm::vec3(0.0f, 0.5f, 2.0f));
    while (!glfwWindowShouldClose(window))
    {
        double currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        processInput(window);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        
        glm::mat4 model;
        glm::mat4 projection = pCamera->GetProjectionMatrix();
        glm::mat4 view = pCamera->GetViewMatrix();
        skybox.draw(view, projection);
		model = glm::mat4();
        floorShader.Use();
        floor.Draw(floorShader, *pCamera);
        for (GLuint i = 0; i < vegetation.size(); ++i)
        {
            //glEnable(GL_DEPTH_TEST);
            //glEnable(GL_BLEND);
            glDepthMask(true);
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, vegetation[i]);
			grass.Draw(floorShader, *pCamera, model);
            revGrass.Draw(floorShader, *pCamera, model);
        }
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}



