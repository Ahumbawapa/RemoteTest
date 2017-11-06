#ifndef RemoteControlPresenter_H
#define RemoteControlPresenter_H

#include "libremotecontrol_global.h"

#include <QtCore>
#include <QTcpSocket>

class RemoteControlView;
class QTcpServer;
class QHostAddress;

class libRemoteControlSHARED_EXPORT RemoteControlPresenter : public QObject
{

    Q_OBJECT

    Q_PROPERTY(bool isServer READ isServer WRITE setIsServer NOTIFY isServerChanged)
    Q_PROPERTY(QString ipAddress READ ipAddress WRITE setIpAddress NOTIFY ipAddressChanged)
    Q_PROPERTY(quint16 port READ port WRITE setPort NOTIFY portChanged)

public:
    RemoteControlPresenter(QObject* parent = nullptr);

    bool isServer() const;
    QString ipAddress() const;
    quint16 port() const;
    QWidget* getView();

public slots:

    void acceptConnection();
    void setIsServer(bool isServer);
    void setIpAddress(QString ipAddress);
    void setPort(quint16 port);
    void onServerRoleChanged(bool isServer);
    void onListenOrConnect();
    void onStopListenOrConnect();

    void getBytes();
signals:
    void isServerChanged(bool isServer);
    void ipAddressChanged(QString ipAddress);
    void portChanged(quint16 port);
    void serverMessage(const QString& errorMessage);

private:
    bool m_isServer;
    bool m_isServerRoleUnknown;

    RemoteControlView* m_View = nullptr;
    QString m_ipAddress;
    QHostAddress* m_hostAddress = nullptr;
    quint16 m_port;
    QTcpServer* m_tcpServer = nullptr;
    QTcpSocket* m_tcpClient = nullptr;
    QTcpSocket* m_tcpServerConnection;
};

#endif // RemoteControlPresenter_H
