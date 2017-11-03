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
    connect (m_View, &RemoteControlView::objectNameChanged, this, &RemoteControlPresenter::onListenOrConnect);
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
        emit serverError(tr("Server nicht aktiv"));

   }
   else
   {

   }
}


