#ifndef ENTITY_H 
#define ENTITY_H 

#include "entity.h"
#include "luainc.h"
#include "scene.h"

namespace spasoje{

class Scene;
class Component;

class Entity
{
private:
	lua_State *L;
	std::string name="Empty Entity";
	std::vector<Component*> components;
	Scene *scene;
public:
	Entity(Scene *scene,std::string name);
	~Entity();
	Component *getComponent(std::string name);
	
	bool hasComponent(std::string name);
	
	void addComponent(Component *comp);

	inline lua_State *get_L()
	{
		return this->L;
	}

	std::string getName(){ return this->name;}
	Scene *getScene(){return this->scene;}


	luabridge::LuaRef l_get(lua_State *L);

};
}
#endif
