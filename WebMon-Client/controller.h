#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "mainwindow.h"
#include "logindialog.h"
#include "datastore.h"
#include "Structs.h"
#include <QObject>
typedef enum {PlayerTurn,waiting} EncounterState;
typedef enum {Connecting,RandomEncounter,Challenge,Waiting} gameState;

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    void setDialog(LoginDialog* d);
    void setData(DataStore * data);
    void setMain(MainWindow* main);
public slots:
    void ServerResponse(QString response);
    void ConnectSucessful();
    void ConnectFailure();
    void ConnectDisconnect();
private slots:
    void ConnectToServer();
    void RandomBattle();
    void MoveSelect(QString move);
signals:
    void DisplayTrainer();
    void RandomFight();
    void DisplayRandomEncounter(QString response);
    void PrintResponse(QString response);
private:
    gameState state;
    EncounterState encounter;
    void DisplayData();
    bool PausedForRespose;
    LoginDialog* dialog;
    MainWindow* main;
    DataStore* store;
    bool connected;
};

#endif // CONTROLLER_H
