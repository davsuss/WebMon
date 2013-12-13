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
void Controller::setMain(MainWindow *main)
{
    this->main = main;
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
        pk1.info += "HP:" + pokemon1[1] + "\n";
        pk1.info += "Level:" + pokemon1[2] + "\n";
        pk1.info += "Move 1:" + pokemon1[3] + "\n";
        pk1.info += "Move 2:" + pokemon1[4] + "\n";

        PokemonWait pk2;
        pk2.name = pokemon2[0];
        pk2.info = "";
        pk2.info += "HP:" + pokemon2[1] + "\n";
        pk2.info += "Level:" + pokemon2[2] + "\n";
        pk2.info += "Move 1:" + pokemon2[3] + "\n";
        pk2.info += "Move 2:" + pokemon2[4] + "\n";

      main->ShowWait(pk1,pk2);
    }
    else
    {qDebug() << response;}
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
