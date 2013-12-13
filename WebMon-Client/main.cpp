#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include "controller.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow;
    Controller c;
    DataStore *data= new DataStore;

    w->show();
    LoginDialog *d = new LoginDialog();
    c.setDialog(d);
    c.setData(data);
    c.setMain(w);
    d->show();
    return a.exec();
}
