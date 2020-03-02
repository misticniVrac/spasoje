#pragma once
#include <GLFW/glfw3.h>
#include "../math/vector.h"

namespace spasoje{
class Window
{
	GLFWwindow *gWindow;	
	GLFWmonitor *gMonitor=nullptr;
	bool m_isFullscreen;
	int m_height,m_width;
	char *m_title;
	int x_pos=0,y_pos=0;
	int o_height,o_width;
	public:
	Window(char *title,int width=1,int height=1);
	void init();
	void clear();
	void destroy();
	void setFullscreen(bool fs=true);
	Vector2 getScreenSize();
	Vector2 getSize();
	void update();
	void setSize(int height,int width);
	void setViewortSize(int height,int width);//TODO
	bool isOpen();
	bool isFullscreen();
	int getHeight();
	int getWidth();
	

};

	void window_resize_callback(GLFWwindow* window, int width, int height);
}
