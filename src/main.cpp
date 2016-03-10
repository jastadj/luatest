#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "lua.hpp"

static void stackDump (lua_State *L) {
  int i;
  int top = lua_gettop(L);
  for (i = 1; i <= top; i++) {  /* repeat for each level */
    int t = lua_type(L, i);
    switch (t) {

      case LUA_TSTRING:  /* strings */
        printf("`%s'", lua_tostring(L, i));
        break;

      case LUA_TBOOLEAN:  /* booleans */
        printf(lua_toboolean(L, i) ? "true" : "false");
        break;

      case LUA_TNUMBER:  /* numbers */
        printf("%g", lua_tonumber(L, i));
        break;

      default:  /* other values */
        printf("%s", lua_typename(L, t));
        break;

    }
    printf("  ");  /* put a separator */
  }
  printf("\n");  /* end the listing */
}


int main(int argc, char *argv[])
{
    srand(time(NULL));

    //create lua state
    lua_State *L = luaL_newstate();

    //load file
    if(luaL_loadfile(L,"luatest.lua")) std::cout << "Error loading lua file.\n";

    if(lua_pcall(L, 0,0,0))
    {
        std::cout << "Error in luatest.lua!\n";
    }

    int a = 0;
    int b = 0;
    lua_getglobal(L, "a");
    lua_getglobal(L, "b");

    a = int(lua_tonumber(L, -2));
    b = int(lua_tonumber(L, -1));


    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;

    lua_close(L);

    return 0;
}
