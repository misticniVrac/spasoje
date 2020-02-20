
#include <GL/glew.h>
#include <iostream>

#include "graphics/window.h"
#include "input.h"
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
		if(keyPressed(KEY_Q))
		{
			testWindow.destroy();

	
		}
	}

	
	

}



