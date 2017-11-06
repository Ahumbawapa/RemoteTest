#include "RemoteControlPresenter.h"
#include "remotecontrolview.h"

#include <QtNetwork>
#include <QHostAddress>

RemoteControlPresenter::RemoteControlPresenter(QObject *parent)
    :QObject(parent)
{
    m_View = new RemoteControlView(this);
    m_isServerRoleUnknown = true;
    m_hostAddress = new QHostAddress();

    connect (m_View, &RemoteControlView::serverRoleChanged, this, &RemoteControlPresenter::setIsServer);
    connect (m_View, &RemoteControlView::hostAddressChanged, this, &RemoteControlPresenter::setIpAddress);
    connect (m_View, &RemoteControlView::portChanged, this, &RemoteControlPresenter::setPort);
    connect (m_View, &RemoteControlView::onPushbuttonListenOrConnectClicked, this, &RemoteControlPresenter::onListenOrConnect);
    connect (m_View, &RemoteControlView::onPushButtonStopListenOrConnectClicked, this, &RemoteControlPresenter::onStopListenOrConnect);

    connect (this, &RemoteControlPresenter::serverMessage, m_View, &RemoteControlView::onServerError);


}

bool RemoteControlPresenter::isServer() const
{
    return m_isServer;
}

void RemoteControlPresenter::setIsServer(bool isServer)
{
    if(false == m_isServerRoleUnknown)
        if (m_isServer == isServer)
            return;

    m_isServer = isServer;
    m_isServerRoleUnknown = false;

    onServerRoleChanged(m_isServer);
    emit isServerChanged(m_isServer);
}

QString RemoteControlPresenter::ipAddress() const
{
    return m_ipAddress;
}

void RemoteControlPresenter::setIpAddress(QString ipAddress)
{
    if(false == m_hostAddress->setAddress(ipAddress))
            return;

    if (m_ipAddress == ipAddress)
        return;

    m_ipAddress = ipAddress;
    emit ipAddressChanged(m_ipAddress);
}

quint16 RemoteControlPresenter::port() const
{
    return m_port;
}

void RemoteControlPresenter::setPort(quint16 port)
{
    if (m_port == port)
        return;

    m_port = port;
    emit portChanged(m_port);
}

QWidget* RemoteControlPresenter::getView()
{
    return m_View;
}

void RemoteControlPresenter::onServerRoleChanged(bool isServer)
{
    //TcpServer / TcpSocket instanzieren / konfigurieren
    setIsServer(isServer);
    if(this->isServer())
    {
        if(nullptr != m_tcpClient)
        {
            m_tcpClient->disconnectFromHost();
            delete m_tcpClient;
        }

        if(nullptr == m_tcpServer)
        {
            m_tcpServer = new QTcpServer();

            connect(m_tcpServer, &QTcpServer::newConnection, this, &RemoteControlPresenter::acceptConnection);
        }
        else
        {
            if(nullptr != m_tcpServer)
            {

                ;
            }
        }
    }
    else
    {
        ;
    }
}

void RemoteControlPresenter::onListenOrConnect()
{
   if(this->isServer())
   {
       if(nullptr == m_tcpServer)
           return;

       m_tcpServer->listen(QHostAddress(m_ipAddress), m_port);

       if(false == m_tcpServer->isListening())
           emit serverMessage(tr("Server nicht aktiv"));
       else
           emit serverMessage(tr("Listening on %1:%2").arg(m_tcpServer->serverAddress().toString())
                                                      .arg(QString::number(m_tcpServer->serverPort())));

   }
   else
   {

   }
}

void RemoteControlPresenter::onStopListenOrConnect()
{
#ifdef LOG_FUNCTION_CALLS
    qDebug() << "void RemoteControlPresenter::onStopListenOrConnect()";
#endif /*LOG_FUNCTION_CALLS*/
    if(this->isServer())
    {
        if(nullptr == m_tcpServer)
            return;

        m_tcpServerConnection->disconnectFromHost();
        m_tcpServerConnection->deleteLater();

        m_tcpServer->close();
        emit serverMessage(tr("Listening stopped..."));
    }

}

void RemoteControlPresenter::acceptConnection()
{
#ifdef LOG_FUNCTION_CALLS
    qDebug() << "void RemoteControlPresenter::acceptConnection()";
#endif /*LOG_FUNCTION_CALLS*/
    emit serverMessage(tr("Accepting incoming connection..."));

    if(this->isServer() && nullptr != m_tcpServer)
    {
        m_tcpServerConnection = m_tcpServer->nextPendingConnection();
        connect(m_tcpServerConnection, &QTcpSocket::readyRead, this, &RemoteControlPresenter::getBytes);
    }
}

void RemoteControlPresenter::getBytes()
{
    QByteArray block;
    block.resize(1);

    quint64 bytesAvailable = m_tcpServerConnection->bytesAvailable();
    quint8 value = 0;

    if(0 == bytesAvailable)
    {
        emit serverMessage(tr("0 Bytes available"));
        return;
    }


    block =  m_tcpServerConnection->readAll();
    value = block.at(0);
    emit serverMessage((tr("Received %1 Bytes: Content %2").arg(bytesAvailable)
                                                           .arg(value)));


}

