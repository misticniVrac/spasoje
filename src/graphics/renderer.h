#pragma once

#include <GL/glew.h>

#include "../math/vector.h"
#include "texture2d.h"
#include "shader.h"

namespace spasoje
{
namespace renderer
{
	GLuint genSprite();
	void drawSprite(GLuint VAO, Shader &shader, Texture2D &texture, Vector2 position, Vector2 size, GLfloat rotation, Vector3 color);
}

}
