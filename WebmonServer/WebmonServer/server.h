#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QThread>
#include "trainer.h"
#include "databaseConversation.h"

class server: public QTcpServer
{
    Q_OBJECT

public:
    server(QObject *parent = 0);


protected:
    void incomingConnection(int socketDescriptor);

public slots:
    /**
     * slot invoked when the thread needs to be quited
     */
    void endThread(QString threadID);
    /**
     * to print when a thread is destroyed
     */
    void ThreadDestroyed();
    /**
     * invoked by dialogue to end any running threads
     */
    void EndThreads();

private:
    struct tStruct
    {
        QThread *thread; /**< thread for the client */
        trainer *trainerOBJ; /**< client representation on the server side */
    };
    QMap<QString, tStruct> m_clients; /**< map of al the clients connected */
};

#endif // SERVER_H
