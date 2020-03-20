#include "entity.h"
#include "luainc.h"
#include "debug.h"

#include <string>

using namespace std;
using namespace luabridge;

namespace spasoje
{

Component::Component(Entity *entity,const string lpath)
{

	this->entity = entity;
	this->L = this->entity->get_L(); 
	if(luaL_dofile(this->L,lpath.c_str()) != LUA_OK)
	{
		cout << "could not load lua script " << lpath << "\n"
			<<  lua_tostring(this->L,-1) << "\n";
		this->L = 0;
	}
	


	//setting Scene singleton

	push(this->L,this->entity->getScene());
	lua_setglobal(this->L,"Scene");

	string name = "";
	for(int i=lpath.size();i>0;i--)
	{
		if(lpath[i]=='/' || lpath[i]=='\\')
		{	
			break;

		}

		name+=lpath[i];

	}
	this->name = "";
	for(int j=name.size()-1;j>0;j--)
	{
		if(name[j]=='.')
			break;
		this->name+=name[j];
	}

	this->entity->addComponent(this);

}

void
Component::setEntity(Entity *entity)
{
	this->entity = entity;
}
bool
Component::to_stack(const string name)
{

	string var="";
	for(int i=0;i<name.size();i++)
	{
		if(name[i]=='.')
		{
			if(this->l_level == 0)
			{
				lua_getglobal(this->L, var.c_str());
			;}
			else
         			lua_getfield(this->L,-1,var.c_str());

			if(lua_isnil(this->L,-1))
			{
				cout << "variable not defined:" << var << "\n";
				return false;
			}
			else
			{
				this->l_level++;
				var = "";
			}

		}
		else
		{
			var+=name[i];
		}
	}
	
		if(this->l_level == 0)
			lua_getglobal(this->L, var.c_str());
		else
         		lua_getfield(this->L,-1,var.c_str());

		if(lua_isnil(this->L,-1))
		{
			cout << "variable not defined:" << var << "\n";
			return false;
		}

	
	return true;

}
	
template<>
std::string Component::lua_getdefault() 
{
		  return "null";
}
template <>
bool Component::lua_get(const std::string& name) {
	    return (bool)lua_toboolean(L, -1);
}
 
template <>
float Component::lua_get(const std::string& name) {
	    if(!lua_isnumber(L, -1)) {
		         // printError(variableName, "Not a number");
			      }
	        return (float)lua_tonumber(L, -1);
}
 
template <>
int Component::lua_get(const std::string& name) {
	    if(!lua_isnumber(L, -1)) {
		          //printError(variableName, "Not a number");
			      }
	        return (int)lua_tonumber(L, -1);
}
 
template <>
std::string Component::lua_get(const std::string& name) {
	    std::string s = "null";
	        if(lua_isstring(L, -1)) {
			      s = std::string(lua_tostring(L, -1));
			          } else {
					        //printError(variableName, "Not a string");
						    }
		    return s;

}

string
Component::getName()
{
	return this->name;
}

}
