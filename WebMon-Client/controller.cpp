#include "controller.h"
#include <QDebug>
#include <QMessageBox>
Controller::Controller(QObject *parent) :
    QObject(parent)
{
    state = Connecting;
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
    connect(main,SIGNAL(RandomBattleSignal()),this,SLOT(RandomBattle()));
    connect(main,SIGNAL(MoveSelectSignal(QString)),this,SLOT(MoveSelect(QString)));
}
void Controller::MoveSelect(QString move)
{
    move = move.left(move.lastIndexOf("-"));
    move = move.replace("-"," ");
    store->SendMessage("Move:" + move);
}

void Controller::RandomBattle()
{
QList<PokemonInfo>* pk = store->GetPokemon();
int randomint = qrand() % 2;
if(randomint == 1)
{
    store->SendMessage("Start Random Encounter:" +(*pk).at(1).name);
}
else
{
   store->SendMessage("Start Random Encounter:" +(*pk).at(0).name);
}

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
    QList<PokemonInfo>* pk = new QList<PokemonInfo>;
    if(list[0].startsWith("INIT",Qt::CaseInsensitive))
    {
        qDebug() << "Init Pokemon Team";
        QList<QString> pokemon1 = list[1].split("|");
        QList<QString> pokemon2 = list[2].split("|");
        PokemonInfo pk1;
        pk1.name = pokemon1[0];
        pk1.expleft = pokemon1[1].toInt();
        pk1.level = pokemon1[2].toInt();
        pk1.hp = pokemon1[3].toInt();
        pk1.moves.append(pokemon1[4]);
        pk1.moves.append(pokemon1[5]);
        pk->append(pk1);
        PokemonInfo pk2;
        pk2.name = pokemon2[0];
        pk2.expleft = pokemon2[1].toInt();
        pk2.level = pokemon2[2].toInt();
        pk2.hp = pokemon2[3].toInt();
        pk2.moves.append(pokemon2[4]);
        pk2.moves.append(pokemon2[5]);
        pk->append(pk2);
      store->StorePokemon(pk);
      main->ShowWait(pk1,pk2);
    }
    else if(list[0].startsWith("StartRandomEncounter",Qt::CaseInsensitive))
    {
        qDebug() << "Server: Starting Random Encounter";
        QList<QString> pokemon1 = list[1].split("|");
        QList<QString> pokemon2 = list[2].split("|");
        PokemonInfo pk1;
        pk1.name = pokemon1[0];
        pk1.expleft = pokemon1[1].toInt();
        pk1.level = pokemon1[2].toInt();
        pk1.hp = pokemon1[3].toInt();
        pk1.moves.append(pokemon1[4]);
        pk1.moves.append(pokemon1[5]);

        PokemonInfo pk2;
        pk2.name = pokemon2[0];
        pk2.expleft = pokemon2[1].toInt();
        pk2.level = pokemon2[2].toInt();
        pk2.hp = pokemon2[3].toInt();
        pk2.moves.append(pokemon2[4]);
        pk2.moves.append(pokemon2[5]);
        main->SetBattle(pk1,pk2);


    }
    else if(list[0].startsWith("MoveResult",Qt::CaseInsensitive))
    {
        //Controller Recieved "MoveResult:Friend|Vulpix|2375|0|4|Ember-Fire-24|Flamethrower-Fire-25:Enemy|Vulpix|125|0|7|Ember-Fire-25|Fire Blast-Fire-4:6:3:Ember:Fire Blast"
        qDebug() << "Move Result";
        QString status = "";
        int friendlyDamage;
        int enemyDamage;
        QString friendlyattack;
        QString enemyattack;
        PokemonInfo friendly;
        PokemonInfo enemy;
        bool friendlyfirst= false;
        QList<QString> PokemonFirst = list[1].split("|");
        QList<QString> PokemonSecond = list[2].split("|");
        if(PokemonFirst[0].startsWith("Friend",Qt::CaseInsensitive))
        {
            friendlyfirst = true;
            friendly.name = PokemonFirst[1];
            friendly.expleft = PokemonFirst[2].toInt();
            friendly.level = PokemonFirst[3].toInt();
            friendly.hp = PokemonFirst[4].toInt();
            friendly.moves.append(PokemonFirst[5]);
            friendly.moves.append(PokemonFirst[6]);
        }
        else
        {
            enemy.name = PokemonFirst[1];
            enemy.expleft = PokemonFirst[2].toInt();
            enemy.level = PokemonFirst[3].toInt();
            enemy.hp = PokemonFirst[4].toInt();
            enemy.moves.append(PokemonFirst[5]);
            enemy.moves.append(PokemonFirst[6]);
        }

        if(friendlyfirst)
        {
            enemy.name = PokemonSecond[1];
            enemy.expleft = PokemonSecond[2].toInt();
            enemy.level = PokemonSecond[3].toInt();
            enemy.hp = PokemonSecond[4].toInt();
            enemy.moves.append(PokemonSecond[5]);
            enemy.moves.append(PokemonSecond[6]);
        }
        else
        {
            friendlyfirst = true;
            friendly.name = PokemonSecond[1];
            friendly.expleft = PokemonSecond[2].toInt();
            friendly.level = PokemonSecond[3].toInt();
            friendly.hp = PokemonSecond[4].toInt();
            friendly.moves.append(PokemonSecond[5]);
            friendly.moves.append(PokemonSecond[6]);
        }
        enemyDamage = list[3].toInt();
        friendlyDamage = list[4].toInt();
        friendlyattack = list[5];
        enemyattack = list[6];
        QString yourstatus= QString("Your %1 used %2 and did %3 damage.").arg(friendly.name).arg(friendlyattack).arg(friendlyDamage);
        QString enemystatus= QString("The Enemy %1 used %2 and did %3 damage.").arg(enemy.name).arg(enemyattack).arg(enemyDamage);

        if(friendlyfirst)
        {
            status += yourstatus + enemystatus;
        }
        else
        {
            status += enemystatus + yourstatus;
        }
        main->SetStatus(status);
        main->updateBattle(friendly,enemy);





    }
    else if(list[0].startsWith("Won",Qt::CaseInsensitive))
    {
        qDebug() << "You WON!!!!!";
        main->SetStatus("You Won!!");
        QList<QString> pokemon1 = list[2].split("|");
        QList<QString> pokemon2 = list[3].split("|");
        PokemonInfo pk1;
        pk1.name = pokemon1[0];
        pk1.expleft = pokemon1[1].toInt();
        pk1.level = pokemon1[2].toInt();
        pk1.hp = pokemon1[3].toInt();
        pk1.moves.append(pokemon1[4]);
        pk1.moves.append(pokemon1[5]);
        pk->append(pk1);
        PokemonInfo pk2;
        pk2.name = pokemon2[0];
        pk2.expleft = pokemon2[1].toInt();
        pk2.level = pokemon2[2].toInt();
        pk2.hp = pokemon2[3].toInt();
        pk2.moves.append(pokemon2[4]);
        pk2.moves.append(pokemon2[5]);
        pk->append(pk2);
      store->StorePokemon(pk);

      main->ShowWait(pk1,pk2);
    }
    else if(list[0].startsWith("Lost",Qt::CaseInsensitive))
    {
       main->SetStatus("You Lost!!");

       QList<QString> pokemon1 = list[2].split("|");
       QList<QString> pokemon2 = list[3].split("|");
       PokemonInfo pk1;
       pk1.name = pokemon1[0];
       pk1.expleft = pokemon1[1].toInt();
       pk1.level = pokemon1[2].toInt();
       pk1.hp = pokemon1[3].toInt();
       pk1.moves.append(pokemon1[4]);
       pk1.moves.append(pokemon1[5]);
       pk->append(pk1);
       PokemonInfo pk2;
       pk2.name = pokemon2[0];
       pk2.expleft = pokemon2[1].toInt();
       pk2.level = pokemon2[2].toInt();
       pk2.hp = pokemon2[3].toInt();
       pk2.moves.append(pokemon2[4]);
       pk2.moves.append(pokemon2[5]);
       pk->append(pk2);
     store->StorePokemon(pk);

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
