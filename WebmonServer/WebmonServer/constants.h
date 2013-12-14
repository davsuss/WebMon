#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>
#include <QList>

const int specialPokemons[] = {16};
const int numOfSpecials = 1;
const int maxLevel = 20;

const int partyLimit = 2; // variable to make sure a trainer is limited to 2 pokemon
const int moveLimit = 2; // variable to make sure a training pokemon can only have 2 moves

const QString staticdatabase = "./databases/game.db";
const QString dynamicdatabase = "./databases/saveData.db";

const int easy = 7;

// what a move looks like
struct moveStruct
{
    QString name;
    QString type;
    int damage;
    int pp;
    int accuracy;// doesn't matter in the game mechanics at this point
};
// what a partyPokemon looks like
struct pokemonStruct
{
    QString name;
    int PID;
    int CPID;
    int attack;
    int defense;
    int speed;
    int HP;
    int attEV;
    int defEV;
    int speedEV;
    int HPEV;
    int EXP;
    int level;
    QList<moveStruct> moves;
};

struct moveResult
{
    bool meAlive;
    bool enemyAlive;
    int damageOnMe;
    int damageOnEnemy;
    bool iWentFirst;
    QString moveIUsed;
    QString moveUsedOnMe;
};

enum gameState{unbuilt, idle, battle}; // for extensibility and to keep track what the trainer is doing

#endif // CONSTANTS_H
