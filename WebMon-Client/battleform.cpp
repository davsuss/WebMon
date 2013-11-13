#include "battleform.h"
#include "ui_battleform.h"

BattleForm::BattleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BattleForm)
{
    ui->setupUi(this);
    QPixmap map;
    ui->Background->lower();
    setGif("004.gif",ui->FriendlySprite);
    setGif("004-back.gif",ui->EnemySprite);
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
