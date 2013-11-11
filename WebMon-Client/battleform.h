#ifndef BATTLEFORM_H
#define BATTLEFORM_H

#include <QWidget>

namespace Ui {
class BattleForm;
}

class BattleForm : public QWidget
{
    Q_OBJECT

public:
    explicit BattleForm(QWidget *parent = 0);
    ~BattleForm();

private:
    Ui::BattleForm *ui;
};

#endif // BATTLEFORM_H
