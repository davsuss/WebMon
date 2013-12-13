#include "server.h"

server::server(QObject *parent) : QTcpServer(parent)
{
    if( !connectToDB() )
    {
        qDebug() << "Quitting, unable to connect to database";
    }
}

void server::incomingConnection(int socketDescriptor)
{
    qDebug() << "Connecting in Thread: " << QThread::currentThread();
    // create client representative
    tStruct peer;

    // new client
    peer.trainerOBJ = new trainer();
    // create thread
    peer.thread = new QThread();
     // move client to his own thread
    peer.trainerOBJ->moveToThread(peer.thread);

    // make sure when client ends to quit the thread
    QObject::connect(peer.trainerOBJ, SIGNAL(endConnection(QString)), this, SLOT(endThread(QString)));
    QObject::connect(peer.thread, SIGNAL(finished()), peer.trainerOBJ, SLOT(deleteLater()));
    QObject::connect(peer.trainerOBJ, SIGNAL(destroyed()), peer.thread, SLOT(deleteLater()));
    QObject::connect(peer.thread, SIGNAL(destroyed()), this, SLOT(ThreadDestroyed()));

    // start thread
    QString id = QString::number(this->m_clients.size());
    peer.thread->start();
    // invoke init
    QMetaObject::invokeMethod(peer.trainerOBJ,
                              "init", Qt::BlockingQueuedConnection,
                              Q_ARG(int, socketDescriptor),
                              Q_ARG(QString, id));
    // insert peer into qMAP
    this->m_clients.insert(id, peer);
}

void server::endThread(QString threadID)
{
    QThread *thread = m_clients[threadID].thread; // get corresponding thread
    if( thread != NULL )thread->quit(); // stop thread = will also delete client when thread has finished
    m_clients.remove(threadID); // remove from list of clients
}

void server::EndThreads()
{
    foreach( tStruct rep, m_clients )
    {
        rep.thread->quit();
    }
    m_clients.clear();
}

void server::ThreadDestroyed()
{
    qDebug() << "Thread is being destroyed!";
}
