#ifndef BATTLEFORM_H
#define BATTLEFORM_H

#include <QWidget>
#include <QLabel>
#include <QMovie>
#include <QFile>
namespace Ui {
class BattleForm;
}

class BattleForm : public QWidget
{
    Q_OBJECT

public:
    explicit BattleForm(QWidget *parent = 0);
    void setGif(QString gif, QLabel *label);
    ~BattleForm();

private:
    Ui::BattleForm *ui;
};

#endif // BATTLEFORM_H
