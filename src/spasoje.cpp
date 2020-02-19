//#include <GLFW/glfw3.h>

#include <GL/glew.h>
#include <iostream>

#include "graphics/window.h"

using namespace spasoje;
using namespace std;


int main()
{
	char name[] = "spasoje";
	Window testWindow(800,600,name);
	testWindow.init();
	
	while(testWindow.isOpen())
	{
		testWindow.update();		
	}
	
	testWindow.destroy();
	
	glfwTerminate();
	exit(EXIT_SUCCESS);


}



