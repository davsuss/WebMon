#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    connect(ui->Connect,SIGNAL(clicked()),this,SLOT(ConnectRequested()));
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
QString LoginDialog::GetHost()
{
    return ui->HostLineEdit->text();
}
int LoginDialog::GetPort()
{
    return ui->PortLineEdit->text().toInt();
}
QString LoginDialog::GetTrainerName()
{
    return ui->TrainerLineEdit->text();
}
void LoginDialog::ConnectRequested()
{
    emit ConnectSignal();
}
