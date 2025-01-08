#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include <string>
#include <vector>
#include <glm/glm.hpp>

#include "ModelLoader.h"
#include "VAO.h"
#include "EBO.h"
#include "Texture.h"
#include "Camera.h"

class Mesh
{
public:
    glm::mat4 model = glm::mat4(1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, 1.0f);

    float speed = 0.025f;
    float sensitivity = 100.0f;

    bool firstClick = true;

    std::vector<Vertex> lowVertices;
    std::vector<Vertex> medVertices;
    std::vector<Vertex> highVertices;
    std::vector<GLuint> lowIndices;
    std::vector<GLuint> medIndices;
    std::vector<GLuint> highIndices;
    std::vector<glm::mat4> instanceMats;

    VAO lowVAO;
    VAO medVAO;
    VAO highVAO;
    VBO lowVBO;
    VBO medVBO;
    VBO highVBO;

    vector<glm::mat4> lowMats = {};
    vector<glm::mat4> medMats = {};
    vector<glm::mat4> highMats = {};

    int numInstances = 0;

    Mesh(const std::string& low, const std::string& med, const std::string& high);

    void addInstance(glm::mat4 instanceMats);
    void resetInstances(Camera& camera);
    void Draw(Shader& shader, Camera& camera, glm::vec3 lightPos, glm::vec4 lightColor);

    void Inputs(GLFWwindow* window);
};

#endif

