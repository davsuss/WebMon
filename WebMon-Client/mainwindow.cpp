#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"
#include "QDebug"
MainWindow::MainWindow(QString Host, int Port, QString TrainerName)
{
    MainWindow(0);
    qDebug() << Host;
    qDebug() << Port;
    qDebug() << TrainerName;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGif("Spr_2c_025.gif",ui->label_2);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new BattleForm());
    ui->BattleGroupBox->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setGif(QString gif, QLabel *label)
{
    QMovie *movie = new QMovie(gif);
    label->setMovie(movie);
    movie->start();
}
