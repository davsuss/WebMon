#ifndef BATTLEFORM_H
#define BATTLEFORM_H
#include <QWidget>
#include "Structs.h"
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
    void SetFriendlyHealth(int health);
    void SetEnemyHealth(int health);
    void setFriendlyGif(QString gif);
    void setEnemyGif(QString gif);
    void setBackground(QString png);
    void SetMoves(QList<QString> moves);
    void setEnemyMaxHealth(int health);
    void setFriendlyMaxHealth(int health);
    void SetFriendName(QString name);
    void SetEnemyName(QString name);
    void ReSetMoves(QList<QString>moves);
private slots:
    void SendMove();
    void Destroyed();
signals:
    void MoveSelect(QString move);

private:
    Ui::BattleForm *ui;
    QLabel * friendly;
    QLabel * enemy;
    int maxFriendlyHealth;
    int MaxEnemyHealth;
};

#endif // BATTLEFORM_H
