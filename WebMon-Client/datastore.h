#ifndef DATASTORE_H
#define DATASTORE_H

#include <QObject>
#include <QTcpSocket>
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
};

#endif // DATASTORE_H
