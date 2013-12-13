#include "controller.h"
#include <QDebug>
#include <QMessageBox>
Controller::Controller(QObject *parent) :
    QObject(parent)
{
    state = Connecting;
    bool connected = false;
    PausedForRespose = false;
}
void Controller::setDialog(LoginDialog* d)
{
 dialog = d;
 connect(dialog,SIGNAL(ConnectSignal()),this,SLOT(ConnectToServer()));
}
void Controller::setData(DataStore *data)
{
 store = data;
 connect(store,SIGNAL(SendDataToController(QString)),SLOT(ServerResponse(QString)));
 connect(store,SIGNAL(connectionDisconnected()),SLOT(ConnectDisconnect()));
 connect(store,SIGNAL(connectionFailure()),SLOT(ConnectFailure()));
 connect(store,SIGNAL(connectionSucessful()),SLOT(ConnectSucessful()));

}
void Controller::ConnectToServer()
{
dialog->setEnabled(false);
QString host = dialog->GetHost();
int port = dialog->GetPort();
QString trainer = dialog->GetTrainerName();
store->Connect(host,port,trainer);
}
void Controller::ServerResponse(QString response)
{
    qDebug() << "Controller Recieved" << response;
    QList<QString> list = response.split(":");

    if(list[0].startsWith("INIT",Qt::CaseInsensitive))
    {
        qDebug() << "Init Pokemon Team";
        QList<QString> pokemon1 = list[1].split("|");
        QList<QString> pokemon2 = list[2].split("|");
        PokemonWait pk1;
        pk1.name = pokemon1[0];
        pk1.info = "";
        for(int i = 1; i < pokemon1.length();i++)
        {
            pk1.info += pokemon1[i];
        }
        PokemonWait pk2;
        pk2.name = pokemon2[0];
        pk2.info = "";
        for(int i = 1; i < pokemon2.length();i++)
        {
            pk2.info += pokemon2[i];
        }

      main->ShowWait(pk1,pk2);
    }
}

void Controller::ConnectDisconnect()
{
qDebug() << "Server Disconnected";
main->close();
dialog->close();
}
void Controller::ConnectFailure()
{
    QMessageBox msg;
    msg.setText("Connection Unsucessful Try Again");
    msg.exec();
    dialog->setEnabled(true);
}
void Controller::ConnectSucessful()
{
dialog->close();
main->setEnabled(true);
}
