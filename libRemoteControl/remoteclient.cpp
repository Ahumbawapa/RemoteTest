#include "remoteclient.h"
#include <QHostAddress>

RemoteClient::RemoteClient(QObject *parent)
    : QObject(parent)
{
    connect(&m_clientConnection, &QTcpSocket::connected, this, &RemoteClient::onConnected);
    connect(&m_clientConnection, &QTcpSocket::readyRead, this, &RemoteClient::onReadyRead);
    connect(&m_clientConnection, &QAbstractSocket::stateChanged, this, &RemoteClient::onStateChanged);
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
}

void RemoteClient::disconnectFromHost()
{
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

        break;

        case QAbstractSocket::ConnectingState:

        break;

        case QAbstractSocket::ConnectedState:

        break;

        case QAbstractSocket::HostLookupState:

        break;

        case QAbstractSocket::ListeningState:

        break;

        case QAbstractSocket::BoundState:

        break;

        case QAbstractSocket::ClosingState:

        break;
    }

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
