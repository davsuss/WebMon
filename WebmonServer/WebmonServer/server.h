#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

class server: public QTcpServer
{
    Q_OBJECT

public:
    server(QObject *parent = 0);

protected:
    void incomingConnection(int socketDescriptor);
};

#endif // SERVER_H
