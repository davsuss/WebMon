#include "battleform.h"
#include "ui_battleform.h"

BattleForm::BattleForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BattleForm)
{
    ui->setupUi(this);
}

BattleForm::~BattleForm()
{
    delete ui;
}
