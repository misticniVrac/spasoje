#include "font.h"
#include "../math/vector.h"


#include <GL/glew.h>
#include <map>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <string>
#include <iostream>

namespace spasoje
{
Font::Font(std::string fpath)
{

	//init freetype
	
	FT_Library ft;
	if (FT_Init_FreeType(&ft))
		    std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

	FT_Face face;
	if (FT_New_Face(ft, fpath.c_str(), 0, &face))
		    std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;  

	//font size
	FT_Set_Pixel_Sizes(face, 0, 48);  
	

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Disable byte-alignment restriction
	  


	for (GLubyte c = 0; c < 128; c++)
	{
	    // Load character glyph 
	    if (FT_Load_Char(face, c, FT_LOAD_RENDER))
	    {
	        std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
	        continue;
	    }
	    // Generate texture
	    GLuint texture;
	    glGenTextures(1, &texture);
	    glBindTexture(GL_TEXTURE_2D, texture);
	    glTexImage2D(
	        GL_TEXTURE_2D,
	        0,
	        GL_RED,
	        face->glyph->bitmap.width,
	        face->glyph->bitmap.rows,
	        0,
	        GL_RED,
	        GL_UNSIGNED_BYTE,
	        face->glyph->bitmap.buffer
	    );
	    // Set texture options
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	    // Now store character for later use
	    Character character = {
	        texture, 
	        Vector2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
	        Vector2(face->glyph->bitmap_left, face->glyph->bitmap_top),
	        face->glyph->advance.x
	    };
	    
	    this->characters.insert(std::pair<char, Character>(c, character));
	 
	 
	}

	FT_Done_Face(face);
	FT_Done_FreeType(ft);

}
}
