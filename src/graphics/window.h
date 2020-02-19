#pragma once
#include <GLFW/glfw3.h>

#include <string>
namespace spasoje{
class Window
{
	GLFWwindow *gWindow;	
	public:
	int height,width;
	char *title;
	Window(int width,int height,char *title);
	void init();
	void clear();//TODO
	void destroy();
	void fullscreen();//TODO
	bool isOpen();
	void update();
};
}
