#ifndef TRAINER_H
#define TRAINER_H

/*************************************************************************************
* file needed from Qt
**************************************************************************************/
#include <QList>
#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QStringList>
/*************************************************************************************
* file needed for game
**************************************************************************************/
#include "databaseConversation.h"
#include "gamemechanics.h"
#include "constants.h"

class trainer : public QObject
{
    Q_OBJECT

public:
    trainer(QObject *parent = 0);
    ~trainer();
signals:
    /**
     * sent to server when wants to end thread
     */
    void endConnection(QString id);

public slots:
    /***
     * makes network connections needed
     */
    void init(int socketDescriptor, QString id);
    /**
     * invoked by the ready read signal from the socket
     *          when new info to read
     */
    void newInfo();
    /**
     * to let the server know to quit the client's thread
     */
    void ClientDisconnected();
    /**
     * print that socket has been destroyed
     */
    void printSocketDestroyed();

private:
    /*************************************************************************************
    * variables needed to socket communication
    **************************************************************************************/
    QTcpSocket *m_socket; /**< socket connected the client */
    quint16 m_blocksize; /**< blocksize sent by the client of how big the message is */
    QObject *m_dummyParent;
    QString m_id; // id provided by the server

    /*************************************************************************************
    * variables needed to game
    **************************************************************************************/
    // signifies if this trainer object has been initialized to mirror a trainer (client)
    bool m_hasBeenBuilt;
    bool canPlay(){return m_hasBeenBuilt;}

    QMap<QString, pokemonStruct> m_pokemons; // list of pokemons
    QMap<QString, pokemonStruct> m_opposing; // pokemon of the opposing team
    QString m_memberinBattle; // name of my pokemon in battle
    QString m_opposinginBattle; // name of opposing team's pokemon in battle
    QString m_username; // name of trainer

    gameState m_trainerState;

    /*************************************************************************************
    * private functions to talk to client and manage game
    **************************************************************************************/
    void handleCommand(QString command);
    void reply(QString reply);
    void resumeFromSavedData(QString name);
    void saveData();
    QString encodePokemon(pokemonStruct pokemon);
    QString encodeMyTeam(); // converts m_pokemons into a protocol formatted string
    QString encodeOpposingTeam(); // converts m_oposing into a protocol formatted string
    QString encodeInitialResponse(); // enodes myself to send as initial response
    QString encodeBattleResult(int expLeft); // encodes myself to send after a battle
    QString encodeMoveResult(moveResult res); // encodes myself to send after a move has been played and landed
    QString encodeBattleInitResult();
    /***
     * Purpose: To initize this object to mirror an actual trainer with
     *          pokemon. If old trainer, then read from database. Or created a random
     *          party.
     *
     *      Name must be unique.
     ***/
    void buildTrainer(QString username);
};

#endif // TRAINER_H
