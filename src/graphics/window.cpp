
#include <GL/glew.h>
#include <iostream>

#include "window.h"

namespace spasoje{

Window::Window(int width,int height,char *title)
{
	this->height = height;
	this->width = width;
	this->title = title;	
}

void 
Window::init()
{

	if(!glfwInit())
	{
		std::cout << "could not start glfw" << "\n";
		exit(EXIT_FAILURE);
	}
	

	if(!(this->gWindow = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL)))
	{
		std::cout << "could not create GLFWwindow" << "\n";
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(this->gWindow);

	if(glewInit() != GLEW_OK)
	{
		std::cout << "could not start GLEW" << "\n";
		exit(EXIT_FAILURE);
	}

	std::cout << "OpenGl v "<< glGetString(GL_VERSION) << "\n";	
}

void
Window::destroy()
{
	std::cout << "exiting window " << this->title << "\n";
	glfwDestroyWindow(this->gWindow);
}

bool
Window::isOpen()
{
	return !glfwWindowShouldClose(this->gWindow);
}

void 
Window::update()
{
	glfwSwapBuffers(this->gWindow);
	glfwPollEvents();
}

}
