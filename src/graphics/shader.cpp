
#include <string>
#include <iostream>

#include "shader.h"
#include "../filehandler.h"

#include <GLFW/glfw3.h>

using namespace std;

namespace spasoje{

Shader::Shader(const char* vertexPath,const char* fragmentPath)
{
	string vertex,fragment;
	
	vertex	= read_file(vertexPath);
	fragment = read_file(fragmentPath);

	unsigned int v_id,f_id;
	int success;
	char infoLog[512];

	//vertex shader
	
	const char *vertexCode = vertex.c_str();

	v_id = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(v_id,1,&vertexCode,NULL);
	glCompileShader(v_id);
	glGetShaderiv(v_id,GL_COMPILE_STATUS,&success);

	if(!success)
	{
		glGetProgramInfoLog(v_id, 512, NULL, infoLog);
		cout << "could not compile vertex shader " << vertexPath << "\n"
		<< "LOG: " << infoLog << "\n";
		
	}	

	//fragment shader
	
	const char *fragmentCode = fragment.c_str();

	f_id = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(f_id,1,&fragmentCode,NULL);
	glCompileShader(f_id);
	glGetShaderiv(f_id,GL_COMPILE_STATUS,&success);

	if(!success)
	{
		glGetProgramInfoLog(v_id, 512, NULL, infoLog);
		cout << "could not compile fragment shader " << vertexPath << "\n"
		<< "LOG: " << infoLog << "\n";
		
	}	

	//shader program
	
	this->id = glCreateProgram();
	glAttachShader(this->id,v_id);
	glAttachShader(this->id,f_id);

	glLinkProgram(this->id);

	
	glGetProgramiv(this->id, GL_LINK_STATUS, &success);
	if(!success)
	{
		    glGetProgramInfoLog(this->id, 512, NULL, infoLog);
		    cout << "could not link shader " << infoLog << "\n";
	}

	glDeleteShader(v_id);
	glDeleteShader(f_id);
}

void
Shader::start()
{
	glUseProgram(this->id);
}

void
Shader::stop()
{
	glUseProgram(0);
}

}
