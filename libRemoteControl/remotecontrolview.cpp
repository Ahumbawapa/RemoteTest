#include "remotecontrolview.h"
#include "ui_remotecontrolview.h"
#include "remotecontrolPresenter.h"

#include <QtNetwork>
#include <QStringList>




RemoteControlView::RemoteControlView(RemoteControlPresenter *presenter, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RemoteControlView)
{
    ui->setupUi(this);

    m_Presenter = presenter;

    connect(ui->radioButtonClient, &QRadioButton::clicked, this, &RemoteControlView::onRadiobuttonsServerRoleChanged);
    connect(ui->radioButtonServer, &QRadioButton::clicked, this, &RemoteControlView::onRadiobuttonsServerRoleChanged);
    connect(ui->comboBoxInterfaces, &QComboBox::currentTextChanged, this, &RemoteControlView::hostAddressChanged);
    connect(ui->spinBoxPort, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &RemoteControlView::portChanged);
    connect(ui->pushButtonListenOrConnect, &QPushButton::clicked, this, &RemoteControlView::onPushbuttonListenOrConnectClicked);
    connect(ui->pushButtonStopListenOrConnection, &QPushButton::clicked, this, &RemoteControlView::onPushButtonStopListenOrConnectClicked);

}

RemoteControlView::~RemoteControlView()
{
    delete ui;
}

void RemoteControlView::onRadiobuttonsServerRoleChanged()
{
    if(ui->radioButtonServer->isChecked())
    {
        QStringList interfaces = loadInterfaces();
        ui->comboBoxInterfaces->addItems(interfaces);
        ui->pushButtonListenOrConnect->setText(tr("Listen"));
        ui->pushButtonStopListenOrConnection->setText(tr("Stop Listening"));

    }
    else
    {
        ui->comboBoxInterfaces->clear();
        ui->comboBoxInterfaces->setEditable(true);
        ui->comboBoxInterfaces->setEditText(tr("Enter IP-Adresse"));
        ui->pushButtonListenOrConnect->setText(tr("Connect"));
        ui->pushButtonStopListenOrConnection->setText(tr("Disconnect"));
    }

    ui->groupBoxNetworkParams->setEnabled(true);

    ui->radioButtonClient->setEnabled(false);
    ui->radioButtonServer->setEnabled(false);

    emit serverRoleChanged(ui->radioButtonServer->isChecked());

}

void RemoteControlView::onServerError(const QString &errorMessage)
{
    ui->labelErrorMessages->setText(errorMessage);
}

QStringList RemoteControlView::loadInterfaces()
{
    QList<QHostAddress> interfaces = QNetworkInterface::allAddresses();

    QStringList interfaceNames;

    for(int index = 0; index != interfaces.count(); ++index)
        interfaceNames << interfaces.at(index).toString();

    interfaceNames.insert(0,tr("Select network interface"));

    return interfaceNames;

}


