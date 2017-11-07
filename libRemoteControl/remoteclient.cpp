#include "remoteclient.h"
#include <QHostAddress>

RemoteClient::RemoteClient(QObject *parent)
    : QObject(parent)
{
    connect(&m_clientConnection, &QTcpSocket::connected, this, &RemoteClient::onConnected);
    connect(&m_clientConnection, &QTcpSocket::readyRead, this, &RemoteClient::onReadyRead);
    connect(&m_clientConnection, &QAbstractSocket::stateChanged, this, &RemoteClient::onStateChanged);
    connect(&m_clientConnection, &QAbstractSocket::stateChanged, this, &RemoteClient::socketStateChanged);
    connect(&m_clientConnection, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));

}

QString RemoteClient::hostAddress() const
{
    return m_hostAddress;
}

void RemoteClient::setHostAddress(QString hostAddress)
{
    QHostAddress addressCheck;
    if(false == addressCheck.setAddress(hostAddress))
        return;

    if (m_hostAddress == hostAddress)
        return;

    m_hostAddress = hostAddress;
    emit hostAddressChanged(m_hostAddress);
    emit clientMessage(tr("Host address changed to %1").arg(m_hostAddress));
}

quint16 RemoteClient::port() const
{
    return m_port;
}


void RemoteClient::setPort(quint16 port)
{
    if (m_port == port)
        return;

    m_port = port;
    emit portChanged(m_port);
    emit clientMessage(tr("Port changed to %1").arg(m_port));
}

void RemoteClient::connectToHost()
{
#ifdef LOG_FUNCTION_CALLS
    qDebug() << "void RemoteClient::connectToHost()";
#endif
    emit clientMessage(tr("connect to host..."));
    m_clientConnection.connectToHost(m_hostAddress,m_port);
}

void RemoteClient::disconnectFromHost()
{
#ifdef LOG_FUNCTION_CALLS
    qDebug() << "void RemoteClient::disconnectFromHost()";
#endif
    emit clientMessage(tr("disconnect from host..."));
    m_clientConnection.disconnectFromHost();
}

void RemoteClient::onStateChanged(QAbstractSocket::SocketState newSocketState)
{
#ifdef LOG_FUNCTION_CALLS
    qDebug() << "void RemoteClient::onStateChanged(QAbstractSocket::SocketState newSocketState)";
#endif

    switch(newSocketState)
    {
        case QAbstractSocket::UnconnectedState:
            emit clientMessage(tr("unconnected"));
        break;

        case QAbstractSocket::ConnectingState:
            emit clientMessage(tr("connecting"));
        break;

        case QAbstractSocket::ConnectedState:
            emit clientMessage(tr("connected"));
        break;

        case QAbstractSocket::HostLookupState:
            emit clientMessage(tr("looking up"));
        break;

        case QAbstractSocket::ListeningState:
            emit clientMessage(tr("listening"));
        break;

        case QAbstractSocket::BoundState:
            emit clientMessage(tr("bound"));
        break;

        case QAbstractSocket::ClosingState:
            emit clientMessage(tr("closing connection"));
        break;
    }

}

void RemoteClient::onError(QAbstractSocket::SocketError /*error*/)
{
#ifdef LOG_FUNCTION_CALLS
    qDebug() << "void RemoteClient::onError(QAbstractSocket::SocketError)";
#endif

    emit clientMessage(m_clientConnection.errorString());
}

void RemoteClient::onReadyRead()
{
#ifdef LOG_FUNCTION_CALLS
    qDebug() << "void RemoteClient::onReadyRead()";
#endif
}

void RemoteClient::onConnected()
{
#ifdef LOG_FUNCTION_CALLS
    qDebug() << "void RemoteClient::onConnected()";
#endif
}

void RemoteClient::sendOutputBytes(QByteArray outByteArray)
{
    if(m_clientConnection.state() != QAbstractSocket::ConnectedState)
    {
        emit clientMessage(tr("Keine Clientverbindung. Senden nicht möglich"));
        return;
    }

    emit clientMessage(tr("Sende %1 Byte Daten").arg(outByteArray.size()));
    m_clientConnection.write(outByteArray);

}
