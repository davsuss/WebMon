#include "waitingform.h"
#include "ui_waitingform.h"
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
         ui->PokeInfo1->append("HP:" +pokemon.hp);
         ui->PokeInfo1->append("Lv:" +pokemon.level);
         ui->PokeInfo1->append("Move 1:" +pokemon.moves[0]);
         ui->PokeInfo1->append("Move 2:" +pokemon.moves[1]);
        break;
        }
        case(2):
        {
         setGif(path + pokemon.name,ui->PokeImage2);
         ui->PokeInfo2->append("HP:" +pokemon.hp);
         ui->PokeInfo2->append("Lv:" +pokemon.level);
         ui->PokeInfo2->append("Move 1:" +pokemon.moves[0]);
         ui->PokeInfo2->append("Move 2:" +pokemon.moves[1]);
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
