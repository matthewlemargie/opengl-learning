#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include "stb/stb_image.h"

#include "shaderClass.h"

class Texture
{
public:
	GLuint ID;
	const char* type;
	Texture(const char* image, const char* texType, GLenum slot, GLenum format, GLenum pixelType);

	void texUnit(Shader shader, const char* uniform, GLuint unit);
	void Bind();
	void Unbind();
	void Delete();

};

#endif // !TEXTURE_CLASS_H
