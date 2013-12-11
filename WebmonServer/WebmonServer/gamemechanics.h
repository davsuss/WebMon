#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

// Calculations
int damage(QString trainer, int CPID, QString victimPokemon);
int getRemainingExp(QString pokemon, int curLevel);
bool willEvolve(QString pokemon, int curLevel);
int evolve(QString trainer, int CPID);

#endif // GAMEMECHANICS_H
