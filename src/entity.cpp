#include "entity.h"
#include "scene.h"
#include "component.h"
#include "luainc.h"
#include "debug.h"

#include <iostream>
#include <string>
#include <algorithm> 


using namespace std;
using namespace luabridge;


namespace spasoje
{

Entity::Entity(Scene *scene,string name)
{
	this->L = luaL_newstate();

	luaL_openlibs(this->L);

	getGlobalNamespace(this->L).
		addFunction("print",l_print);

	getGlobalNamespace(this->L).
		addFunction("import",l_import);

	getGlobalNamespace(this->L).
		beginClass<Entity>("Entity").
		addFunction("getName",&Entity::getName).
		addFunction("get",&Entity::l_get).
		endClass();

	//this will later be overwritten by Scene singleton
	getGlobalNamespace(this->L).
		beginClass<Scene>("Scene").
		addFunction("find",&Scene::l_find).
		addFunction("getName",&Scene::getName).
		endClass();


	this->scene = scene;
	this->name = name;

	this->scene->addEntity(this);

}
Entity::~Entity()
{
	if(this->L)
		lua_close(this->L);
}

LuaRef
Entity::l_get(lua_State *L)
{
	string name = lua_tostring(L,2);

	

	LuaRef ref = getGlobal(this->L,name.c_str());


	if(ref==Nil())
		cout << "component not found: " << name << "\n";

	

	return l_copy(L,ref);
}

Component*
Entity::getComponent(string name)
{
	Component *curr;
	for(int i=0;i<this->components.size();i++)
	{
		curr = this->components[i];
		if(curr->getName() == name)
			return curr;
	}


	return nullptr;
}

bool
Entity::hasComponent(string name)
{
	return getComponent(name) != nullptr;
}

void 
Entity::addComponent(Component *comp)
{
	if(hasComponent(comp->getName()))
	{
		cout << "entity " << this->name <<  "already has component " << comp->getName();
		return;
	}
	this->components.push_back(comp);

}

}
