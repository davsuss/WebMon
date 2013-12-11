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

    QSqlRecord recs[2];
    qDebug() << QString::number(createTrainer("Roy"));
    qDebug() << QString::number(createTrainer("Roy"));
    qDebug() << QString::number(numOfPokemonCaught("Roy"));
    qDebug() << QString::number(changeNumOfPokemonCaught("Roy", 2));
    qDebug() << QString::number(numOfPokemonCaught("Roy"));
    qDebug() << QString::number(newPokemonCaught("Roy", 0, 12, 3, 4, 2, 111, "Bubble:12"));
    qDebug() << QString::number(newPokemonCaught("Roy", 1, 12, 3, 4, 2, 111, "Flamethrower:20, Fire Blast:2"));
    qDebug() << QString::number(numOfPokemonCaught("Roy"));
    qDebug() << QString::number(accessCaughtPokemon("Roy", recs));
    qDebug() << recs[0].field("Moves").value().toString();
    qDebug() << recs[1].field("Moves").value().toString();
    qDebug() << QString::number(deleteTrainer("Roy"));
    qDebug() << QString::number(trainerExists("Roy"));
}
