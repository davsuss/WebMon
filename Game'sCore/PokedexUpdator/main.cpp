#include "xmltodatabase.h"

QString DataBaseName = "game.db";

int main(int argc, char *argv[])
{
    // n for running on a new system
    if( QString::fromAscii(argv[1]).compare("n") == 0 )
    {
        qDebug() << "New System";
        connect(DataBaseName);
        createTables();
        updateTables();
        qDebug() << "Check if " + DataBaseName + " shows up in the dir with this exe!";
    }
    else if( QString::fromAscii(argv[1]).compare("o") == 0 )
    {
        qDebug() << "Already have the game huh?";
        connect(DataBaseName);
        clearTables();
        createTables();
        updateTables();
        qDebug() << "Check if " + DataBaseName + " shows up in the dir with this exe!";
    }
    else
    {
        qDebug() << "Read manual to run this program properly!";
    }
}
