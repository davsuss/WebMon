/*#include "gamemechanics.h"
#include "databaseConversation.h"

int main(int argc, char *argv[])
{
    if( !connect() )
    {
        qDebug() << "Quitting, unable to connect to database";
        return 1;
    }
    /************************************
    // if reset then this
    //clearTables();
    //createTables();
    QSqlRecord rec;
    *************************************/
    //clearTables();
    //createTables();
   /*QMap<QString, pokemonStruct> ans;
    while( generatePartyPkmn(ans) );
    foreach(pokemonStruct p, ans)
    {
        qDebug() << "Name: " << p.name << " Attack: " << p.attack;
        foreach( moveStruct m, p.moves )
        {
            qDebug() << "   Move: " << m.name;
        }
    }
    /*
    QSqlRecord recs[2];
    qDebug() << QString::number(createTrainer("Roy"));
    qDebug() << QString::number(createTrainer("Roy"));
    qDebug() << QString::number(numOfPokemonCaught("Roy"));
    qDebug() << QString::number(changeNumOfPokemonCaught("Roy", 2));
    qDebug() << QString::number(numOfPokemonCaught("Roy"));
    //qDebug() << QString::number(newPokemonCaught("Roy", 0, 12, 3, 4, 2, 111, "Bubble:12"));
    //qDebug() << QString::number(newPokemonCaught("Roy", 1, 12, 3, 4, 2, 111, "Flamethrower:20, Fire Blast:2"));
    qDebug() << QString::number(numOfPokemonCaught("Roy"));
    //qDebug() << QString::number(accessCaughtPokemon("Roy", recs));
    qDebug() << recs[0].field("Moves").value().toString();
    qDebug() << recs[1].field("Moves").value().toString();
    qDebug() << QString::number(deleteTrainer("Roy"));
    qDebug() << QString::number(trainerExists("Roy"));*/

/*
}*/
#include <QApplication>
#include <QtCore>

#include <stdlib.h>

#include "dialog.h"

int main(int argc, char *argv[])
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
