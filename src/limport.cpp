#include "luainc.h"
#include "math/vector.h"
#include "graphics/renderer.h"
#include "input.h"

#include <string>
#include <iostream>
#include <map>

using namespace luabridge;

namespace spasoje{



std::map<std::string,lPtr> modules = 
{	
	std::pair<std::string,lPtr>("spasoje",&lSpasoje),
	std::pair<std::string,lPtr>("spasoje.graphics",&lGraphics),
	std::pair<std::string,lPtr>("Vector2",&lVector2),
	std::pair<std::string,lPtr>("Vector3",&lVector3)

};




int lSpasoje(lua_State *L)
{
	lVector2(L);
	lVector3(L);


	return 0;
}


int lGraphics(lua_State *L)
{

	getGlobalNamespace(L).
		addFunction("render",renderer::drawSprite)
		.addFunction("genSprite",renderer::genSprite);

	getGlobalNamespace(L).
		beginClass<Texture2D>("Texture2D")
		.addConstructor<void(*) (const char*)>()
		.endClass();

	getGlobalNamespace(L).
		beginClass<Shader>("Shader")
		.addConstructor<void(*) (const char*,const char*)>()
		.endClass();


	return 0;

}

int lVector3(lua_State *L)
{
	getGlobalNamespace(L).
		beginClass<Vector3>("Vector3")
		.addConstructor<void(*) (float,float,float)>()
		.addProperty("x",&Vector3::x)
		.addProperty("y",&Vector3::y)
		.addFunction("add",&Vector3::add)
		.addFunction("subtract",&Vector3::subtract)
		.addFunction("multiply",&Vector3::multiply)
		.addFunction("divide",&Vector3::divide)
		.addFunction("__add",&Vector3::add)
		.addFunction("__sub",&Vector3::subtract)
		.addFunction("__mul",&Vector3::multiply)
		.addFunction("__div",&Vector3::divide)
		.addFunction("__uq",&Vector3::compare)
		.endClass();

	return 0;
}
int lVector2(lua_State *L)
{
	
	getGlobalNamespace(L).
		beginClass<Vector2>("Vector2")
		.addConstructor<void(*) (float,float)>()
		.addProperty("x",&Vector2::x)
		.addProperty("y",&Vector2::y)
		.addFunction("add",&Vector2::add)
		.addFunction("subtract",&Vector2::subtract)
		.addFunction("multiply",&Vector2::multiply)
		.addFunction("divide",&Vector2::divide)
		.addFunction("__add",&Vector2::add)
		.addFunction("__sub",&Vector2::subtract)
		.addFunction("__mul",&Vector2::multiply)
		.addFunction("__div",&Vector2::divide)
		.addFunction("__uq",&Vector2::compare)
		.endClass();


	return 0;

}

int l_import(lua_State *L)
{
	std::string name = lua_tostring(L,1);
	if(modules.count(name) == 0)
	{
		std::cout << "module not found: " << name << "\n";
		std::cout << modules.size();
		return 0 ;
	}
	modules[name](L);

	return 0;
}


}
