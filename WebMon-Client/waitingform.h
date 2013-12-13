#ifndef WAITINGFORM_H
#define WAITINGFORM_H

#include <QWidget>
#include <QLabel>
#include <QMovie>
#include <Structs.h>
namespace Ui {
class WaitingForm;

}

class WaitingForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit WaitingForm(QWidget *parent = 0);
    ~WaitingForm();
    void SetPokemon(int number,PokemonWait pokemon);
    void setGif(QString gif, QLabel *label);
private:
    Ui::WaitingForm *ui;
};

#endif // WAITINGFORM_H
