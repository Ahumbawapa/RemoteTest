#ifndef REMOTECONTROLVIEW_H
#define REMOTECONTROLVIEW_H

#include <QWidget>
#include <libremotecontrol_global.h>

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
    void onPushbuttonListenOrConnectClicked();

public slots:
    void onRadiobuttonsServerRoleChanged();

private slots:
    QStringList loadInterfaces();

private:
    Ui::RemoteControlView *ui;

    RemoteControlPresenter* m_Presenter;
};

#endif // REMOTECONTROLVIEW_H
