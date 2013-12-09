#include "xmltodatabase.h"

bool connect(QString pathToDatabaseFile)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // TELLS QT LIBS ABOUT DATABASE
    db.setDatabaseName(pathToDatabaseFile);// WHERE TO STORE THE FILES
    if (!db.open()) { // CHECK IF IT OPEN
        return false;
    }
    else
    {
        return true;
    }
}

void createTables()
{
    QSqlQuery query;
    query.exec("CREATE TABLE Trainers(trainerid integer primary key, Name varchar(20), CaughtPokemon varchar(20))");
    query.exec("CREATE TABLE CaughtPokemon(CPID INTEGER primary key, PID INTEGER, Type varchar(20), AtEV INTEGER, DefEV INTEGER, speedEV INTEGER, HPEV INTEGER, EXP INTEGER)");
}

int createTrainer(QString Name)
{
    QSqlQuery query;
    query.exec("INSERT INTO Trainers(Name, CaughtPokemon) values('" + Name + "', '')");
    query.exec("SELECT * FROM Trainers WHERE Name='" + Name + "'");
    if( query.next() )
    {
        return query.record().field("trainerid").value().toInt();
    }
    else
    {
        return -1;
    }
}
// access static database objects
// pokemons from pokedex
bool accessPokemon(QString PokemonName, QSqlRecord &pokemon)
{
    QSqlQuery query;
    QString statement = "SELECT * FROM Moves WHERE Name='" + PokemonName + "'";
    query.exec(statement);
    if( query.next() )
    {
        pokemon = query.record();
        return true;
    }
    else
    {
        return false;
    }
}

QString accessHelper(QString pokemonName, QString column)
{
    QSqlRecord rec;
    bool success = accessPokemon(pokemonName, rec);
    if( success )
    {
        return rec.field(column).value().toString();
    }
    else
    {
        return "-1";
    }
}
QString getPokemonType(QString pokemonName)
{
    QString result = accessHelper(pokemonName, "Type");
    return (result == "-1") ? "" : result;
}
int getBaseAtt(QString pokemonName)
{
    return accessHelper(pokemonName, "BaseAtt").toInt();
}
int getBaseDef(QString pokemonName)
{
    return accessHelper(pokemonName, "BaseDef").toInt();
}
int getBaseSpeed(QString pokemonName)
{
    return accessHelper(pokemonName, "BaseSpeed").toInt();
}
int getBaseHP(QString pokemonName)
{
    return accessHelper(pokemonName, "BaseHP").toInt();
}
int getAttYield(QString pokemonName)
{
    return accessHelper(pokemonName, "AtEVyield").toInt();
}
int getDefYield(QString pokemonName)
{
    return accessHelper(pokemonName, "DefEVyield").toInt();
}
int getSpeedYield(QString pokemonName)
{
    return accessHelper(pokemonName, "speedEVyield").toInt();
}
int getHPYield(QString pokemonName)
{
    return accessHelper(pokemonName, "HPEVyield").toInt();
}
int getEXPYield(QString pokemonName)
{
    return accessHelper(pokemonName, "EXPyield").toInt();
}

// damage modifiers
double accessDamageModifer(QString attackType, QString victimType)
{
    QSqlQuery query;
    QString statement = "SELECT * FROM TypeEffectiveness WHERE AttackType='" + attackType + "' AND VictimType='"
            + victimType + "'";
    query.exec(statement);
    if( query.next() )
    {
        return query.record().field("Modifier").value().toDouble();
    }
    else
    {
        return -1;
    }
}

// moves
bool accessMove(QString MoveName, QSqlRecord &rec)
{
    QSqlQuery query;
    QString statement = "SELECT * FROM Moves WHERE Name='" + MoveName + "'";
    query.exec(statement);
    if( query.next() )
    {
        rec = query.record();
        return true;
    }
    else
    {
        return false;
    }
}
QString accessHelperMove(QString MoveName, QString column)
{
    QSqlRecord rec;
    bool success = accessMove(MoveName, rec);
    if( success )
    {
        return rec.field(column).value().toString();
    }
    else
    {
        return "-1";
    }
}
QString getMoveType(QString MoveName)
{
    QString result = accessHelper(MoveName, "Type");
    return (result == "-1") ? "" : result;
}
int getDamage(QString MoveName)
{
    return accessHelper(MoveName, "Damage").toInt();
}
int getAccuracy(QString MoveName)
{
    return accessHelper(MoveName, "Accuracy").toInt();
}
int getPP(QString MoveName)
{
    return accessHelper(MoveName, "PP").toInt();
}
