#pragma once


#include <GL/glew.h>
#include <map>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <string>

#include "../math/vector.h"

namespace spasoje
{

struct Character
{
	GLuint texture_ID;
	Vector2 Size,Bearing;
	long int Advance;
};

class Font
{
private:
	std::map <char,Character> characters;
public:
	Font(std::string fpath);

	inline Character getCharacter(char c){return characters[c];}

};

}
