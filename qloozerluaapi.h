#ifndef QLOOZERLUAAPI_H
#define QLOOZERLUAAPI_H

#include "lua/lua.hpp"
#include <QString>
#include <QObject>


class QLoozerLuaAPI : public QObject
{
    Q_OBJECT

signals:
    void SendLooserInfo(QString name, int raiting, int stat);
    void ClearLoosersTable();

public:
    explicit QLoozerLuaAPI(QObject *parent = 0);
    //QLoozerLuaAPI();
    static QLoozerLuaAPI* getInstance();

public slots:
    void FindLooser();/*
    void Emmiter(QString name, int raiting, int stat);*/

private:

    /*
    static QLoozerLuaAPI* m_instance;
    static int EmitSendLooserInfo(lua_State *L);*/

};

#endif // QLOOZERLUAAPI_H
