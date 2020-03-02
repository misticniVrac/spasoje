#include "GLFW/glfw3.h"

#include "input.h"

#include "math/vector.h"
namespace spasoje{
namespace input{
	
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

	
bool getKeyPressed(int key)
{

	if(key>=MAX_KEYS_SIZE)
		return false;
	if(key>-2)
	{
		bool temp = m_keys[key];
		m_keys[key] = false;
		return temp;
	}	

	//key is mouse button (-2...-9)
	key = key * -1;
	key-=2;

	if(key>-10 && key<MAX_BUTTONS_SIZE)
	{
		bool temp = m_buttons[key];
		m_buttons[key] = false;
		return temp;
	}	


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

void 
cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	mousePosition.x = xpos;
	mousePosition.y = ypos;
}

Vector2
getMousePosition()
{
	return mousePosition;
}

}
}
