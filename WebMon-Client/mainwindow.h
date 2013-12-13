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
    void SetBattle(QString pokemon1,QString pokemon2,int Heath1,int Health2);
    void ShowTeam(QList<QString> * list);
    void ShowWait(PokemonWait pk1, PokemonWait pk2);
    void SetStatus(QString status);

public slots:
    void CatchButton();
private:
    void ResetBattleForm();
    Ui::MainWindow *ui;
    BattleForm * btl;
    WaitingForm* waitingform;

};

#endif // MAINWINDOW_H
