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
    connect(ui->pushButtonSendOutputBytes, &QPushButton::clicked, this, &RemoteControlView::onpushButtonSendOutputBytes);
    connect(ui->pushButtonClearLineEditInByte, &QPushButton::clicked, ui->lineEditInByteArray, &QLineEdit::clear);

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
        ui->groupBoxConnectionStatus->setTitle(tr("Serverstatus"));

    }
    else
    {
        ui->comboBoxInterfaces->clear();
        ui->comboBoxInterfaces->setEditable(true);
        ui->comboBoxInterfaces->setEditText(tr("Enter IP-Adresse"));
        ui->pushButtonListenOrConnect->setText(tr("Connect"));
        ui->pushButtonStopListenOrConnection->setText(tr("Disconnect"));
        ui->groupBoxConnectionStatus->setTitle(tr("Clientstatus"));
    }

    ui->groupBoxNetworkParams->setEnabled(true);
    ui->pushButtonStopListenOrConnection->setEnabled(false);

    ui->radioButtonClient->setEnabled(false);
    ui->radioButtonServer->setEnabled(false);

    emit serverRoleChanged(ui->radioButtonServer->isChecked());

}

void RemoteControlView::onServerMessage(const QString &serverMessage)
{
    ui->labelErrorMessages->setText(serverMessage);
}

void RemoteControlView::onClientMessage(const QString &clientMessage)
{
    ui->labelErrorMessages->setText(clientMessage);
}

void RemoteControlView::onConnectionStateChanged(QAbstractSocket::SocketState newSocketState)
{
    switch(newSocketState)
    {
        case QAbstractSocket::UnconnectedState:
            ui->radioButtonUnconnected->setChecked(true);
            ui->pushButtonStopListenOrConnection->setEnabled(false);
            ui->groupBoxDataExchange->setEnabled(false);
        break;

        case QAbstractSocket::ConnectingState:
            ui->radioButtonConnecting->setChecked(true);
            ui->pushButtonStopListenOrConnection->setEnabled(false);
        break;

        case QAbstractSocket::ConnectedState:
            ui->radioButtonConnected->setChecked(true);
            ui->pushButtonStopListenOrConnection->setEnabled(true);
            ui->groupBoxDataExchange->setEnabled(true);
        break;

        case QAbstractSocket::HostLookupState:
            ui->radioButtonHostLookup->setChecked(true);
        break;

        case QAbstractSocket::ListeningState:
            ui->radioButtonListening->setChecked(true);
        break;

        case QAbstractSocket::BoundState:
            ui->radioButtonBound->setChecked(true);
        break;

        case QAbstractSocket::ClosingState:
            ui->radioButtonClosing->setChecked(true);
            ui->groupBoxDataExchange->setEnabled(false);
        break;
    }
}

void RemoteControlView::onInbyteArrayChanged(QByteArray newInByteArray)
{
    if(newInByteArray.size() == 0)
    {
        ui->lineEditInByteArray->setText("");
        return;
    }

    QString byteString;
    for(int index = 0; index != newInByteArray.size(); ++index)
    {
        if(newInByteArray.at(index) & 0x80)
            byteString += '1';
        else
            byteString +=  '0';

        if(newInByteArray.at(index) & 0x40)
            byteString += '1';
        else
            byteString +=  '0';

        if(newInByteArray.at(index) & 0x20)
            byteString += '1';
        else
            byteString +=  '0';

        if(newInByteArray.at(index) & 0x10)
            byteString += '1';
        else
            byteString +=  '0';

        if(newInByteArray.at(index) & 0x08)
            byteString += '1';
        else
            byteString +=  '0';

        if(newInByteArray.at(index) & 0x04)
            byteString += '1';
        else
            byteString +=  '0';

        if(newInByteArray.at(index) & 0x02)
            byteString += '1';
        else
            byteString +=  '0';

        if(newInByteArray.at(index) & 0x01)
            byteString += '1';
        else
            byteString +=  '0';

        byteString += ' ';


    }

    ui->lineEditInByteArray->setText(byteString);
}

void RemoteControlView::onOutbyteArrayChanged(QByteArray newOutByteArray)
{
    if(newOutByteArray.size() == 0)
    {
        ui->lineEditInByteArray->setText("");
        return;
    }

    QString byteString;
    for(int index = 0; index != newOutByteArray.size(); ++index)
    {
        if(newOutByteArray.at(index) & 0x80)
            byteString += '1';
        else
            byteString +=  '0';

        if(newOutByteArray.at(index) & 0x40)
            byteString += '1';
        else
            byteString +=  '0';

        if(newOutByteArray.at(index) & 0x20)
            byteString += '1';
        else
            byteString +=  '0';

        if(newOutByteArray.at(index) & 0x10)
            byteString += '1';
        else
            byteString +=  '0';

        if(newOutByteArray.at(index) & 0x08)
            byteString += '1';
        else
            byteString +=  '0';

        if(newOutByteArray.at(index) & 0x04)
            byteString += '1';
        else
            byteString +=  '0';

        if(newOutByteArray.at(index) & 0x02)
            byteString += '1';
        else
            byteString +=  '0';

        if(newOutByteArray.at(index) & 0x01)
            byteString += '1';
        else
            byteString +=  '0';

        byteString += ' ';


    }

    ui->lineEditOutByteArray->setText(byteString);
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

void RemoteControlView::onpushButtonSendOutputBytes()
{
    QByteArray bytesTosend = ui->lineEditOutByteArray->text().toLocal8Bit();
    emit sendOutputBytes(bytesTosend);
}
