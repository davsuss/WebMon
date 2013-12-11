#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "mainwindow.h"
#include <QObject>
typedef enum {EnemyTurn,PlayerTurn,INIT,waiting} EncounterState;
typedef enum {Connecting,RandomEncounter,Challenge,Waiting} gameState;
class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(MainWindow * window);
    explicit Controller(QObject *parent = 0);
public slots:
    void Connect(QString host, int Port,QString trainer);
    void ServerResponse(QString response);
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


};

#endif // CONTROLLER_H
