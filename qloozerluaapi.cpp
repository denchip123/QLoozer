#include "qloozerluaapi.h"

QLoozerLuaAPI::QLoozerLuaAPI()
{
    lua_State *L;

    L = luaL_newstate();

    luaL_openlibs(L);

    luaL_dofile(L,"qloozerluacore.lua");
}
