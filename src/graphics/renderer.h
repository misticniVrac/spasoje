#ifndef RENDERER_H
#define RENDERER_H

#pragma once

#include <GL/glew.h>
#include <string>

#include "../math/vector.h"
#include "../math/matrix.h"
#include "texture2d.h"
#include "shader.h"
#include "font.h"
namespace spasoje
{
namespace renderer
{


	


	GLuint genQuad();
	

	void drawSprite(Shader &shader, Texture2D &texture, Vector2 position, Vector2 size, GLfloat rotation, Vector3 color);

	
	

	
	void drawText(Font font,std::string text,Shader shader,Vector2 position,float scale,Vector3 color);
	
	extern Matrix4 projection;

	inline void setProjectionOrtho(float width,float height)
	{

		projection = Matrix4::orthographic(0.0f,width,0,height,-1.0,1.0);
	}

	inline Matrix4 getProjection()
	{
		return projection;
	}

	float fps();

}

}
#endif
