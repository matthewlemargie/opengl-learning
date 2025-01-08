#define GLM_ENABLE_EXPERIMENTAL
#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include<glew/include/GL/glew.h>
#include <iostream>
#include <gl/GL.h>
#include <glm.hpp>
#include <vector>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	//glm::vec2 texUV;
};

class VBO
{
public:
	GLuint ID;
	GLuint instanceID = 0;
	int numInstances = 0;
	VBO();

	void addVertices(std::vector<Vertex>& vertices);
	void addInstance(std::vector<glm::mat4>& instanceMats);
	void resetInstances(std::vector<glm::mat4>& instanceMats);
	void Bind();
	void bindInstance();
	void Unbind();
	void Delete();
};

#endif
