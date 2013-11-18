#ifndef POKEMON_H
#define POKEMON_H

#include <QObject>

class Pokemon : public QObject
{
    Q_OBJECT
public:
    explicit Pokemon(QObject *parent = 0);
    void getId();
    void setId(QString id);
    void setName(QString name);
    void setMaxHealth(int maxHealth);
    void setCurrentHealth(int currentHealth);
private:
    QString m_id;
    QString m_name;
    QList<QString> m_types;
    int     m_MaxHealth;
    int     m_CurrentHealth;
};

#endif // POKEMON_H
