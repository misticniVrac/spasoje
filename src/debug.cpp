#include "luainc.h"
#include "debug.h"

#include <iostream>



namespace spasoje{

int l_print(lua_State* L)
{
	int args = lua_gettop(L);
	for (int i=1; i <= args; i++) 
	{
		if(lua_isstring(L, i)) 
		{
			std::cout << lua_tostring(L,i);		            
		}
		else
		{
		}
	}
	std::cout << "\n";
	return 0;
}

}
