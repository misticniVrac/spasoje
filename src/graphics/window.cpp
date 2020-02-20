
#include <GL/glew.h>
#include <iostream>

#include "window.h"

namespace spasoje{

Window::Window(char *title,int width,int height)
{
	this->m_height = height;
	this->m_width = width;
	this->m_title = title;	
}

void 
Window::init()
{

	if(!glfwInit())
	{
		std::cout << "could not start glfw" << "\n";
		exit(EXIT_FAILURE);
	}
	

	if(this->m_height==1)//if window size has been left default, set window to fullscreen
	{
		getScreenSize();
		this->m_isFullscreen = true;
		this->gMonitor=glfwGetPrimaryMonitor();
	}
	if(!(this->gWindow = glfwCreateWindow(this->m_width, this->m_height, this->m_title, this->gMonitor, NULL)))
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
	std::cout << "exiting window " << this->m_title << "\n";
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

void 
Window::getScreenSize()
{
	
	 const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    	 this->m_width = mode->width;
         this->m_height = mode->height;


}

bool Window::isFullscreen(){ return this->m_isFullscreen; }

void 
Window::setFullscreen(bool fs)
{

	if(gMonitor = fs?glfwGetPrimaryMonitor():nullptr)
	{
		this->m_isFullscreen = true;
		const	GLFWvidmode* mode = glfwGetVideoMode(this->gMonitor);
		glfwSetWindowMonitor(this->gWindow,this->gMonitor,0, 0, mode->width, mode->height, mode->refreshRate);
	}
	else
	{
		this->m_isFullscreen = false;
		glfwSetWindowMonitor(this->gWindow,this->gMonitor,0, 0, this->m_width,this->m_height, 0);
	}
}

int Window::getWidth(){ return this->m_width; }
int Window::getHeight(){ return this->m_height; }

}
