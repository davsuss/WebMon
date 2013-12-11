#include "xmltodatabase.h"

void connect(QString pathToDatabaseFile)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // TELLS QT LIBS ABOUT DATABASE
    db.setDatabaseName(pathToDatabaseFile);// WHERE TO STORE THE FILES
    if (!db.open()) { // CHECK IF IT OPEN
        qDebug() << "Unable to connect to Database";
        return;
    }
}

void createTables()
{
    // create new tables
    // create tables
    QSqlQuery query;

    query.exec("create table Moves(moveid integer primary key, Name varchar(20), Type varchar(20), PP integer, Damage integer, Accuracy integer)");

    query.exec("create table TypeEffectiveness(teid integer primary key, AttackType varchar(20), VictimType varchar(20), Modifier varchar(20))");

    query.exec("create table Pokedex(pid integer primary key, Name varchar(20), Type varchar(20), BaseAtt integer, BaseDef integer, BaseSpeed integer, BaseHP integer, AtEVyield integer, DefEVyield integer, speedEVyield integer, HPEVyield integer, EXPyield integer, evolveLevel integer)");
    /**/
}

void updateTables()
{
    if(validateXML())
    {
        qDebug() << "Reading Pokemon!";
        readALLPokemon();
        qDebug() << "Reading Moves!";
        readALLMoves();
        qDebug() << "Reading Type Match Ups!";
        readALLTypeEffectiveness();
    }
}

void readALLMoves()
{
    QString moveName;
    QString moveType;
    QString movePP;
    QString moveAccuracy;
    QString moveDamage;
    QSqlQuery query;
    /* We'll parse the example.xml */
    QFile* file = new QFile("./xmlFiles/moves.xml");
    /* If we can't open it, let's show an error message. */
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Problem Opening File!";
        return;
    }
    /* QXmlStreamReader takes any QIODevice. */
    QXmlStreamReader xml(file);
    /* We'll parse the XML until we reach end of it.*/
    while(!xml.atEnd() &&
            !xml.hasError())
    {
        /* Read next element.*/
        QXmlStreamReader::TokenType token = xml.readNext();

        /* If token is just StartDocument, we'll go to next.*/
        if(token == QXmlStreamReader::StartDocument)
        {
            continue;
        }

        /* If token is StartElement, we'll see if we can read it.*/
        if(token == QXmlStreamReader::StartElement)
        {
            /* If it's named persons, we'll go to the next.*/
            if(xml.name() == "moves")
            {
                continue;
            }
            /* If it's named person, we'll dig the information from there.*/
            if(xml.name() == "move")
            {
                /*
                 * We're going to loop over the things because the order might change.
                 * We'll continue the loop until we hit an EndElement named person.
                 */
                while(!(xml.tokenType() == QXmlStreamReader::EndElement &&
                        xml.name() == "move"))
                {
                    if(xml.tokenType() == QXmlStreamReader::StartElement) {

                        if(xml.name() == "name")
                        {
                            moveName = xml.readElementText();
                        }
                        else if(xml.name() == "type")
                        {
                            moveType = xml.readElementText();
                        }
                        else if(xml.name() == "pp")
                        {
                            movePP = xml.readElementText();
                        }
                        else if(xml.name() == "baseDamage")
                        {
                            moveDamage = xml.readElementText();
                        }
                        else if(xml.name() == "Accuracy")
                        {
                            moveAccuracy = xml.readElementText();
                        }
                    }
                    /* ...and next... */
                    xml.readNext();
                }
            }
            QString statement = "INSERT INTO Moves (Name, Type, PP, Damage, Accuracy) values('"
                    + moveName + "', '" + moveType + "', " + movePP + ", " + moveDamage
                    + ", " + moveAccuracy + ")";
            if( !query.exec(statement) )
            {
                qDebug() << query.lastError().databaseText();
            }
        }
    }
    /* Error handling. */
    if(xml.hasError())
    {
        qDebug() << "XMLError in moves.xml";
    }
    /* Removes any device() or data from the reader
     * and resets its internal state to the initial state. */
    xml.clear();
    QString statement = "SELECT * FROM Moves";
    query.exec(statement);
    while( query.next() )
    {
        qDebug() << "Move: " << query.record().field("Name").value().toString() << " Will do damage: " << query.record().field("Damage").value().toString();
    }
}

void readALLPokemon()
{
    QString pokemonName;
    QString pokemonType;
    QString attack;
    QString defense;
    QString speed;
    QString HP;
    QString attackYield;
    QString defenseYield;
    QString speedYield;
    QString HPYield;
    QString expYield;
    QString levelToEvolve;
    QSqlQuery query;
    /* We'll parse the example.xml */
    QFile* file = new QFile("./xmlFiles/AllPokemon.xml");
    /* If we can't open it, let's show an error message. */
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Problem Opening File!";
        return;
    }
    /* QXmlStreamReader takes any QIODevice. */
    QXmlStreamReader xml(file);
    /* We'll parse the XML until we reach end of it.*/
    while(!xml.atEnd() &&
            !xml.hasError())
    {
        /* Read next element.*/
        QXmlStreamReader::TokenType token = xml.readNext();

        /* If token is just StartDocument, we'll go to next.*/
        if(token == QXmlStreamReader::StartDocument) {
            continue;
        }

        /* If token is StartElement, we'll see if we can read it.*/
        if(token == QXmlStreamReader::StartElement) {
            /* If it's named persons, we'll go to the next.*/
            if(xml.name() == "pokedex") {
                continue;
            }
            /* If it's named pokemon, we'll dig the information from there.*/
            if(xml.name() == "pokemon") {
                /*
                 * We're going to loop over the things because the order might change.
                 * We'll continue the loop until we hit an EndElement named person.
                 */
                while(!(xml.tokenType() == QXmlStreamReader::EndElement &&
                        xml.name() == "pokemon"))
                {
                    if(xml.tokenType() == QXmlStreamReader::StartElement) {

                        if(xml.name() == "ID")
                        {

                        }
                        else if(xml.name() == "name")
                        {
                            pokemonName = xml.readElementText();
                        }
                        else if(xml.name() == "type")
                        {
                            pokemonType = xml.readElementText();
                        }
                        else if(xml.name() == "HP")
                        {
                            HP = xml.readElementText();
                        }
                        else if(xml.name() == "Attack")
                        {
                            attack = xml.readElementText();
                        }
                        else if(xml.name() == "Defense")
                        {
                            defense = xml.readElementText();
                        }
                        else if(xml.name() == "Speed")
                        {
                            speed = xml.readElementText();
                        }
                        else if(xml.name() == "HPYield")
                        {
                            HPYield = xml.readElementText();
                        }
                        else if(xml.name() == "AttackYield")
                        {
                            attackYield = xml.readElementText();
                        }
                        else if(xml.name() == "DefenseYield")
                        {
                            defenseYield = xml.readElementText();
                        }
                        else if(xml.name() == "SpeedYield")
                        {
                            speedYield = xml.readElementText();
                        }
                        else if(xml.name() == "EXPYield")
                        {
                            expYield = xml.readElementText();
                        }
                        else if(xml.name() == "evolveLevel")
                        {
                            levelToEvolve = xml.readElementText();
                        }
                    }
                    /* ...and next... */
                    xml.readNext();
                }
                QString statement = "INSERT INTO Pokedex (Name, Type, BaseAtt, BaseDef, BaseSpeed, BaseHP, AtEVyield, DefEVyield, speedEVyield, HPEVyield, EXPyield, evolveLevel) values('"
                        + pokemonName + "', '" + pokemonType + "', " + attack + ", " + defense
                        + ", " + speed + ", " + HP + ", " + attackYield + ", " + defenseYield + ", " + speedYield
                        + ", " + HPYield + ", " + expYield + ", " + levelToEvolve + ")";
                if( !query.exec(statement) )
                {
                    qDebug() << query.lastError().databaseText();
                    return;
                }
            }
        }
    }
    /* Error handling. */
    if(xml.hasError()) {

    }
    /* Removes any device() or data from the reader
     * and resets its internal state to the initial state. */
    xml.clear();
    QString statement = "SELECT * FROM Pokedex";
    query.exec(statement);
    while( query.next() )
    {
        qDebug() << "Added to Pokedex: " << query.record().field("Name").value().toString() << " Will evolve at: " << query.record().field("evolveLevel").value().toString();
    }
}

void readALLTypeEffectiveness()
{
    QString attackType;
    QString victimType;
    QString modifier;
    QSqlQuery query;
    /* We'll parse the example.xml */
    QFile* file = new QFile("./xmlFiles/typeEffectiveness.xml");
    /* If we can't open it, let's show an error message. */
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Problem Opening File!";
        return;
    }
    /* QXmlStreamReader takes any QIODevice. */
    QXmlStreamReader xml(file);
    /* We'll parse the XML until we reach end of it.*/
    while(!xml.atEnd() &&
            !xml.hasError())
    {
        /* Read next element.*/
        QXmlStreamReader::TokenType token = xml.readNext();

        /* If token is just StartDocument, we'll go to next.*/
        if(token == QXmlStreamReader::StartDocument) {
            continue;
        }

        /* If token is StartElement, we'll see if we can read it.*/
        if(token == QXmlStreamReader::StartElement) {
            /* If it's named persons, we'll go to the next.*/
            if(xml.name() == "effect") {
                continue;
            }
            /* If it's named person, we'll dig the information from there.*/
            if(xml.name() == "attack") {
                while(!(xml.tokenType() == QXmlStreamReader::EndElement &&
                        xml.name() == "attack"))
                {
                    if(xml.tokenType() == QXmlStreamReader::StartElement) {
                        if(xml.name() == "name")
                        {
                            attackType = xml.readElementText();
                        }
                        else if(xml.name() == "victim")
                        {
                            while(!(xml.tokenType() == QXmlStreamReader::EndElement &&
                                    xml.name() == "victim"))
                            {
                                if(xml.tokenType() == QXmlStreamReader::StartElement) {
                                    if(xml.name() == "type")
                                    {
                                        victimType = xml.readElementText();
                                    }
                                    else if(xml.name() == "modifier")
                                    {
                                        modifier = xml.readElementText();
                                    }
                                }
                                /* ...and next... */
                                xml.readNext();
                            }
                            QString statement = "INSERT INTO TypeEffectiveness (AttackType, VictimType, Modifier) values('" + attackType + "', '" + victimType + "', '" + modifier + "')";
                            query.exec(statement);
                        }
                    }
                    /* ...and next... */
                    xml.readNext();
                }
            }
        }
    }
    /* Error handling. */
    if(xml.hasError()) {

    }
    /* Removes any device() or data from the reader
     * and resets its internal state to the initial state. */
    xml.clear();
    QString statement = "SELECT * FROM TypeEffectiveness";
    query.exec(statement);
    while( query.next() )
    {
        qDebug() << "Added to TypeEffectiveness table: " << query.record().field("VictimType").value().toString();
    }
    qDebug() << "****************If no 'Added to TypeEffectiveness table' shown... problem!****************";
}

bool validateXML()
{
    // validate the allPokemons.xml
    QFile schemaFile("./xmlFiles/AllPokemon.xsd");
    bool open = schemaFile.open(QIODevice::ReadOnly);
    QXmlSchema schema;
    schema.load(&schemaFile, QUrl::fromLocalFile(schemaFile.fileName()));

    if ( schema.isValid() )
    {
        QFile xmlFile("./xmlFiles/AllPokemon.xml");
        open = xmlFile.open(QIODevice::ReadOnly);

        QXmlSchemaValidator validator( schema );

        if ( !validator.validate(&xmlFile, QUrl::fromLocalFile(xmlFile.fileName())) )
        {
            qDebug() << "AllPokemon.xml is invalid!";
            return false;
        }
    }
    else
    {
        return false;
    }

    // validate the moves.xml
    QFile schemaFile1("./xmlFiles/moves.xsd");
    open = schemaFile1.open(QIODevice::ReadOnly);
    QXmlSchema schema1;
    schema1.load(&schemaFile1, QUrl::fromLocalFile(schemaFile1.fileName()));

    if ( schema1.isValid() )
    {
        QFile xmlFile1("./xmlFiles/moves.xml");
        open = xmlFile1.open(QIODevice::ReadOnly);

        QXmlSchemaValidator validator1( schema1 );

        if ( !validator1.validate(&xmlFile1, QUrl::fromLocalFile(xmlFile1.fileName())) )
        {
            qDebug() << "moves.xml is invalid!";
            return false;
        }
    }
    else
    {
        return false;
    }

    // validate the typeEffectiveness.xml
    QFile schemaFile2("./xmlFiles/typeEffectiveness.xsd");
    open = schemaFile2.open(QIODevice::ReadOnly);
    QXmlSchema schema2;
    schema2.load(&schemaFile2, QUrl::fromLocalFile(schemaFile2.fileName()));

    if ( schema2.isValid() )
    {
        QFile xmlFile2("./xmlFiles/typeEffectiveness.xml");
        open = xmlFile2.open(QIODevice::ReadOnly);

        QXmlSchemaValidator validator2( schema2 );

        if ( !validator2.validate(&xmlFile2, QUrl::fromLocalFile(xmlFile2.fileName())) )
        {
            qDebug() << "typeEffectiveness.xml is invalid!";
            return false;
        }
    }
    else
    {
        return false;
    }
}

void clearTables()
{
    // clear and delete all tables
    QSqlQuery queryToDelete;
    bool worked = queryToDelete.exec("DELETE FROM Moves") || queryToDelete.exec("DELETE FROM TypeEffectiveness") ||
                    queryToDelete.exec("DELETE FROM Pokedex") || queryToDelete.exec("DROP TABLE Moves") ||
                    queryToDelete.exec("DROP TABLE TypeEffectiveness") || queryToDelete.exec("DROP TABLE Pokedex");
    if( !worked )
    {
        qDebug() << queryToDelete.lastError().databaseText();
    }
}
