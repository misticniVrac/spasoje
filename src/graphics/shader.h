#pragma once


#include <GL/glew.h>

namespace spasoje{

class Shader
{
	GLuint id;

	public:
		Shader(const char* vertexPath,const char* fragmentPath);
		void start();
		void stop();




};
}
