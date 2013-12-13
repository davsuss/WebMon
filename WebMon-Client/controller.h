#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "mainwindow.h"
#include "logindialog.h"
#include "Structs.h"
#include <QObject>
typedef enum {PlayerTurn,waiting} EncounterState;
typedef enum {Connecting,RandomEncounter,Challenge,Waiting} gameState;

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
public slots:
    void Connect(QString host, int Port,QString trainer);
    void ServerResponse(QString response);
private slots:
    void DialogClosed();
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
};

#endif // CONTROLLER_H
