#include "mainpresenter.h"
#include "mainwindow.h"
#include "remotecontrolPresenter.h"
#include "laserremotecontrolpresenter.h"
#include "remotecontrolview.h"
#include "ui_mainwindow.h"


mainPresenter::mainPresenter(QObject *parent)
    :QObject(parent)
{
    m_View = new MainWindow();

    m_remoteControlPresenter = new RemoteControlPresenter(this);
    m_laserRemoteControlPresenter = new LaserRemoteControlPresenter(this);

    connect(    m_laserRemoteControlPresenter,  &LaserRemoteControlPresenter::outByteArrayChanged
              , m_remoteControlPresenter,       &RemoteControlPresenter::setOutByteArray);


    m_View->ui->tabWidgetMain->clear();

    delete m_View->ui->tab;
    delete m_View->ui->tab_2;

    m_View->ui->tabWidgetMain->addTab(m_remoteControlPresenter->getView(), tr("Remote Control"));
    m_View->ui->tabWidgetMain->addTab(m_laserRemoteControlPresenter->getView(), tr("Laser Remote Control"));


}

QWidget* mainPresenter::getView()
{
    return m_View;
}
