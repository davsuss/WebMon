#include "waitingform.h"
#include "ui_waitingform.h"
#include <QDebug>
WaitingForm::WaitingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WaitingForm)
{
    ui->setupUi(this);
}

WaitingForm::~WaitingForm()
{
    delete ui;
}
 void WaitingForm::SetPokemon(int number,PokemonInfo pokemon)
 {
     switch(number)
     {
        case(1):
        {
         setGif(path + pokemon.name,ui->PokeImage1);
         ui->PokeInfo1->append(QString("HP:%1").arg(pokemon.hp));
         ui->PokeInfo1->append(QString("Lv:%1").arg(pokemon.level));
         ui->PokeInfo1->append(QString("Exp Left:%1").arg(pokemon.expleft));
         ui->PokeInfo1->append(QString("Move 1:" +pokemon.moves[0]));
         ui->PokeInfo1->append(QString("Move 2:" +pokemon.moves[1]));
        break;
        }
        case(2):
        {
         setGif(path + pokemon.name,ui->PokeImage2);
         ui->PokeInfo2->append(QString("HP:%1").arg(pokemon.hp));
         ui->PokeInfo2->append(QString("Lv:%1").arg(pokemon.level));
         ui->PokeInfo2->append(QString("Exp Left:%1").arg(pokemon.expleft));
         ui->PokeInfo2->append(QString("Move 1:" +pokemon.moves[0]));
         ui->PokeInfo2->append(QString("Move 2:" +pokemon.moves[1]));
        break;
        }
     }
 }
 void WaitingForm::setGif(QString gif, QLabel *label)
 {
     QMovie *movie = new QMovie(gif);
     label->setMovie(movie);
     label->setScaledContents(true);
     movie->start();
 }
