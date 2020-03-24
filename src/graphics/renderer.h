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
	extern Matrix4 camera;


	inline void translateCamera(Vector2 val)
	{
		camera = Matrix4::translate(camera,Vector3(val,0));
	}
	
	inline void scaleCamera(Vector2 val)
	{
		camera = Matrix4::scale(camera,Vector3(val,0));
	}

	inline void translateCamera(float val)
	{
		scaleCamera(Vector2(val));
	}

	inline void setProjectionOrtho(float width,float height)
	{
		projection = Matrix4::orthographic(0.0f,width,0,height,-1.0,1.0);
	}

	inline Matrix4 getProjection()
	{
		return projection;
	}
	inline Matrix4 getCamera()
	{
		return camera;
	}

	float fps();

}

}
#endif
