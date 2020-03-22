/*

	TODO: setting texture parameters
*/
#pragma once

#include "../utils/stb_image.h"

namespace spasoje{

class Texture2D
{

private:
	unsigned int ID;	
	int m_width,m_height,m_channels;
public:
	Texture2D();
	Texture2D(const char *path);
	
	int getID();
	inline void setID(unsigned int ID){this->ID = ID;}
};

}
