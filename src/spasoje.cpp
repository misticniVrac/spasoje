#include <GL/glew.h>
#include <iostream>

#include "graphics/window.h"
#include "input.h"
#include "math/vector.h"
#include "graphics/shader.h"

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
	Vector3 rot1(1.0f,2.0f,3.0f);
	Vector3 rot2(1.1f,2.2f,3.3f);
	Vector3 rot3 = rot2-rot1;
	cout << (rot1==rot2) << "\n";
	rot3*=Vector3(3);
	cout << rot3 << "\n";
	pos3 = pos1+pos2;
	cout << pos1 << "\n" << pos2 << "\n" << pos3 << "\n";

	Shader testShader("res/shaders/shader.v","res/shaders/shader.f");
	
	testShader.start();
	
	while(testWindow.isOpen())
	{

		testWindow.clear();
		testWindow.update();		
		if(input::keyPressed(KEY_Q))
		{
			testWindow.destroy();

	
		}
	}

	
	

}
