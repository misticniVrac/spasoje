#pragma once

#include "luainc.h"
#include "entity.h"

#include <string>

namespace spasoje
{

class Entity;
class Scene;
	
class Component
{
private:
	Entity *entity;
	lua_State *L;
	int l_level=0;
	std::string name;
public:
	Component(Entity *entity,const std::string lpath);

	void setEntity(Entity *entity);
	bool to_stack(const std::string name);
	std::string getName();


template<typename T>
T lua_get(const std::string& variableName) 
{
          return 0;
}

template<typename T>
T lua_getdefault() 
{
		  return 0;
}

template<typename T>
inline T get(const std::string& name) 
	{
		if(!this->L) 
		{
			      //printError(, "Script is not loaded");
			          return lua_getdefault<T>();
		}
		   
		T result;
		
		if(to_stack(name)) 
		{ // variable succesfully on top of stack
			result = lua_get<T>(name);
		} else 
		{
			result = lua_getdefault<T>();
		}
		       
		lua_pop(this->L, this->l_level + 1); // pop all existing elements from stack
		this->l_level =0;	
	       	return result;
		
	}
};




}
