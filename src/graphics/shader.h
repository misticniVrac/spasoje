#pragma once


#include <GL/glew.h>
#include "../math/vector.h"
#include "../math/matrix.h"

namespace spasoje{

class Shader
{
	GLuint id;

	public:
		Shader(const char* vertexPath,const char* fragmentPath);
		void start();
		void stop();

		void setBool(const char *name,bool val);
		void setInt(const char *name,int val);
		void setFloat(const char *name,float val);
		void setVector2(const char *name,Vector2 val);
		void setVector3(const char *name,Vector3 val);
		void setMatrix4(const char *name,Matrix4 val);
};
}
