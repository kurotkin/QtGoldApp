#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{ }

bool DataBase::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("QSQLITE");
    db.setDatabaseName("..\\QtGoldApp\\gold.db");
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

void DataBase::closeDataBase()
{
    db.close();
}
