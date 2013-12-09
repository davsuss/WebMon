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
bool connect(QString name);

// dynamic database
void createTables();
int createTrainer(QString name);
/*bool accessTrainer(QString TrainerName, QSqlRecord &rec);
QString accessHelperTrainer(QString pokemonName, QString column);
QString getCaughtPokemonIDs(QString pokemonName);
int getCaughtPokemonAttEV(QString ID);
int getCaughtPokemonDefEV(QString ID);
int getCaughtPokemonSpeedEV(QString ID);
int getCaughtPokemonHPEV(QString ID);
int getCaughtPokemonEXP(QString ID);*/

// access static database objects
// pokemons from pokedex
bool accessPokemon(QString PokemonName, QSqlRecord &rec);
QString accessHelper(QString pokemonName, QString column);
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
