#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QLabel>
#include <QLayout>
#include "battleform.h"
#include <QGridLayout>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QString Host,int Port, QString TrainerName);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setGif(QString gif,QLabel* label);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
