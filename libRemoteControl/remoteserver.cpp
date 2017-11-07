#include "remoteserver.h"
#include <QTcpSocket>

RemoteServer::RemoteServer(QObject *parent)
    :QTcpServer(parent)
{
    setMaxPendingConnections(1);
}

RemoteServer::~RemoteServer()
{
    if(QAbstractSocket::ConnectedState == m_clientConnection->state())
        m_clientConnection->close();
    m_clientConnection->deleteLater();
}

QString RemoteServer::ipAddress() const
{
    return m_ipAddress;
}

void RemoteServer::setIpAddress(QString ipAddress)
{
    QHostAddress hostAddress;
    if(false == hostAddress.setAddress(ipAddress))
            return;

    if (m_ipAddress == ipAddress)
        return;

    m_ipAddress = ipAddress;
    emit ipAddressChanged(m_ipAddress);
}

quint16 RemoteServer::port() const
{
    return m_port;
}

void RemoteServer::setPort(quint16 port)
{
    if (m_port == port)
        return;

    m_port = port;
    emit portChanged(m_port);
}

void RemoteServer::onListenOrConnect()
{
       listen(QHostAddress(m_ipAddress), m_port);

       if(false == isListening())
           emit serverMessage(tr("Server nicht aktiv"));
       else
           emit serverMessage(tr("Listening on %1:%2").arg(serverAddress().toString())
                                                      .arg(QString::number(serverPort())));

}

void RemoteServer::onStopListenOrConnect()
{
#ifdef LOG_FUNCTION_CALLS
    qDebug() << "void RemoteServer::onStopListenOrConnect()";
#endif /*LOG_FUNCTION_CALLS*/


        if(nullptr != m_clientConnection)
        {
            m_clientConnection->disconnectFromHost();
            m_clientConnection->deleteLater();
        }

        close();
        emit serverMessage(tr("Listening stopped..."));
}



void RemoteServer::incomingConnection(qintptr socketDescriptor)
{
    emit serverMessage(tr("Accepting incoming connection..."));

    if(Q_NULLPTR == m_clientConnection)
    {

        m_clientConnection = new QTcpSocket();
        m_clientConnection->setSocketDescriptor(socketDescriptor);
        connect(m_clientConnection, SIGNAL(error(QAbstractSocket::SocketError)), this,  SLOT(onClientConnectionError(QAbstractSocket::SocketError)));
        connect(m_clientConnection, &QTcpSocket::readyRead, this, &RemoteServer::onClientReadyRead);
        connect(m_clientConnection, &QTcpSocket::disconnected, m_clientConnection, &QTcpSocket::deleteLater);
        connect(m_clientConnection, &QTcpSocket::stateChanged, this, &RemoteServer::serverStateChanged);
    }
}

void RemoteServer::onClientConnectionError(QAbstractSocket::SocketError /*clientConnectionError*/)
{
    emit connectionError(m_clientConnection->errorString());
}


void RemoteServer::onClientReadyRead()
{
    QByteArray block;
    block.resize(1);

    quint64 bytesAvailable = m_clientConnection->bytesAvailable();
    quint8 value = 0;

    if(0 == bytesAvailable)
    {
        emit serverMessage(tr("0 Bytes available"));
        return;
    }


    block =  m_clientConnection->readAll();
    value = block.at(0);
    emit serverMessage((tr("Received %1 Bytes: Content: %2").arg(bytesAvailable)
                                                           .arg(value)));


}
