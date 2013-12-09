#include "xmltodatabase.h"

QString database = "game.db";

int main(int argc, char *argv[])
{
    if( !connect(database) )
    {
        qDebug() << "Quitting, unable to connect to database";
        return 1;
    }
    QSqlRecord rec;
    qDebug() << QString::number(("Bubble"));

}
