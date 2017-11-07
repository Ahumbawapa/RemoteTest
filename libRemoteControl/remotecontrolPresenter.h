#ifndef RemoteControlPresenter_H
#define RemoteControlPresenter_H

#include "libremotecontrol_global.h"

#include <QtCore>
#include <QTcpSocket>

class RemoteControlView;
class QTcpServer;
class QHostAddress;
class RemoteServer;
class RemoteClient;

class libRemoteControlSHARED_EXPORT RemoteControlPresenter : public QObject
{

    Q_OBJECT

    Q_PROPERTY(bool isServer READ isServer WRITE setIsServer NOTIFY isServerChanged)

public:
    RemoteControlPresenter(QObject* parent = nullptr);

    bool isServer() const;

    QWidget* getView();

public slots:

    void setIsServer(bool isServer);
    void onServerRoleChanged(bool isServer);


signals:
    void isServerChanged(bool isServer);


private:
    bool m_isServer;
    bool m_isServerRoleUnknown;

    RemoteControlView* m_View = nullptr;


    RemoteServer* m_remoteServer = nullptr;
    RemoteClient* m_remoteClient = nullptr;

};

#endif // RemoteControlPresenter_H
