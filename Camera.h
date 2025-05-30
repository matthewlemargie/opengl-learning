#define GLM_ENABLE_EXPERIMENTAL
#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"

class Camera
{
public:
	glm::vec3 Position;
	glm::vec3 initialPosition;
	glm::vec3 Orientation = glm::vec3(-1.0f, 0.0f, 0.0f);
	glm::vec3 initialOrientation = glm::vec3(-1.0f, 0.0f, 0.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 cameraMatrix = glm::mat4(1.0f);
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	float FOVdeg, nearPlane, farPlane;

	float hNear, hFar, wNear, wFar;

	bool firstClick = true;

	double mouseX, mouseY;

	GLuint VAO, VBO;

	float rayLength = 30.0f;

	int width;
	int height;

	float speed = 0.5f;
	float sensitivity = 100.0f;

	Camera(int width, int height, glm::vec3 position, float FOVdeg, float nearPlane, float farPlane);

	void updateMatrix();
	void Matrix(Shader& shader, const char* uniform);
	void Inputs(GLFWwindow*);
	void drawFrustum(Shader rayShader, glm::mat4 proj, glm::mat4 vw);
};

#endif // !CAMERA_CLASS_H
