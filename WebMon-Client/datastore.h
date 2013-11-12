#ifndef DATASTORE_H
#define DATASTORE_H

#include <QObject>

class DataStore : public QObject
{
    Q_OBJECT
public:
    explicit DataStore(QObject *parent = 0);

signals:
    QString getGif(QString pokemon);
public slots:

};

#endif // DATASTORE_H
