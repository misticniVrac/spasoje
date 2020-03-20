#pragma once

#ifndef SCENE_H 
#define SCENE_H 

#include "luainc.h"
#include "entity.h"
#include "component.h"
namespace spasoje
{

class Entity;
class Component;

class Scene
{

private:
	std::vector<Entity*> entities;
	std::string name;
public:
	Scene(std::string name);
	void addEntity(Entity *entity);

	Entity *getEntity(std::string name);

	Entity *l_find(lua_State *L);

	inline std::string getName(){return this->name;}

};

}
#endif
