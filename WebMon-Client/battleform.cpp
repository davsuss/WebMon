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
    ui->MoveLayout->setSpacing(0);
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
void BattleForm::SetFriendName(QString name)
{
ui->PokemonFriendName->setText(name);
}
void BattleForm::SetEnemyName(QString name)
{
ui->PokemonEnemyName->setText(name);
}

void BattleForm::setEnemyGif(QString gif)
{
setGif(gif,ui->EnemySprite);
}
void BattleForm::Destroyed()
{
    int i = 0;
}

void BattleForm::setFriendlyMaxHealth(int health)
{
    ui->FriendlyHealth->setRange(0,health);
    ui->FriendlyHealth->setValue(health);
    maxFriendlyHealth = health;
    ui->FriendHP->setText(QString("%1/%1").arg(health));
}

void BattleForm::SetFriendlyHealth(int health)
{
ui->FriendlyHealth->setValue(health);
ui->FriendHP->setText(QString("%1/%2").arg(health).arg(maxFriendlyHealth));
}
void BattleForm::setEnemyMaxHealth(int health)
{
    ui->EnemyHealth->setRange(0,health);
    ui->EnemyHealth->setValue(health);
    MaxEnemyHealth = health;
    ui->EnemyHP->setText(QString("%1/%1").arg(health));
}

void BattleForm::SetEnemyHealth(int health)
{
ui->EnemyHealth->setValue(health);
ui->EnemyHP->setText(QString("%1/%2").arg(health).arg(MaxEnemyHealth));
}
void BattleForm::SendMove()
{
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    QString move = button->text();
    move = move.left(move.lastIndexOf('-'));
    emit MoveSelect(move);
}

void BattleForm::setBackground(QString png)
{

}
void BattleForm::ReSetMoves(QList<QString>moves)
{
    QLayoutItem * child;
    while((child = ui->MoveLayout->takeAt(0)) != 0)
    {
        ui->MoveLayout->removeItem(child);
        delete child->widget();
    }

    int i = 0;
    foreach(QString move, moves)
    {
        QPushButton * btn = new QPushButton();
        btn->setText(move);
       connect(btn,SIGNAL(clicked()),this,SLOT(SendMove()));
       ui->MoveLayout->addWidget(btn,i,0);
       i++;
    }

}

void BattleForm::SetMoves(QList<QString> moves)
{
    int i = 0;
    foreach(QString move, moves)
    {
        QPushButton * btn = new QPushButton();
        btn->setText(move);
       connect(btn,SIGNAL(clicked()),this,SLOT(SendMove()));
       ui->MoveLayout->addWidget(btn,i,0);
       i++;
    }
}
