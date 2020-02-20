//#include <GLFW/glfw3.h>

#include <GL/glew.h>
#include <iostream>

#include "graphics/window.h"

using namespace spasoje;
using namespace std;


int main()
{
	char name[] = "spasoje";
	Window testWindow(name,800,600);
	testWindow.init();
	testWindow.setSize(1000,1000);
	while(testWindow.isOpen())
	{
		testWindow.update();		
	}
	
	testWindow.destroy();
	
	glfwTerminate();
	exit(EXIT_SUCCESS);


}



