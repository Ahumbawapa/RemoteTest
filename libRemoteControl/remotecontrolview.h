#ifndef REMOTECONTROLVIEW_H
#define REMOTECONTROLVIEW_H

#include <QWidget>
#include <libremotecontrol_global.h>
#include <QAbstractSocket>

class RemoteControlPresenter;


namespace Ui {
class RemoteControlView;
}

class libRemoteControlSHARED_EXPORT RemoteControlView : public QWidget
{
    Q_OBJECT

public:
    explicit RemoteControlView(RemoteControlPresenter* presenter, QWidget *parent = 0);
    ~RemoteControlView();

signals:
    void serverRoleChanged(bool isServer);
    void hostAddressChanged(const QString& hostaddress);
    void portChanged(int);
    void onPushbuttonListenOrConnectClicked();
    void onPushButtonStopListenOrConnectClicked();
    void sendOutputBytes(QByteArray newOutBytes);

public slots:
    void onRadiobuttonsServerRoleChanged();
    void onServerMessage(const QString& serverMessage);
    void onClientMessage(const QString& clientMessage);
    void onConnectionStateChanged(QAbstractSocket::SocketState newSocketState);
    void onInbyteArrayChanged(QByteArray newInByteArray);
    void onOutbyteArrayChanged(QByteArray newOutByteArray);
private slots:
    QStringList loadInterfaces();
    void onpushButtonSendOutputBytes();

private:
    Ui::RemoteControlView *ui;

    RemoteControlPresenter* m_Presenter;
};

#endif // REMOTECONTROLVIEW_H
