#ifndef DATASTORE_H
#define DATASTORE_H

#include <QObject>

class DataStore : public QObject
{
    Q_OBJECT
public:
    void Connect(QString host, int Port,QString trainer);
    explicit DataStore(QObject *parent = 0);
    QString getGif(QString pokemon);



};

#endif // DATASTORE_H
