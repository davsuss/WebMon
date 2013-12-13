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
 void WaitingForm::SetPokemon(int number,PokemonWait pokemon)
 {
     switch(number)
     {
        case(1):
        {
         setGif(path + pokemon.name + "-Back.gif",ui->PokeImage1);
         ui->PokeInfo1->append(pokemon.info);
        break;
        }
        case(2):
        {
         setGif(path + pokemon.name + "-Back.gif",ui->PokeImage2);
         ui->PokeInfo2->append(pokemon.info);
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
