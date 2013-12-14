#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

#include "constants.h"
#include "databaseConversation.h"
#include <cstdlib>
#include <time.h>
#include <cmath>

// pokemon generations
/***
 * generate a random pokemon and add it to curParty
 * returns true if pokemon could be added (# of pokemon limited)
 ***/
bool generatePartyPkmn(QMap<QString, pokemonStruct> &curParty);

/***
 * generate random pokemon at +-1 aroundLevel
 ***/
pokemonStruct genRandPkmn(int aroundLevel);

/***
 * generate a random pokemon at a certain level with rand stats
 ***/
pokemonStruct genPkmn(int id, int level);

/***
 * returns id of special pokemon if a-go to generate special pokemon or return -1
 ***/
int genSpecial();

// pokemon training
// move calculations
moveResult playMove(pokemonStruct &pkmn1, moveStruct &move1, pokemonStruct &pkmn2);
// pokemon's growth
int growPokemon(pokemonStruct &pkmnVictor, pokemonStruct &pkmnLooser);
// levels up a pokemon if necessary
int levelUp(pokemonStruct &pkmn);
// evolves up a pokemon if necessary
int evolve(pokemonStruct &pkmn);
// Calculations
int getStat(int EV, int baseStat, int level);
int getHP(int EV, int baseHP, int level);
int getLevel(int EXP);
int getEXP(int level);
int damage(moveStruct moveUsed, pokemonStruct user, pokemonStruct victim);
void restorePkmn(pokemonStruct &pkmn);

// saving and resuming
void save(QString trainer, QMap<QString, pokemonStruct> dataToSave);
QMap<QString, pokemonStruct> resume(QString name);
QString encodeMoves(QList<moveStruct> moves);

#endif // GAMEMECHANICS_H
