#ifndef DATASTORE_H
#define DATASTORE_H

#include <QObject>
#include <QTcpSocket>
#include "Structs.h"
QT_BEGIN_NAMESPACE
class QTcpSocket;
class QNetworkSession;
QT_END_NAMESPACE
class DataStore : public QObject
{
    Q_OBJECT
public:
    bool Connect(QString host, int Port,QString trainer);
    explicit DataStore(QObject *parent = 0);
    QString getGif(QString pokemon);
    void SendMessage(QString msg);
    void StorePokemon(QList<PokemonInfo>* pk);
    QList<PokemonInfo>* GetPokemon();
signals:
    void connectionSucessful();
    void connectionFailure();
    void connectionDisconnected();
    void SendDataToController(QString data);

private slots:
    void connectSuccess();
    void connectFaliure();
    void connectDisconnected();
    void DataRecieved();


private:
void SendData(QString data);
QString trainer;
QNetworkSession *networkSession;
QTcpSocket * tcpSocket;
QList<PokemonInfo>* m_pk;
};

#endif // DATASTORE_H
