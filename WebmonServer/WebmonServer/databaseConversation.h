#ifndef XMLTODATABASE_H
#define XMLTODATABASE_H

#include <QSqlDatabase>
#include <QSqlField>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QStringList>

#include <QFile>
#include <QtXmlPatterns/QXmlSchema>
#include <QtXml/QXmlStreamReader>
#include <QtXmlPatterns/QXmlSchemaValidator>

#include "constants.h"
#include "gamemechanics.h"

// connect to game.db
bool connectToDB();

// dynamic database
// Trainers and Caught/trained pokemon
void createTables();
void clearTables();

// trainer accessors
bool createTrainer(QString name); // trainer with 0 pokemon, name has to be unique
bool deleteTrainer(QString name);
bool trainerExists(QString name);
bool accessTrainer(QString TrainerName, QSqlRecord &rec);
QString accessHelperTrainer(QString trainerName, QString column);
int numOfPokemonCaught(QString name);
bool changeNumOfPokemonCaught(QString name, int num);

// caught pokemon accessors
// return number of pokemon caught by the particular trainer
int addCaughtPokemon(QString trainer, int HP, int PID, int attackEV, int defEV, int speedEV, int HPEV, int exp, QString moves);
QMap<QString, pokemonStruct>  accessAllCaughtPokemon(QString trainerName);
void clearAllCaughtPokemon(QString trainerName);

// access static database object
// pokemons from pokedex
bool accessPokemon(QString PokemonName, QSqlRecord &rec);
QString accessHelper(QString pokemonName, QString column);
QString getPokemonName(QString id);
QString getPokemonType(QString pokemonName);
int getBaseAtt(QString pokemonName);
int getBaseDef(QString pokemonName);
int getBaseSpeed(QString pokemonName);
int getBaseHP(QString pokemonName);
int getAttYield(QString pokemonName);
int getDefYield(QString pokemonName);
int getSpeedYield(QString pokemonName);
int getHPYield(QString pokemonName);
int getEXPYield(QString pokemonName);
int getEvolveLevel(QString pokemonName);
int getEvolveTo(QString pokemonName);
QList<QString> getEvolChain(QString pokemonName);
int numberOfPokemon();

// damage modifiers
double accessDamageModifer(QString attackType, QString victimType);

// moves
bool accessMove(QString MoveName);
QString accessHelperMove(QString MoveName, QString column);
QString getMoveType(QString MoveName);
int getDamage(QString MoveName);
int getAccuracy(QString MoveName);
int getPP(QString MoveName);
QList<QString> MovesOfType(QString Type);

// types
QList<QString> getAllTypes();

#endif // XMLTODATABASE_H
