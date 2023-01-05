#pragma once
#include "Skybox.h"
#include "Camera.h"
#include "Texture.h"
#include "Mesh.h"
#include "Model.h"

#pragma comment (lib, "glfw3dll.lib")
#pragma comment (lib, "glew32.lib")
#pragma comment (lib, "OpenGL32.lib")

const unsigned int SCR_WIDTH = 1500;
const unsigned int SCR_HEIGHT = 1000;
Camera* pCamera;
// timing
double deltaTime = 0.0f;	// time between current frame and last frame
double lastFrame = 0.0f;
bool day = true;
bool buttonPressed = false;

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


Vertex lightVertices[] =
{
    Vertex{glm::vec3(10.0f, 10.0f,  10.2f)},
    Vertex{glm::vec3(10.0f, 10.0f, 10.0f)},
    Vertex{glm::vec3(10.2f, 10.0f, 10.0f)},
    Vertex{glm::vec3(10.2f, 10.0f,  10.2f)},
    Vertex{glm::vec3(10.0f,  10.2f,  10.2f)},
    Vertex{glm::vec3(10.0f,  10.2f, 10.0f)},
    Vertex{glm::vec3(10.2f,  10.2f, 10.0f)},
    Vertex{glm::vec3(10.2f,  10.2f,  10.f)}
};

GLuint lightIndices[] =
{
    0, 1, 2,
    0, 2, 3,
    0, 4, 7,
    0, 7, 3,
    3, 7, 6,
    3, 6, 2,
    2, 6, 5,
    2, 5, 1,
    1, 5, 4,
    1, 4, 0,
    4, 5, 6,
    4, 6, 7
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
    if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
    {
        day = false;
        buttonPressed = true;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        day = true;
        buttonPressed = true;
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
    std::vector<std::string> dayFaces
    {
            "../../../External/skybox/right.jpg",
            "../../../External/skybox/left.jpg",
            "../../../External/skybox/top.jpg",
            "../../../External/skybox/bottom.jpg",
            "../../../External/skybox/front.jpg",
            "../../../External/skybox/back.jpg"
    };
    std::vector<std::string> nightFaces
    {
            "../../../External/new_skybox_night/right.jpg",
            "../../../External/new_skybox_night/left.jpg",
            "../../../External/new_skybox_night/top.jpg",
            "../../../External/new_skybox_night/bottom.jpg",
            "../../../External/new_skybox_night/front.jpg",
            "../../../External/new_skybox_night/back.jpg"
    };


    Skybox skybox(dayFaces);

    glEnable(GL_DEPTH_TEST);
    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Initialize();
    glDepthMask(GL_FALSE);
    glDisable(GL_CULL_FACE);


    std::string image = strExePath + "\\terrain.png";
    Texture textures[]{ Texture(image.c_str(), "texture1", 0, GL_RGBA, GL_UNSIGNED_BYTE) };
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

    const char* objFilePath = "../../../External/models/tank1/tank1.obj";
    const char* texFilePath = "../../../External/models/tank1/tank1.jpg";
    Model tank1(objFilePath, texFilePath, glm::vec3(0.0f, 0.0f, 0.0f));
    //const char* objFilePath1 = "../../../External/models/eli3/Heli_bell.obj";
    //const char* texFilePath1 = "../../../External/models/elicopter1/image2.jpg";
    //Model eli1(objFilePath1, texFilePath1, glm::vec3(0.0f, 0.0f, 10.0f));

    Shader lightShader("Light.vs", "Light.fs");
    std::vector <Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(Vertex));
    std::vector <GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint));
    // Crate light mesh
    Mesh light(lightVerts, lightInd, tex);

    glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);
    glm::mat4 lightModel = glm::mat4(1.0f);
    lightModel = glm::translate(lightModel, lightPos);

    // Create floor mesh
    Mesh floor(verts, ind, tex);
    Mesh grass(grassVerts, ind, grassTex);
    Mesh revGrass(revGrassVerts, ind, grassTex);

    lightShader.Use();
    glUniformMatrix4fv(glGetUniformLocation(lightShader.GetID(), "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
    glUniform4f(glGetUniformLocation(lightShader.GetID(), "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);

    glm::vec3 objectPos = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::mat4 objectModel = glm::mat4(1.0f);
    objectModel = glm::translate(objectModel, objectPos);

    floorShader.Use();
    glUniformMatrix4fv(glGetUniformLocation(floorShader.GetID(), "model"), 1, GL_FALSE, glm::value_ptr(objectModel));
    glUniform4f(glGetUniformLocation(floorShader.GetID(), "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
    glUniform3f(glGetUniformLocation(floorShader.GetID(), "lightPos"), lightPos.x, lightPos.y, lightPos.z);

    floorShader.SetInt("day", 1);

    pCamera = new Camera(SCR_WIDTH, SCR_HEIGHT, glm::vec3(0.0f, 0.5f, 2.0f));
    while (!glfwWindowShouldClose(window))
    {
        double currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        processInput(window);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if (buttonPressed)
        {
            if (day)
            {
                skybox.setCubemapTexture(skybox.loadCubemap(dayFaces));
                floorShader.SetInt("day", 1);
            }
            else if (!day)
            {
                skybox.setCubemapTexture(skybox.loadCubemap(nightFaces));
                floorShader.SetInt("day", 0);
            }
            buttonPressed = false;
        }
        glm::mat4 model;
        glm::mat4 projection = pCamera->GetProjectionMatrix();
        glm::mat4 view = pCamera->GetViewMatrix();
        skybox.draw(view, projection);
        model = glm::mat4();
        floorShader.Use();
        floor.Draw(floorShader, *pCamera);
        for (GLuint i = 0; i < vegetation.size(); ++i)
        {
            glEnable(GL_DEPTH_TEST);
            glEnable(GL_BLEND);
            glDepthMask(true);
            model = glm::mat4(1.0f);
            model = glm::translate(model, vegetation[i]);
            grass.Draw(floorShader, *pCamera, model);
            revGrass.Draw(floorShader, *pCamera, model);
        }
        float angle = 90.0f;
        model = glm::mat4(1.0f);
        glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(-1.0f, 0.0f, 0.0f));
        model = model * rotation;
        tank1.DrawModel(floorShader, *pCamera, model);
        //eli1.DrawModel(floorShader, *pCamera, model);
        if (!day)
        {
            light.Draw(lightShader, *pCamera);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}