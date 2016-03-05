#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "lua.hpp"
//#include "oolua.h"
//using namespace OOLUA

int getRandom()
{

}

void luaPrint(char *msg)
{
    std::cout << msg;
}
int main(int argc, char *argv[])
{
    srand(time(NULL));

    //create lua state
    lua_State *L = luaL_newstate();

    //load file
    if(luaL_loadfile(L,"luatest.lua")) std::cout << "Error loading lua file.\n";

    lua_


    lua_pcall(L, 0,0,0);

    lua_close(L);

    return 0;
}
