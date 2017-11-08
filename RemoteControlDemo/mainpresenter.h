#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include <QObject>

class MainWindow;
class RemoteControlPresenter;
class LaserRemoteControlPresenter;

class mainPresenter : public QObject
{
    Q_OBJECT
public:

    mainPresenter(QObject* parent = nullptr);
    QWidget* getView();

private:
    MainWindow* m_View;
    RemoteControlPresenter* m_remoteControlPresenter = nullptr;
    LaserRemoteControlPresenter* m_laserRemoteControlPresenter = nullptr;
};

#endif // MAINPRESENTER_H
