#include "controller.h"
#include <QDebug>
Controller::Controller(QObject *parent) :
    QObject(parent)
{
    state = Connecting;
    PausedForRespose = false;
}
void Controller::Connect(QString host, int Port, QString trainer)
{
    //Getting Initial Data

    PausedForRespose = true;
}
void Controller::ServerResponse(QString response)
{
    qDebug() << "Controller Recieved" << response;
    switch (state)
    {
        case Connecting:
        {
        //Should be new Information about the Trainer
        break;
        }
        case RandomEncounter:
        {
        //Needs a switch statement about the Encounter State
        switch(encounter)
        {
        case PlayerTurn:
        {
        }
        case waiting:
        {
        //We got the info from the server

        }
        }
        break;
        }
    }
}
void Controller::DialogClosed()
{
       QString host = dialog->GetHost();
       QString port = dialog->GetPort();
}
