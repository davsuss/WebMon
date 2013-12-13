#include "trainer.h"

trainer::trainer(QObject *parent) : QObject(parent)
{
    m_hasBeenBuilt = false;
}

void trainer::init(int socketDescriptor, QString id)
{
    m_trainerState = unbuilt;
    this->m_id = id;
    this->m_blocksize = 0;
    this->m_dummyParent = new QObject();
    m_socket = new QTcpSocket(m_dummyParent);
    m_socket->setSocketDescriptor(socketDescriptor);

    QObject::connect(m_socket, SIGNAL(readyRead()), this, SLOT(newInfo()));
    // to ask the server to end this thread
    QObject::connect(m_socket, SIGNAL(disconnected()), this, SLOT(ClientDisconnected()));
    // to print when the socket is destroyed
    QObject::connect(m_socket, SIGNAL(destroyed()), this, SLOT(printSocketDestroyed()));
    this->reply("Successuly connected");
}

void trainer::buildTrainer(QString username)
{
    if( !m_hasBeenBuilt )
    {
        if( trainerExists(username) )
        {
            resumeFromSavedData(username);
        }
        else
        {
            while(generatePartyPkmn(m_pokemons));
        }
        m_username = username;
        m_trainerState = idle;
        m_hasBeenBuilt = true;
        QString response = encodeInitialResponse();
        reply(response);
    }
    else
    {
        this->reply("ERROR: Already registered as player, logout first!");
    }
}

void trainer::newInfo()
{
    QDataStream in(m_socket);
    in.setVersion(QDataStream::Qt_4_0);

    if (m_blocksize == 0) {
        if (m_socket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> m_blocksize;
    }

    if (m_socket->bytesAvailable() < m_blocksize)
        return;

    QString command;
    in >> command;
    m_blocksize = 0;
    this->handleCommand(command);
}

void trainer::reply(QString reply)
{
    //new reply
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);

    out << (quint16)0;
    out << reply;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    this->m_socket->write(block);
}

void trainer::handleCommand(QString command)
{
    QStringList sub = command.split(":");
    switch(this->m_trainerState)
    {
    case unbuilt:
    {
        if( sub.at(0).compare("build", Qt::CaseInsensitive) == 0 )
        {
            this->buildTrainer(sub.at(1));
            m_trainerState = idle;
        }
        else
        {
            reply("ERROR: before doing anything, build log-in!");
        }
        break;
    }
    case idle:
    {        
        if( sub.at(0).compare("start random encounter", Qt::CaseInsensitive) == 0 )
        {
            // add only one pokemon to the opposing team (wild pokemon encounter)
            if( m_pokemons.contains(sub.at(1)) )
            {
                m_memberinBattle = sub.at(1);
                pokemonStruct enemy = genRandPkmn(m_pokemons[m_memberinBattle].level);
                m_opposing.insert(enemy.name, enemy);
                m_opposinginBattle = enemy.name;
                m_trainerState = battle;
                reply(encodeBattleInitResult());
            }
            else
            {
                reply("ERROR pokemon chosen not in team");
            }
        }
        else
        {
            this->reply("id: " + this->m_id + " received urecognized command for a non battle state: " + command);
        }
        break;
    }
    case battle:
    {
        if( sub.at(0).compare("Move", Qt::CaseInsensitive) == 0 )
        {
            moveStruct movePlayed;
            bool present = false;
            int i = 0;
            for( i = 0; i < m_pokemons[m_memberinBattle].moves.size() && !present; i++ )
            {
                if( sub.at(1).compare(m_pokemons[m_memberinBattle].moves[i].name, Qt::CaseInsensitive) == 0 )
                {
                    movePlayed = m_pokemons[m_memberinBattle].moves[i];
                    present = true;
                    i--;
                }
            }
            if( present )
            {
                moveResult resp = playMove(m_pokemons[m_memberinBattle], movePlayed, m_opposing[m_opposinginBattle]);
                m_pokemons[m_memberinBattle].moves.replace(i, movePlayed);
                if( resp.enemyAlive && resp.meAlive )
                {
                    reply("MoveResult:" + encodeMoveResult(resp));
                }
                else if( resp.meAlive  && !resp.enemyAlive)
                {
                    int expLeft = growPokemon(m_pokemons[m_memberinBattle], m_opposing[m_opposinginBattle]);
                    reply("Won:" + encodeBattleResult(expLeft));
                    m_trainerState = idle;
                    restorePkmn(m_pokemons[m_memberinBattle]);
                }
                else
                {
                    int expLeft = levelUp(m_pokemons[m_memberinBattle]);
                    reply("Lost:" + encodeBattleResult(expLeft));
                    m_trainerState = idle;
                    restorePkmn(m_pokemons[m_memberinBattle]);
                }
            }
            else
            {
                this->reply("ERROR: Move chosen doesn't exists, move: " + sub.at(1) );
            }
        }
        else
        {
            this->reply("ERROR: received urecognized command for a battle state: " + command + " can only play a move or quit!");
        }
        break;
    }
    }
}

void trainer::resumeFromSavedData(QString name)
{
    m_pokemons = resume(name);
}

void trainer::saveData()
{
    save(m_username, m_pokemons);
}

QString trainer::encodePokemon(pokemonStruct member)
{
    QString resp = "";
    resp += member.name + "|" + QString::number(member.level) + "|" + QString::number(member.HP) + "|";
    int j = 0;
    foreach( moveStruct m, member.moves )
    {
        j++;
        resp += m.name + "-" + m.type + "-" + QString::number(m.pp) + ((j==member.moves.size()) ? "":"|");
    }
    return resp;
}
QString trainer::encodeMyTeam()
{
    // pokemon1Name.p1HP.p1m.p1m|p2...
    QString res = "";
    int i = 0;
    foreach(pokemonStruct member, m_pokemons)
    {
        i++;
        res += encodePokemon(member) + ((i==m_pokemons.size())? "" : ":");
    }
    return res;
}
QString trainer::encodeOpposingTeam()
{
    // pokemon1Name.p1HP.p1m.p1m|p2...
    QString res = "";
    int i = 0;
    foreach(pokemonStruct member, m_opposing)
    {
        i++;
        res += encodePokemon(member) + ((i==m_pokemons.size())? "" : ":");
    }
    return res;
}
QString trainer::encodeInitialResponse()
{
    QString res = "Init:";
    res += encodeMyTeam();
    return res;
}
QString trainer::encodeBattleInitResult()
{
    QString resp = "StartRandomEncounter:";
    pokemonStruct member = m_pokemons[m_memberinBattle];
    resp += encodePokemon(member) + ":";
    member = m_opposing[m_opposinginBattle];
    resp += encodePokemon(member);
    return resp;
}
QString trainer::encodeBattleResult(int expLeft)
{
    // pokemon1Name.p1HP.p1m.p1m|p2...
    QString res = "Battle over:" + QString::number(expLeft) + ":";
    pokemonStruct member = m_pokemons[m_memberinBattle];
    res += encodePokemon(member);
    return res;
}

QString trainer::encodeMoveResult(moveResult res)
{
    // pokemon1Name.p1HP.p1m.p1m|p2...
    QString resp = "";
    if( res.iWentFirst )
    {
        pokemonStruct member = m_pokemons[m_memberinBattle];
        resp += "Friend|" + encodePokemon(member) + ":";
        member = m_opposing[m_opposinginBattle];
        resp += "Enemy|" + encodePokemon(member);
    }
    else
    {
        pokemonStruct member = m_opposing[m_opposinginBattle];
        resp += "Enemy|" + encodePokemon(member) + ":";
        member = m_pokemons[m_memberinBattle];
        resp += "Friend|" + encodePokemon(member);
    }
    return resp;
}


void trainer::ClientDisconnected()
{
    emit trainer::endConnection(this->m_id);
}

void trainer::printSocketDestroyed()
{
    qDebug() << this->m_id << "'s socket has been destroyed!";
}

trainer::~trainer()
{
    // convert this object into database entry and save state
    saveData();
    delete this->m_dummyParent; // will delete all gates and tcpSocket
}
