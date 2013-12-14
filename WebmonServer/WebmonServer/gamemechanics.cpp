#include "gamemechanics.h"

bool generatePartyPkmn(QMap<QString, pokemonStruct> &curParty)
{
    srand(time(NULL));
    if( curParty.size() < partyLimit )
    {
        int level = 2; // starting out so...
        int id = genSpecial(); // check whether to get special pokemon
        if( id == -1 )// no special pokemon generated
        {
            int possible = numberOfPokemon() - numOfSpecials; // number of pokemon to choose from
            bool done = false;
            while( !done )
            {
                id = rand() % possible + 1; // generate a random pokemon id
                // following logic makes sure that same pokemon
                // isn't added and a present pokemon's evolution isn't added
                bool ok = true;
                for( int i = 0; i < curParty.size(); i++ )
                {
                    bool success = getPokemonName(QString::number(id)) != curParty.keys()[i];
                    QList<QString> evolChainthis = getEvolChain(getPokemonName(QString::number(id)));
                    QList<QString> evolChainother = getEvolChain(curParty.keys()[i]);
                    bool equal = evolChainother == evolChainthis;
                    success = success && !equal;
                    if( !success  )
                    {
                        done = false;
                        ok = false;
                    }
                }
                if(ok) done = true;
            }
        }
        pokemonStruct gen = genPkmn(id, level);
        curParty.insert(gen.name, gen);
        return true;
    }
    else
    {
        return false;
    }
}

pokemonStruct genRandPkmn(int aroundLevel)
{
    pokemonStruct generated;
    srand(time(NULL));
    int id = genSpecial(); // check whether to spawn special pokemon
    int lev = rand() % 3 + (aroundLevel - ((aroundLevel == maxLevel) ? 2 : (aroundLevel == 1) ? 0 : 1)); // produce aroundLevel +- 1
    if( id == -1 )// no special pokemon generated
    {
        int possible = numberOfPokemon() - numOfSpecials; // number of pokemon to choose from
        id = rand() % possible + 1; // generate a random pokemon id
    }
    generated = genPkmn(id, lev);
    return generated;

}

int genSpecial()
{
    for( int i = 0; i < numOfSpecials; i++ )
    {
        int special = rand() % 100 + 1; // 1/100 chance of generating the special pokemon
        if( special == 100 )
        {
            return specialPokemons[i];
        }
    }
    return -1;
}

pokemonStruct genPkmn(int id, int level)
{
    pokemonStruct generated;
    QString name = getPokemonName(QString::number(id));
    generated.name = name;
    generated.PID = id;
    generated.attEV = 0;
    generated.defEV = 0;
    generated.HPEV = 0;
    generated.speedEV = 0;
    generated.CPID = 0;
    generated.EXP = getEXP(level);
    generated.level = level;
    QString type = getPokemonType(name);

    int numberOfMoves = moveLimit;
    QList<QString> possibleMoves = MovesOfType(type);
    QList<int> moves;

    if( numberOfMoves > possibleMoves.size() && type != "Undefined" ) numberOfMoves = possibleMoves.size() - 1;

    if( type.compare("Undefined", Qt::CaseInsensitive) != 0 )
    {
        for( int i = 0; i < numberOfMoves; i++ )
        {
            int move = rand() % possibleMoves.size();
            while( true )
            {
                if(moves.contains(move))
                {
                    move = rand() % possibleMoves.size();
                }
                else
                {
                    moves.append(move);
                    break;
                }
            }
            moveStruct moveOne;
            moveOne.name = possibleMoves[move];
            moveOne.accuracy = getAccuracy(moveOne.name);
            moveOne.damage = getDamage(moveOne.name);
            moveOne.pp = getPP(moveOne.name);
            moveOne.type = getMoveType(moveOne.name);
            generated.moves.append(moveOne);
        }
    }
    else // special pokemon
    {
        int move = rand() % possibleMoves.size(); // choose a random move from the undefined type
        moves.append(move);
        moveStruct moveOne;
        moveOne.name = possibleMoves[move];
        moveOne.accuracy = getAccuracy(moveOne.name);
        moveOne.damage = getDamage(moveOne.name);
        moveOne.pp = getPP(moveOne.name);
        moveOne.type = getMoveType(moveOne.name);
        generated.moves.append(moveOne);
        numberOfMoves--;
        QList<QString> types = getAllTypes();
        for( int i = 0; i < numberOfMoves; i++ )
        {
            int type = rand() % types.size();
            possibleMoves = MovesOfType(types[type]);
            move = rand() % possibleMoves.size();
            while( true )
            {
                if(moves.contains(move) && moves.size() != 1)
                {
                    move = rand() % possibleMoves.size();
                }
                else
                {
                    break;
                }
            }
            moveStruct moveOne;
            moveOne.name = possibleMoves[move];
            moveOne.accuracy = getAccuracy(moveOne.name);
            moveOne.damage = getDamage(moveOne.name);
            moveOne.pp = getPP(moveOne.name);
            moveOne.type = getMoveType(moveOne.name);
            generated.moves.append(moveOne);
        }
    }
    generated.attack = getStat(0, getBaseAtt(generated.name), generated.level);
    generated.defense = getStat(0, getBaseDef(generated.name), generated.level);
    generated.speed = getStat(0, getBaseSpeed(generated.name), generated.level);
    generated.HP = getHP(0, getBaseHP(generated.name), generated.level);
    return generated;
}

moveResult playMove(pokemonStruct &pkmn1, moveStruct &pkmn1move, pokemonStruct &pkmn2)
{
    srand(time(NULL));
    moveResult result;
    result.damageOnEnemy = 0;
    result.damageOnMe = 0;
    result.enemyAlive = true;
    result.meAlive = true;
    result.iWentFirst = pkmn1.speed >= pkmn2.speed;
    moveStruct pkmn2move;
    int move = rand() % pkmn2.moves.size();
    pkmn2move = pkmn2.moves[move];

    int probOfHit = pkmn1move.accuracy;
    int r = rand() % 100 + 1;
    if( r < probOfHit ) // pkmn1's move lands
    {
        result.damageOnEnemy = damage(pkmn1move, pkmn1, pkmn2);
        pkmn1move.pp--;
    }
    probOfHit = pkmn2move.accuracy;
    r = rand() % 100 + 1;
    if( r < probOfHit ) // pkmn1's move lands
    {
        result.damageOnMe = damage(pkmn2move, pkmn2, pkmn1);
        pkmn2move.pp--;
    }

    // have pkmn1's played move and pkmn2's played and which pkmn will attack first
    if( result.iWentFirst )
    { // pkmn1 goes first
        pkmn2.HP -= result.damageOnEnemy;
        pkmn2.moves.replace(move, pkmn2move);
        if( pkmn2.HP <= 0 )
        {
            result.enemyAlive = false;
            result.meAlive = true;
            pkmn2.HP = 0;
        }
        pkmn1.HP -= result.damageOnMe;
        if( pkmn1.HP <= 0 )
        {
            result.enemyAlive = true;
            result.meAlive = false;
            pkmn1.HP = 0;
        }
    }
    else
    { // pkmn2 goes first
        pkmn1.HP -= result.damageOnMe;
        pkmn2.moves.replace(move, pkmn2move);
        if( pkmn1.HP <= 0 )
        {
            result.enemyAlive = true;
            result.meAlive = false;
            pkmn1.HP = 0;
        }
        pkmn2.HP -= result.damageOnEnemy;
        if( pkmn2.HP <= 0 )
        {
            result.enemyAlive = false;
            result.meAlive = true;
            pkmn2.HP = 0;
        }
    }
    result.moveIUsed = pkmn1move.name;
    result.moveUsedOnMe = pkmn2move.name;
    return result;
}

int growPokemon(pokemonStruct &pkmnVictor, pokemonStruct &pkmnLooser)
{
    QString pkmnLost = pkmnLooser.name;
    pkmnVictor.EXP += (((double)getEXPYield(pkmnLost) * (double)(pkmnLooser.level * (100.0/(double)maxLevel)))/12.0) * easy;
    int expLeft = levelUp(pkmnVictor);
    evolve(pkmnVictor);
    if( pkmnVictor.attEV + pkmnVictor.defEV + pkmnVictor.speedEV + pkmnVictor.HPEV <= 100 )
    {
        pkmnVictor.attEV += getAttYield(pkmnLost);
        pkmnVictor.defEV += getDefYield(pkmnLost);
        pkmnVictor.speedEV += getSpeedYield(pkmnLost);
        pkmnVictor.HPEV += getHPYield(pkmnLost);
        pkmnVictor.attack = getStat(pkmnVictor.attEV, getBaseAtt(pkmnVictor.name), pkmnVictor.level);
        pkmnVictor.defense = getStat(pkmnVictor.defEV, getBaseDef(pkmnVictor.name), pkmnVictor.level);
        pkmnVictor.speed = getStat(pkmnVictor.speedEV, getBaseSpeed(pkmnVictor.name), pkmnVictor.level);
        pkmnVictor.HP = getHP(pkmnVictor.HPEV, getBaseHP(pkmnVictor.name), pkmnVictor.level);
    }
    return expLeft;
}
int levelUp(pokemonStruct &pkmn)
{
    if( pkmn.level < maxLevel )
    {
        int ExpCapforthisLevel = getEXP(pkmn.level + 1);
        while( pkmn.EXP >= ExpCapforthisLevel )
        {
            // level up
            pkmn.level++;
            ExpCapforthisLevel =  getEXP(pkmn.level + 1); // update expCap
        }
        return ExpCapforthisLevel - pkmn.EXP; // return how much exp left to go to next level
    }
    else
    {
        return 0;
    }
}
int evolve(pokemonStruct &pkmn)
{
    QString pokemon = pkmn.name;
    int levelToEvolve = getEvolveLevel(pokemon);
    if( levelToEvolve > 0 )
    {
        if( levelToEvolve <= pkmn.level )
        {
            QString evolveTo = getEvolveTo(pokemon); // pid it will evolve to
            pkmn.name = getPokemonName(evolveTo);
            pkmn.attack = getBaseAtt(pkmn.name);
            pkmn.defense = getBaseDef(pkmn.name);
            pkmn.speed = getBaseSpeed(pkmn.name);
            pkmn.HP = getBaseHP(pkmn.name);
            pkmn.PID = evolveTo.toInt();
            levelToEvolve = getEvolveLevel(pkmn.name);
            return (levelToEvolve > 0) ? levelToEvolve - pkmn.level : -1;
        }
        else
        {
            return levelToEvolve - pkmn.level;
        }
    }
    else
    {
        return -1; // already filly evolved
    }
}
void restorePkmn(pokemonStruct &pkmn)
{
    pkmn.HP = getHP(pkmn.HPEV, getBaseHP(pkmn.name), pkmn.level);
    for(int i = 0; i < pkmn.moves.size(); i++)
    {
        moveStruct m = pkmn.moves[i];
        m.pp = getPP(m.name);
        pkmn.moves.replace(i, m);
    }
}
int damage(moveStruct moveUsed, pokemonStruct user, pokemonStruct victim)
{
    double damage = ((double)((2* (user.level*(100/maxLevel))) + 10)) / 250.0;
    damage *= ((double)user.attack/(double)victim.defense) * (double)moveUsed.damage;
    damage += 2.0;
    damage *= accessDamageModifer(moveUsed.type,getPokemonType(victim.name));
    return qFloor(damage);
}
int getStat(int EV, int baseStat, int level)
{
    int stat = 2 * baseStat;
    stat += (EV/4);
    stat *= level * (100/maxLevel); // theorectical maxLevel is 100, divide by maxLevel to scale
    stat /= 100;
    stat += 5;
    return stat;
}
int getHP(int EV, int baseHP, int level)
{
    int stat = 2 * baseHP;
    stat += (EV/4) + 100;
    stat *= level * (100/maxLevel); // theorectical maxLevel is 100, divide by maxLevel to scale
    stat /= 100;
    stat += 10;
    return stat;
}
int getLevel(int EXP)
{
    return qPow(EXP, 1/3) / (100/maxLevel);
}
int getEXP(int level)
{
    return qPow(level * (100/maxLevel), 3);
}
void save(QString trainer, QMap<QString, pokemonStruct> dataToSave)
{
    if( trainerExists(trainer) )
    {
        changeNumOfPokemonCaught(trainer, dataToSave.size());
        clearAllCaughtPokemon(trainer);
    }
    else
    {
        createTrainer(trainer);
        changeNumOfPokemonCaught(trainer, dataToSave.size());
    }

    foreach(pokemonStruct member, dataToSave)
    {
        addCaughtPokemon(trainer, member.HP, member.PID, member.attEV, member.defEV, member.speedEV, member.HPEV, member.EXP, encodeMoves(member.moves));
    }
}

QString encodeMoves(QList<moveStruct> moves)
{
    QString result = "";
    int i = 0;
    foreach(moveStruct m, moves)
    {
        i++;
        result += m.name + "." + QString::number(m.pp) + ((i == moves.size()) ? "" : "|");
    }
    return result;
}

QMap<QString, pokemonStruct> resume(QString name)
{
    return accessAllCaughtPokemon(name);
}
