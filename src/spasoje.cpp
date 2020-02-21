
#include <GL/glew.h>
#include <iostream>

#include "graphics/window.h"
#include "input.h"
#include "math/vector.h"

using namespace spasoje;
using namespace std;

int main()
{
	char name[] = "spasoje";
	Window testWindow(name,800,600);
	testWindow.init();
	testWindow.setSize(1000,1000);

	Vector2 pos1(3.0f,2.0f);
	Vector2 pos2(1.0f,1.0f);
	Vector2 pos3;
	pos1+=pos2;
	cout << pos1 << "\n" << pos2 << "\n" << pos3 << "\n";

	while(testWindow.isOpen())
	{
		cout << input::getMousePosition() << "\n";
		testWindow.update();		
		if(input::keyPressed(KEY_Q))
		{
			testWindow.destroy();

	
		}
	}

	
	

}



