#ifndef XMLTODATABASE_H
#define XMLTODATABASE_H

#include <QSqlDatabase>
#include <QSqlField>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

#include <QFile>
#include <QtXmlPatterns/QXmlSchema>
#include <QtXml/QXmlStreamReader>
#include <QtXmlPatterns/QXmlSchemaValidator>

// connect to game.db
bool connect();

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
int addCaughtPokemon(QString trainer, int PID, int attackEV, int defEV, int speedEV, int HPEV, int exp, QString moves);
bool accessAllCaughtPokemon(QString trainerName, QSqlRecord *recs);

// access static database objects
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

// damage modifiers
double accessDamageModifer(QString attackType, QString victimType);

// moves
bool accessMove(QString MoveName);
QString accessHelperMove(QString MoveName, QString column);
QString getMoveType(QString MoveName);
int getDamage(QString MoveName);
int getAccuracy(QString MoveName);
int getPP(QString MoveName);

#endif // XMLTODATABASE_H
