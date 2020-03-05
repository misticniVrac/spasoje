#include "../utils/stb_image.h"
#include "texture2d.h"

#include <iostream>


#include <GL/glew.h>


namespace spasoje{



Texture2D::Texture2D(const char *path)
{

	unsigned char *data = stbi_load(path, &(this->m_width), &(this->m_height), &(this->m_channels), 0);
	

	if(!data)
	{
		std::cout << "failed to load texture " << path << "\n";
		return;
	}
	
	glGenTextures(1,&(this->ID));
	
	glBindTexture(GL_TEXTURE_2D, this->ID); 

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->m_width, this->m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);


	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	stbi_image_free(data);


}

int
Texture2D::getID()
{
	return this->ID;
}

}

