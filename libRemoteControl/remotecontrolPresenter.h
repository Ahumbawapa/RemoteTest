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
    Q_PROPERTY(QByteArray inByteArray READ inByteArray WRITE setInByteArray NOTIFY inByteArrayChanged)
    Q_PROPERTY(QByteArray outByteArray READ outByteArray WRITE setOutByteArray NOTIFY outByteArrayChanged)

public:
    RemoteControlPresenter(QObject* parent = nullptr);

    bool isServer() const;

    QWidget* getView();

    QByteArray inByteArray() const;
    QByteArray outByteArray() const;


public slots:

    void setIsServer(bool isServer);
    void onServerRoleChanged(bool isServer);
    void setInByteArray(QByteArray inByteArray);
    void setOutByteArray(QByteArray outByteArray);


signals:
    void isServerChanged(bool isServer);
    void inByteArrayChanged(QByteArray inByteArray);
    void outByteArrayChanged(QByteArray outByteArray);


private:
    bool m_isServer;
    bool m_isServerRoleUnknown;

    RemoteControlView* m_View = nullptr;

    RemoteServer* m_remoteServer = nullptr;
    RemoteClient* m_remoteClient = nullptr;

    QByteArray m_inByteArray;
    QByteArray m_outByteArray;
};

#endif // RemoteControlPresenter_H
