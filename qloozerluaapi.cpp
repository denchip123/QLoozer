#include "qloozerluaapi.h"
//QLoozerLuaAPI* QLoozerLuaAPI::m_instance = 0;

#include <QMainWindow>
QLoozerLuaAPI::QLoozerLuaAPI(QObject *parent) :
    QObject(parent)
{
    lua_State* L;

    L = luaL_newstate();

    luaL_openlibs(L);



//    lua_register(L, "SendLooserInfo", EmitSendLooserInfo);



    if (luaL_loadfile(L, "qloozerluacore.lua") || lua_pcall(L, 0, 0, 0)) {
        qDebug("error: ");
        qDebug(QString(lua_tostring(L, -1)).toAscii());
    }

    lua_getglobal(L, "GetLooser");
    lua_getglobal(L, "GetLooserInfo");

    lua_pushstring(L, "GetLooserInfo"); /* function to be called */
    lua_gettable   (L, -1);
    lua_pcall (L, 0, 1, 0);
    lua_setfield(L, -1, "a");
    lua_gettable(L,-1);
    char *k;
    lua_getfield(L,-1,k);
}


//int QLoozerLuaAPI::EmitSendLooserInfo(lua_State *L)
//{
//    //int n = lua_gettop(L); // number of arguments
//    QString name = QString(lua_tostring(L, 1));
//    int raiting = lua_tonumber(L, 2);
//    int stat = lua_tonumber(L, 3);

//    getInstance()->Emmiter(name, raiting, stat);
//}

//void QLoozerLuaAPI::Emmiter(QString name, int raiting, int stat)
//{
//    emit QLoozerLuaAPI::SendLooserInfo(name, raiting, stat);
//}

void QLoozerLuaAPI::FindLooser()
{
    return;
}

//QLoozerLuaAPI* QLoozerLuaAPI::getInstance()
//{
//    if (m_instance == 0)
//        m_instance = new QLoozerLuaAPI;
//    return m_instance;
//}
