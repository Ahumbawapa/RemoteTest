#include "remotecontrolPresenter.h"
#include "remotecontrolview.h"
#include "remoteserver.h"
#include "remoteclient.h"

#include <QtNetwork>
#include <QHostAddress>

RemoteControlPresenter::RemoteControlPresenter(QObject *parent)
    :QObject(parent)
{
    m_View = new RemoteControlView(this);
    m_isServerRoleUnknown = true;

    connect (m_View, &RemoteControlView::serverRoleChanged, this, &RemoteControlPresenter::setIsServer);
    connect (m_View, &RemoteControlView::sendOutputBytes, this, &RemoteControlPresenter::setOutByteArray);

    connect (this, &RemoteControlPresenter::inByteArrayChanged, m_View, &RemoteControlView::onInbyteArrayChanged);

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

QByteArray RemoteControlPresenter::inByteArray() const
{
    return m_inByteArray;
}

void RemoteControlPresenter::setInByteArray(QByteArray inByteArray)
{
    if (m_inByteArray == inByteArray)
        return;

    m_inByteArray = inByteArray;
    emit inByteArrayChanged(m_inByteArray);
}

QByteArray RemoteControlPresenter::outByteArray() const
{
    return m_outByteArray;
}

void RemoteControlPresenter::setOutByteArray(QByteArray outByteArray)
{
    if (m_outByteArray == outByteArray)
        return;

    m_outByteArray = outByteArray;
    emit outByteArrayChanged(m_outByteArray);
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
        if(nullptr != m_remoteClient)
        {
            m_remoteClient->disconnectFromHost();
            m_remoteClient->deleteLater();
        }

        if(nullptr == m_remoteServer)
        {
            m_remoteServer = new RemoteServer(this);

            connect (m_View, &RemoteControlView::hostAddressChanged, m_remoteServer, &RemoteServer::setIpAddress);
            connect (m_View, &RemoteControlView::portChanged, m_remoteServer, &RemoteServer::setPort);

            connect (m_View, &RemoteControlView::onPushbuttonListenOrConnectClicked     , m_remoteServer, &RemoteServer::onListenOrConnect);
            connect (m_View, &RemoteControlView::onPushButtonStopListenOrConnectClicked , m_remoteServer, &RemoteServer::onStopListenOrConnect);

            connect (m_remoteServer, &RemoteServer::serverMessage, m_View, &RemoteControlView::onServerMessage);
            connect (m_remoteServer, &RemoteServer::serverStateChanged, m_View, &RemoteControlView::onConnectionStateChanged);

            connect (this, &RemoteControlPresenter::outByteArrayChanged, m_remoteServer, &RemoteServer::sendOutputBytes);


        }
        else
        {
            ;
        }
    }
    else//false == this->isServer()
    {
        if(nullptr != m_remoteServer)
        {
           m_remoteServer->close();
           m_remoteServer->deleteLater();
        }

        if(nullptr == m_remoteClient)
        {
            m_remoteClient = new RemoteClient(this);

            connect(m_View, &RemoteControlView::hostAddressChanged, m_remoteClient, &RemoteClient::setHostAddress);
            connect(m_View, &RemoteControlView::portChanged, m_remoteClient, &RemoteClient::setPort);

            connect (m_View, &RemoteControlView::onPushbuttonListenOrConnectClicked     , m_remoteClient, &RemoteClient::connectToHost);
            connect (m_View, &RemoteControlView::onPushButtonStopListenOrConnectClicked , m_remoteClient, &RemoteClient::disconnectFromHost);

            connect (m_remoteClient, &RemoteClient::clientMessage, m_View, &RemoteControlView::onClientMessage);
            connect (m_remoteClient, &RemoteClient::socketStateChanged, m_View, &RemoteControlView::onConnectionStateChanged);

            connect (this, &RemoteControlPresenter::outByteArrayChanged, m_remoteClient, &RemoteClient::sendOutputBytes);

        }

    }
}



