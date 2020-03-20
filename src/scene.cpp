#include "scene.h"
#include "luainc.h"
#include "debug.h"

using namespace std;
using namespace luabridge;

namespace spasoje
{
Scene::Scene(string name)
{
	this->name = name;

}

Entity*
Scene::l_find(lua_State *L)
{


	string name = lua_tostring(L,2);
	
	Entity *ent;
	ent = getEntity(name);
	if(ent != nullptr)
	{
	}
	else
	{
		cout << "Entity not found " << name << "\n";
	}	

	return ent;



}


Entity*
Scene::getEntity(string name)
{
	Entity *curr;
	for(int i=0;i<this->entities.size();i++)
	{
		curr = this->entities[i];
		if(curr->getName() == name)
			return curr;
	}


	return nullptr;
}

void
Scene::addEntity(Entity *entity)
{
	this->entities.push_back(entity);
}


}
