#pragma once
#ifndef __LUA_INC_H__
#define __LUA_INC_H__

extern "C"
{
	   #include "lualib/src/lua.h"
	   #include "lualib/src/lauxlib.h"
	   #include "lualib/src/lualib.h"
}
#include "math/vector.h"
#include "lualib/luabridge/LuaBridge.h"
#include <map>



using namespace luabridge;
namespace spasoje
{

	class l_class
	{
	};
	struct l_struct
	{
	};


	typedef int (*lPtr)(lua_State *L);
	extern std::map<std::string,lPtr> modules;

	int lVector2(lua_State *L);
	int lVector3(lua_State *L);
	int lSpasoje(lua_State *L);
	int lGraphics(lua_State *L);
	
	int l_import(lua_State *L);




inline void
l_copy_userdata(lua_State *L,LuaRef ref,LuaRef *res,std::string key)
{
	
	if(ref.isInstance<Vector3>())
		(*res)[key]=ref.cast<Vector3>();		
	if(ref.isInstance<Vector2>())
		(*res)[key]=ref.cast<Vector2>();	
}



//copies LuaRef from one state to another
inline LuaRef
l_copy(lua_State *L,LuaRef ref)
{



	LuaRef res=newTable(L);
	for(luabridge::Iterator iterator(ref); !iterator.isNil(); ++iterator)
	{
		switch(iterator.value().type())
		{
			case LUA_TNIL:
		       		break;

			case LUA_TNUMBER:
				res[iterator.key().cast<std::string>()]=
					iterator.value().cast<lua_Number>();
				break;	

			case LUA_TSTRING:
				res[iterator.key().cast<std::string>()]=
					iterator.value().cast<std::string>();
				break;	

			case LUA_TTABLE:
				res[iterator.key().cast<std::string>()]
					= l_copy(L,iterator.value());
				break;	
			case LUA_TUSERDATA:
					l_copy_userdata(L,iterator.value(),&res,iterator.key().cast<std::string>());
				break;
		}	
	}
		
	
	return res;
}
	



}





#endif  //__LUA_INC_H__
