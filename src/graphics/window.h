#pragma once
#include <GLFW/glfw3.h>

#include <string>
namespace spasoje{
class Window
{
	GLFWwindow *gWindow;	
	GLFWmonitor *gMonitor=nullptr;
	bool m_isFullscreen;
	int m_height,m_width;
	char *m_title;

	public:
	Window(char *title,int width=1,int height=1);
	void init();
	void clear();//TODO
	void destroy();
	void setFullscreen(bool fs=true);
	void getScreenSize();//TODO: return size 
	void update();
	bool isOpen();
	bool isFullscreen();
	int getHeight();
	int getWidth();
};
}
