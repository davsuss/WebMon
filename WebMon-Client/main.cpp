#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include "controller.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow;
    w->show();
    LoginDialog d;
    d.show();
    return a.exec();
}
