#include "datastore.h"
#include <QtNetwork>
DataStore::DataStore(QObject *parent) :
    QObject(parent)
{
    // find out which IP to connect to
       QString ipAddress;
       QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
       // use the first non-localhost IPv4 address
       for (int i = 0; i < ipAddressesList.size(); ++i) {
           if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
               ipAddressesList.at(i).toIPv4Address()) {
               ipAddress = ipAddressesList.at(i).toString();
               break;
           }
       }
       // if we did not find one, use IPv4 localhost
       if (ipAddress.isEmpty())
           ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
tcpSocket = new QTcpSocket(this);
connect(tcpSocket, SIGNAL(readyRead()),this,SLOT(DataRecieved()));
connect(tcpSocket, SIGNAL(connected()), this, SLOT(connectSuccess()));
connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(connectFaliure()));
connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(connectDisconnected()));
QNetworkConfigurationManager manager;
   if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
       // Get saved network configuration
       QSettings settings(QSettings::UserScope, QLatin1String("Trolltech"));
       settings.beginGroup(QLatin1String("QtNetwork"));
       const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
       settings.endGroup();

       // If the saved network configuration is not currently discovered use the system default
       QNetworkConfiguration config = manager.configurationFromIdentifier(id);
       if ((config.state() & QNetworkConfiguration::Discovered) !=
           QNetworkConfiguration::Discovered) {
           config = manager.defaultConfiguration();
       }


        networkSession = new QNetworkSession(config, this);
       networkSession->open();

     }

}
void DataStore::connectFaliure()
{
emit connectionFailure();
}
void DataStore::connectDisconnected()
{
emit connectionDisconnected();
}
void DataStore::StorePokemon(QList<PokemonInfo> *pk)
{
    m_pk = pk;
}
QList<PokemonInfo>* DataStore::GetPokemon()
{
    return m_pk;
}

void DataStore::SendMessage(QString msg)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);

    out << (quint16)0;
    out << tr(msg.toStdString().c_str());
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    tcpSocket->write(block);
    emit connectionSucessful();
}

void DataStore::connectSuccess()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);

    out << (quint16)0;
    out << tr(QString("build:"+trainer).toStdString().c_str());
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    tcpSocket->write(block);
    emit connectionSucessful();
}
bool DataStore::Connect(QString host, int Port, QString trainer)
{
    tcpSocket->abort();
    tcpSocket->connectToHost(host,Port);
    this->trainer = trainer;

}
void DataStore::DataRecieved()
{
    QDataStream in(tcpSocket);

    quint16 blockSize;
       in.setVersion(QDataStream::Qt_4_0);
           in >> blockSize;

    QString nextFortune;
    in >> nextFortune;
    emit SendDataToController(nextFortune);
}
