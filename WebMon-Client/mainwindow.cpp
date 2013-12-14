#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QUrl"
#include "QFile"
#include "QDir"
MainWindow::MainWindow(QString Host, int Port, QString TrainerName)
{
    MainWindow(0);
    qDebug() << Host;
    qDebug() << Port;
    qDebug() << TrainerName;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    btl = new BattleForm();
    waitingform = new WaitingForm();

    setGif("Spr_2c_025.gif",ui->label_2);
    SetStatus("Please Connect to Server");
    //SetBattle("Charmander","Charmander",2,2);
    setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setGif(QString gif, QLabel *label)
{
    QMovie *movie = new QMovie(gif);
    label->setMovie(movie);
    movie->start();
}
void MainWindow::ShowWait(PokemonInfo pk1, PokemonInfo pk2)
{
ResetBattleForm();
QGridLayout * layout = new QGridLayout();
waitingform = new WaitingForm();
layout->addWidget(waitingform);
ui->BattleGroupBox->setLayout(layout);
waitingform->SetPokemon(1,pk1);
waitingform->SetPokemon(2,pk2);
}
void MainWindow::ResetBattleForm()
{
    if(ui->BattleGroupBox->layout() == 0)
        return;

    QLayoutItem * child;
    while((child = ui->BattleGroupBox->layout()->takeAt(0)) != 0)
    {
        ui->BattleGroupBox->layout()->removeItem(child);
        delete child->widget();
    }

    delete ui->BattleGroupBox->layout();
}
void MainWindow::SetStatus(QString status)
{
    ui->Status->setText(status);
}
void MainWindow::SetBattle(QString pokemon1,QList<QString> moves ,QString pokemon2, int Health1, int Health2)
{
    QGridLayout *layout = new QGridLayout;
    ResetBattleForm();
    btl->setFriendlyMaxHealth(Health1);
    btl->setEnemyMaxHealth(Health2);
    btl->setFriendlyGif(path + pokemon2 + ".gif");
    btl->setEnemyGif(path + pokemon2 + "-Back.gif");
    btl->SetMoves(moves);
    layout->addWidget(btl);
    ui->BattleGroupBox->setLayout(layout);
}
void MainWindow::CatchButton()
{

}
void MainWindow::ShowTeam(QList<QString> * list)
{
    for(int i = 0; i < 2; i++)
    {

    }
}
