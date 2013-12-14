#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "waitingform.h"
#include <QMainWindow>
#include <QMovie>
#include <QLabel>
#include <QLayout>
#include "battleform.h"
#include <QGridLayout>
#include "Structs.h"
#include "logindialog.h"


namespace Ui {
class MainWindow;
class Controller;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QString Host,int Port, QString TrainerName);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setGif(QString gif,QLabel* label);
    void SetBattle(PokemonInfo Mine,PokemonInfo enemy);
    void ShowTeam(QList<QString> * list);
    void ShowWait(PokemonInfo pk1, PokemonInfo pk2);
    void SetStatus(QString status);

    void updateBattle(PokemonInfo mine, PokemonInfo enemy);
public slots:
    void RandomBattle();
signals:
    void RandomBattleSignal();
    void MoveSelectSignal(QString move);
private slots:
    void MoveSelect(QString move);
private:
    void ResetBattleForm(QWidget* forum);
    Ui::MainWindow *ui;
    BattleForm * btl;
    WaitingForm* waitingform;

};

#endif // MAINWINDOW_H
