#include "databaseConversation.h"

// TELLS QT LIBS ABOUT DATABASE
QSqlDatabase Static;
QSqlDatabase Dynamic;

bool connectToDB()
{
    Static = QSqlDatabase::addDatabase("QSQLITE", "Static");
    Dynamic = QSqlDatabase::addDatabase("QSQLITE", "Dynamic");
    Static.setDatabaseName(staticdatabase);// WHERE TO STORE THE FILES
    Dynamic.setDatabaseName(dynamicdatabase);
    if (!Static.open() || !Dynamic.open() ) { // CHECK IF IT OPEN
        return false;
    }
    else
    {
        QSqlQuery queryS(Static);
        if( queryS.exec("SELECT name FROM sqlite_master WHERE type = 'table' ORDER BY 1") )
        {
            qDebug() << "game.db already contains: ";
            while(queryS.next())
            {
                qDebug() << queryS.record().field("name").value().toString();
            }
        }
        else
        {
            qDebug() << queryS.lastError().databaseText();
        }
        QSqlQuery queryD(Dynamic);
        if( queryD.exec("SELECT name FROM sqlite_master WHERE type = 'table' ORDER BY 1") )
        {
            qDebug() << "saveData.db already contains: ";
            while(queryD.next())
            {
                qDebug() << queryD.record().field("name").value().toString();
            }
        }
        else
        {
            qDebug() << queryS.lastError().databaseText();
        }
        return true;
    }
}

void createTables()
{
    QSqlQuery query(Dynamic);
    if( !query.exec("CREATE TABLE Trainers(trainerID integer primary key, Name varchar(20), numberOfPokemon integer)") )
    {
       qDebug() << query.lastError().databaseText();
       qDebug() << "Run the server with -reset as an argument...";
    }

    if( !query.exec("CREATE TABLE CaughtPokemon(CPID INTEGER primary key, trainer varchar(20), PID INTEGER, AtEV INTEGER, DefEV INTEGER, speedEV INTEGER, HPEV INTEGER, EXP INTEGER, HP INTEGER, Moves varchar(60))") )
    {
        qDebug() << query.lastError().databaseText();
        qDebug() << "Run the server with -reset as an argument...";
    }
}
void clearTables()
{
    // only clear the dynamic database
    QSqlQuery query(Dynamic);
    if( !query.exec("DELETE FROM Trainers") )
    {
        qDebug() << query.lastError().databaseText();
    }
    if( !query.exec("DELETE FROM CaughtPokemon") )
    {
        qDebug() << query.lastError().databaseText();
    }
    if( ! query.exec("DROP TABLE Trainers") )
    {
        qDebug() << query.lastError().databaseText();
    }
    if( !query.exec("DROP TABLE CaughtPokemon") )
    {
        qDebug() << query.lastError().databaseText();
    }
}
bool createTrainer(QString Name)
{
    if( !trainerExists(Name) )
    {
        QSqlQuery query(Dynamic);
        if( !query.exec("INSERT INTO Trainers(Name, numberOfPokemon) values('" + Name + "', 0)") )
        {
            qDebug() << query.lastError().databaseText();
            return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}
bool trainerExists(QString name)
{
    QSqlQuery query(Dynamic);
    QString q = "SELECT * FROM Trainers WHERE Name='" + name + "'";
    if( !query.exec(q) )
    {
        qDebug() << query.lastError().databaseText();
        return false;
    }
    if( query.next() )
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool deleteTrainer(QString Name)
{
    if( trainerExists(Name) )
    {
        QSqlQuery query(Dynamic);
        if( !query.exec("DELETE FROM Trainers WHERE Name='" + Name + "'") )
        {
            qDebug() << query.lastError().databaseText();
            return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}
bool accessTrainer(QString TrainerName, QSqlRecord &rec)
{
    QSqlQuery query(Dynamic);
    QString statement = "SELECT * FROM Trainers WHERE Name='" + TrainerName + "'";
    if( !query.exec(statement) )
    {
        qDebug() << query.lastError().databaseText();
        return false;
    }
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
QString accessHelperTrainer(QString trainerName, QString column)
{
    QSqlRecord rec;
    bool success = accessTrainer(trainerName, rec);
    if( success )
    {
        return rec.field(column).value().toString();
    }
    else
    {
        return "-1";
    }
}
int numOfPokemonCaught(QString name)
{
    if( trainerExists(name) )
    {
        return accessHelperTrainer(name, "numberOfPokemon").toInt();
    }
    else
    {
        return -1;
    }
}
bool changeNumOfPokemonCaught(QString name, int num)
{
    if( trainerExists(name) )
    {
        QSqlQuery query(Dynamic);
        if( !query.exec("UPDATE Trainers SET numberOfPokemon=" + QString::number(num) + " WHERE Name='" + name + "'") )
        {
            qDebug() << query.lastError().databaseText();
            return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}

int addCaughtPokemon(QString trainer, int HP, int PID, int attackEV, int defEV, int speedEV, int HPEV, int exp, QString moves)
{
    // search for trainer first
    QSqlRecord rec;
    bool created = accessTrainer(trainer, rec);
    if( created )
    {
        QSqlQuery query(Dynamic);
        QString statement = "INSERT INTO CaughtPokemon(trainer, PID, AtEV, DefEV, speedEV, HPEV, EXP, HP, Moves) values('" + trainer + "', " + QString::number(PID) + ", " + QString::number(attackEV) + ", " + QString::number(defEV) + ", " + QString::number(speedEV) + ", " + QString::number(HPEV) + ", " + QString::number(exp) + ", " + QString::number(HP) + ", '" + moves + "')";
        if( !query.exec(statement) )
        {
            qDebug() << query.lastError().databaseText();
            return -1;
        }
        else
        {
            // succefully added newly caught pokemon
            query.exec("SELECT * FROM CaughtPokemon WHERE trainer='" + trainer + "'");
            int pokemons = 0;
            while( query.next() )
            {
                pokemons++;
            }
            changeNumOfPokemonCaught(trainer, pokemons);
            return pokemons;
        }
    }
    else
    {
        return -1;
    }
}

QMap<QString, pokemonStruct> accessAllCaughtPokemon(QString trainerName)
{
    QMap<QString, pokemonStruct> data;
    QSqlQuery query(Dynamic);
    QString statement = "SELECT * FROM CaughtPokemon WHERE trainer='" + trainerName + "'";
    if( !query.exec(statement) )
    {
        qDebug() << query.lastError().databaseText();
        return data;
    }
    while( query.next() )
    {        
        pokemonStruct saved;
        saved.PID = query.record().field("PID").value().toInt();
        saved.attEV = query.record().field("AtEV").value().toInt();
        saved.CPID = query.record().field("CPID").value().toInt();
        saved.defEV = query.record().field("DefEV").value().toInt();
        saved.EXP = query.record().field("EXP").value().toInt();
        saved.HPEV = query.record().field("HPEV").value().toInt();
        saved.speedEV = query.record().field("speedEV").value().toInt();
        saved.HP = query.record().field("HP").value().toInt();
        saved.level = getLevel(saved.EXP);
        saved.name = getPokemonName(QString::number(saved.PID));
        saved.attack = getStat(saved.attEV, getBaseAtt(saved.name), saved.level);
        saved.defense = getStat(saved.defEV, getBaseDef(saved.name), saved.level);
        saved.speed = getStat(saved.speedEV, getBaseSpeed(saved.name), saved.level);
        saved.HP = getHP(saved.HPEV, getBaseHP(saved.name), saved.level);
        QString moves = query.record().field("Moves").value().toString();
        QStringList l = moves.split("|");
        for(int i = 0; i < l.size(); i++)
        {
            QStringList m = l[i].split(".");
            moveStruct move;
            move.name = m[0];
            move.pp = m[1].toInt();
            move.accuracy = getAccuracy(move.name);
            move.damage = getDamage(move.name);
            move.type = getMoveType(move.name);
            saved.moves.append(move);
        }
        data.insert(saved.name, saved);
    }
    return data;
}

void clearAllCaughtPokemon(QString trainerName)
{
    QSqlQuery query(Dynamic);
    if( !query.exec("DELETE FROM CaughtPokemon WHERE trainer='" + trainerName + "'"))
    {
        qDebug() << query.lastError().databaseText();
    }
}

// access static database objects
// pokemons from pokedex
bool accessPokemon(QString PokemonName, QSqlRecord &pokemon)
{
    QSqlQuery query(Static);
    QString statement = "SELECT * FROM Pokedex WHERE Name='" + PokemonName + "'";
    if( !query.exec(statement) )
    {
        qDebug() << query.lastError().databaseText();
        return false;
    }
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
QString getPokemonName(QString id)
{
    QSqlQuery query(Static);
    QString statement = "SELECT * FROM Pokedex WHERE pid='" + id + "'";
    if( !query.exec(statement) )
    {
        qDebug() << query.lastError().databaseText();
        return "Problem!";
    }
    if( query.next() )
    {
        return query.record().field("Name").value().toString();
    }
    else
    {
        return "No pokemon with id: " + id;
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
int getEvolveLevel(QString pokemonName)
{
    return accessHelper(pokemonName, "evolveLevel").toInt();
}
int getEvolveTo(QString pokemonName)
{
    int id = accessHelper(pokemonName, "evolveTo").toInt();
    return id;
}
QList<QString> getEvolChain(QString pokemonName)
{
    QString chain = accessHelper(pokemonName, "evolutionaryChain");
    QList<QString> c;
    if( chain.contains(',') )
    {
        QStringList l = chain.split(",");

        for( int i = 0; i < l.size(); i++ )
        {
            c.append(l[i]);
        }
    }
    else
    {
        c.append(chain);
    }
    return c;
}
int numberOfPokemon()
{
    QSqlQuery query(Static);
    if( query.exec("SELECT * FROM Pokedex") )
    {
        int number = 0;
        while( query.next() )
        {
            number++;
        }
        return number;
    }
    else
    {
        qDebug() << query.lastError().databaseText();
        return 0;
    }
}

// damage modifiers
double accessDamageModifer(QString attackType, QString victimType)
{
    QSqlQuery query(Static);
    QString statement = "SELECT * FROM TypeEffectiveness WHERE AttackType='" + attackType + "' AND VictimType='"
            + victimType + "'";
    if( !query.exec(statement) )
    {
        qDebug() << query.lastError().databaseText();
        return false;
    }
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
    QSqlQuery query(Static);
    QString statement = "SELECT * FROM Moves WHERE Name='" + MoveName + "'";
    if( !query.exec(statement) )
    {
        qDebug() << query.lastError().databaseText();
        return false;
    }
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
    QString result = accessHelperMove(MoveName, "Type");
    return (result == "-1") ? "" : result;
}
int getDamage(QString MoveName)
{
    return accessHelperMove(MoveName, "Damage").toInt();
}
int getAccuracy(QString MoveName)
{
    return accessHelperMove(MoveName, "Accuracy").toInt();
}
int getPP(QString MoveName)
{
    return accessHelperMove(MoveName, "PP").toInt();
}

QList<QString> MovesOfType(QString Type)
{
    QList<QString> allMoves;
    QSqlQuery query(Static);
    if( query.exec("SELECT (Name) FROM Moves WHERE Type='" + Type + "'"))
    {
        while( query.next() )
        {
            allMoves.append(query.record().field("Name").value().toString());
        }
    }
    else
    {
        qDebug() << query.lastError().databaseText();
        allMoves.clear();
    }
    return allMoves;
}

QList<QString> getAllTypes()
{
    QList<QString> allTypes;
    QSqlQuery query(Static);
    if( query.exec("SELECT (Type) FROM Pokedex"))
    {
        while(query.next())
        {
            QString type = query.record().field("Type").value().toString();
            if( !allTypes.contains(type) )
            {
                allTypes.append(type);
            }
        }
    }
    else
    {
        qDebug() << query.lastError().databaseText();
    }
    return allTypes;
}
