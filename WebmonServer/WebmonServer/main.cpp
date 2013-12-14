#include <QApplication>
#include <QtCore>

#include <stdlib.h>

#include "dialog.h"

int main(int argc, char *argv[])
{
    qDebug() << argc;
    if( argc == 2 && QString::fromAscii(argv[1]).compare("r") == 0 )
    {
        connectToDB();
        clearTables();
        createTables();
        qDebug() << "run just executable, tables have been reset, all save data has been deleted!";
    }
    else
    {
        QApplication app(argc, argv);
        //connectToDB(); clearTables(); createTables();
        Dialog dialog;
    #ifdef Q_OS_SYMBIAN
        dialog.showMaximized();
    #else
        dialog.show();
    #endif
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        return app.exec();
    }
}
