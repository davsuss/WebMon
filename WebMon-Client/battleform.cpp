#include "battleform.h"
#include "ui_battleform.h"
#include <QPushButton>
QString progress = " QProgressBar {border: 1px solid black;border-bottom-right-radius: 9px;}  QProgressBar::chunk {background-color: #33CC00;width: 20px;}";


BattleForm::BattleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BattleForm)
{
    ui->setupUi(this);
    QPixmap map(background);
    ui->Background->setPixmap(map);
    ui->Background->lower();

    ui->FriendlyHealth->setStyleSheet(progress);
    ui->EnemyHealth->setStyleSheet(progress);
    friendly = ui->FriendlySprite;
    enemy = ui->EnemySprite;
}

BattleForm::~BattleForm()
{
    delete ui;
}
void BattleForm::setGif(QString gif, QLabel *label)
{
    QMovie *movie = new QMovie(gif);
    label->setMovie(movie);
    label->setScaledContents(true);
    movie->start();
}
void BattleForm::setFriendlyGif(QString gif)
{
setGif(gif,ui->FriendlySprite);
}
void BattleForm::setEnemyGif(QString gif)
{
setGif(gif,ui->EnemySprite);
}
void BattleForm::setFriendlyMaxHealth(int health)
{
    ui->FriendlyHealth->setRange(0,health);
    maxFriendlyHealth = health;
    ui->FriendHP->setText(QString(health + '/' + health));
}

void BattleForm::SetFriendlyHealth(int health)
{
ui->FriendlyHealth->setValue(health);
ui->FriendHP->setText(QString(health + '/' + maxFriendlyHealth));
}
void BattleForm::setEnemyMaxHealth(int health)
{
    ui->FriendlyHealth->setRange(0,health);
    MaxEnemyHealth = health;
    ui->EnemyHP->setText(QString(health + '/' + health));
}

void BattleForm::SetEnemyHealth(int health)
{
ui->EnemyHealth->setValue(health);
ui->EnemyHP->setText(QString(health + '/' + MaxEnemyHealth));
}
void BattleForm::setBackground(QString png)
{

}
void BattleForm::SetMoves(QList<QString> moves)
{
    int i = 0;
    foreach(QString move, moves)
    {
        QPushButton * btn = new QPushButton();
        btn->setText(move);
       ui->MoveLayout->addWidget(btn,i,0);
       i++;
    }
}
