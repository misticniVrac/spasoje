
#include <GL/glew.h>
#include <iostream>

#include "window.h"
#include "../input.h"
#include "../math/vector.h"
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
		Vector2 ss = getScreenSize();
		this->m_width = ss.x;
		this->m_height = ss.y;
		this->m_isFullscreen = true;
		this->gMonitor=glfwGetPrimaryMonitor();
	}
	if(!(this->gWindow = glfwCreateWindow(this->m_width, this->m_height, this->m_title, this->gMonitor, NULL)))
	{
		std::cout << "could not create GLFWwindow" << "\n";
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(this->gWindow);
	
	//input callbacks
	
	glfwSetKeyCallback(this->gWindow, input::key_callback);
	
	glfwSetMouseButtonCallback(this->gWindow,input::mouse_button_callback);

	glfwSetCursorPosCallback(this->gWindow, input::cursor_position_callback);

	glfwSetWindowSizeCallback(this->gWindow, window_resize_callback);

	glfwGetWindowSize(this->gWindow,&(this->m_width),&(this->m_height));


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

	glfwTerminate();
	exit(EXIT_SUCCESS);
}

bool
Window::isOpen()
{
	return !glfwWindowShouldClose(this->gWindow);
}

void 
Window::update()
{
	
	glfwGetWindowSize(this->gWindow,&(this->m_width),&(this->m_height));
	
	glfwSwapBuffers(this->gWindow);
	glfwPollEvents();
}

Vector2
Window::getScreenSize()
{
	
	 const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	 return Vector2(mode->width,mode->height);	

}

bool Window::isFullscreen(){ return this->m_isFullscreen; }

void 
Window::setFullscreen(bool fs)
{

	if(gMonitor = fs?glfwGetPrimaryMonitor():nullptr)
	{
		glfwGetWindowPos(this->gWindow, &(this->x_pos), &(this->y_pos));//save old cordinates
	
		glfwGetWindowSize(this->gWindow,&(this->o_width),&(this->o_height));

		this->m_isFullscreen = true;
		const	GLFWvidmode* mode = glfwGetVideoMode(this->gMonitor);
		glfwSetWindowMonitor(this->gWindow,this->gMonitor,0, 0, mode->width, mode->height, mode->refreshRate);
	}
	else
	{
		this->m_isFullscreen = false;
		glfwSetWindowMonitor(this->gWindow,this->gMonitor,this->x_pos, this->y_pos, this->o_width,this->o_height, 0);
	}
}

int Window::getWidth(){ return this->m_width; }
int Window::getHeight(){ return this->m_height; }

void
Window::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void 
Window::setSize(int height,int width)
{
	this->m_height = height;
	this->m_width = width;
	glfwSetWindowSize(this->gWindow, this->m_height, this->m_width);
}

Vector2
Window::getSize()
{
	return Vector2(this->m_width,this->m_height);
}

void 
window_resize_callback(GLFWwindow* window, int width, int height)
{
}



}
