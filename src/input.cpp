#include "GLFW/glfw3.h"

#include "input.h"

namespace spasoje{

	
bool keyPressed(int key)
{


	if(key>=MAX_KEYS_SIZE)
		return false;
	if(key>-2)	
		return m_keys[key];

	//key is mouse button (-2...-9)
	key = key * -1;
	key-=2;

	if(key>-10 && key<MAX_BUTTONS_SIZE)
		return m_buttons[key];

	return false;

}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	 {
		 m_keys[key]=true;
	 }
	else if(action == GLFW_RELEASE)
		m_keys[key]=false;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (action == GLFW_PRESS)
	 {
		 m_buttons[button] = true;
	 }
	else if(action == GLFW_RELEASE)
		m_buttons[button] = false;

}


}
