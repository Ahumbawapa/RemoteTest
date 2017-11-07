/********************************************************************************
** Form generated from reading UI file 'remotecontrolview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOTECONTROLVIEW_H
#define UI_REMOTECONTROLVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RemoteControlView
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonClient;
    QRadioButton *radioButtonServer;
    QGroupBox *groupBoxNetworkParams;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBoxInterfaces;
    QLabel *label_2;
    QPushButton *pushButtonStopListenOrConnection;
    QPushButton *pushButtonListenOrConnect;
    QSpinBox *spinBoxPort;
    QLabel *labelErrorMessages;
    QGroupBox *groupBoxConnectionStatus;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButtonConnected;
    QRadioButton *radioButtonConnecting;
    QRadioButton *radioButtonListening;
    QRadioButton *radioButtonUnconnected;
    QRadioButton *radioButtonHostLookup;
    QRadioButton *radioButtonBound;
    QRadioButton *radioButtonClosing;
    QGroupBox *groupBoxDataExchange;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEditInByteArray;
    QPushButton *pushButtonClearLineEditInByte;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEditOutByteArray;
    QPushButton *pushButtonSendOutputBytes;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *RemoteControlView)
    {
        if (RemoteControlView->objectName().isEmpty())
            RemoteControlView->setObjectName(QStringLiteral("RemoteControlView"));
        RemoteControlView->resize(561, 383);
        verticalLayout = new QVBoxLayout(RemoteControlView);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButtonClient = new QRadioButton(RemoteControlView);
        radioButtonClient->setObjectName(QStringLiteral("radioButtonClient"));

        horizontalLayout->addWidget(radioButtonClient);

        radioButtonServer = new QRadioButton(RemoteControlView);
        radioButtonServer->setObjectName(QStringLiteral("radioButtonServer"));

        horizontalLayout->addWidget(radioButtonServer);


        verticalLayout->addLayout(horizontalLayout);

        groupBoxNetworkParams = new QGroupBox(RemoteControlView);
        groupBoxNetworkParams->setObjectName(QStringLiteral("groupBoxNetworkParams"));
        groupBoxNetworkParams->setEnabled(false);
        verticalLayout_2 = new QVBoxLayout(groupBoxNetworkParams);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        label = new QLabel(groupBoxNetworkParams);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBoxInterfaces = new QComboBox(groupBoxNetworkParams);
        comboBoxInterfaces->setObjectName(QStringLiteral("comboBoxInterfaces"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxInterfaces->sizePolicy().hasHeightForWidth());
        comboBoxInterfaces->setSizePolicy(sizePolicy);

        gridLayout->addWidget(comboBoxInterfaces, 0, 2, 1, 1);

        label_2 = new QLabel(groupBoxNetworkParams);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pushButtonStopListenOrConnection = new QPushButton(groupBoxNetworkParams);
        pushButtonStopListenOrConnection->setObjectName(QStringLiteral("pushButtonStopListenOrConnection"));

        gridLayout->addWidget(pushButtonStopListenOrConnection, 2, 2, 1, 1);

        pushButtonListenOrConnect = new QPushButton(groupBoxNetworkParams);
        pushButtonListenOrConnect->setObjectName(QStringLiteral("pushButtonListenOrConnect"));
        sizePolicy.setHeightForWidth(pushButtonListenOrConnect->sizePolicy().hasHeightForWidth());
        pushButtonListenOrConnect->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonListenOrConnect, 2, 0, 1, 1);

        spinBoxPort = new QSpinBox(groupBoxNetworkParams);
        spinBoxPort->setObjectName(QStringLiteral("spinBoxPort"));
        sizePolicy.setHeightForWidth(spinBoxPort->sizePolicy().hasHeightForWidth());
        spinBoxPort->setSizePolicy(sizePolicy);
        spinBoxPort->setMinimum(0);
        spinBoxPort->setMaximum(64000);

        gridLayout->addWidget(spinBoxPort, 1, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout->addWidget(groupBoxNetworkParams);

        labelErrorMessages = new QLabel(RemoteControlView);
        labelErrorMessages->setObjectName(QStringLiteral("labelErrorMessages"));
        labelErrorMessages->setWordWrap(true);

        verticalLayout->addWidget(labelErrorMessages);

        groupBoxConnectionStatus = new QGroupBox(RemoteControlView);
        groupBoxConnectionStatus->setObjectName(QStringLiteral("groupBoxConnectionStatus"));
        groupBoxConnectionStatus->setEnabled(false);
        gridLayout_2 = new QGridLayout(groupBoxConnectionStatus);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        radioButtonConnected = new QRadioButton(groupBoxConnectionStatus);
        radioButtonConnected->setObjectName(QStringLiteral("radioButtonConnected"));

        gridLayout_2->addWidget(radioButtonConnected, 0, 2, 1, 1);

        radioButtonConnecting = new QRadioButton(groupBoxConnectionStatus);
        radioButtonConnecting->setObjectName(QStringLiteral("radioButtonConnecting"));

        gridLayout_2->addWidget(radioButtonConnecting, 0, 1, 1, 1);

        radioButtonListening = new QRadioButton(groupBoxConnectionStatus);
        radioButtonListening->setObjectName(QStringLiteral("radioButtonListening"));

        gridLayout_2->addWidget(radioButtonListening, 0, 7, 1, 1);

        radioButtonUnconnected = new QRadioButton(groupBoxConnectionStatus);
        radioButtonUnconnected->setObjectName(QStringLiteral("radioButtonUnconnected"));

        gridLayout_2->addWidget(radioButtonUnconnected, 0, 0, 1, 1);

        radioButtonHostLookup = new QRadioButton(groupBoxConnectionStatus);
        radioButtonHostLookup->setObjectName(QStringLiteral("radioButtonHostLookup"));

        gridLayout_2->addWidget(radioButtonHostLookup, 1, 0, 1, 1);

        radioButtonBound = new QRadioButton(groupBoxConnectionStatus);
        radioButtonBound->setObjectName(QStringLiteral("radioButtonBound"));

        gridLayout_2->addWidget(radioButtonBound, 1, 1, 1, 1);

        radioButtonClosing = new QRadioButton(groupBoxConnectionStatus);
        radioButtonClosing->setObjectName(QStringLiteral("radioButtonClosing"));

        gridLayout_2->addWidget(radioButtonClosing, 1, 2, 1, 1);


        verticalLayout->addWidget(groupBoxConnectionStatus);

        groupBoxDataExchange = new QGroupBox(RemoteControlView);
        groupBoxDataExchange->setObjectName(QStringLiteral("groupBoxDataExchange"));
        groupBoxDataExchange->setEnabled(false);
        verticalLayout_3 = new QVBoxLayout(groupBoxDataExchange);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBoxDataExchange);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEditInByteArray = new QLineEdit(groupBoxDataExchange);
        lineEditInByteArray->setObjectName(QStringLiteral("lineEditInByteArray"));

        horizontalLayout_2->addWidget(lineEditInByteArray);

        pushButtonClearLineEditInByte = new QPushButton(groupBoxDataExchange);
        pushButtonClearLineEditInByte->setObjectName(QStringLiteral("pushButtonClearLineEditInByte"));

        horizontalLayout_2->addWidget(pushButtonClearLineEditInByte);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(groupBoxDataExchange);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEditOutByteArray = new QLineEdit(groupBoxDataExchange);
        lineEditOutByteArray->setObjectName(QStringLiteral("lineEditOutByteArray"));

        horizontalLayout_3->addWidget(lineEditOutByteArray);

        pushButtonSendOutputBytes = new QPushButton(groupBoxDataExchange);
        pushButtonSendOutputBytes->setObjectName(QStringLiteral("pushButtonSendOutputBytes"));

        horizontalLayout_3->addWidget(pushButtonSendOutputBytes);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(groupBoxDataExchange);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(RemoteControlView);

        QMetaObject::connectSlotsByName(RemoteControlView);
    } // setupUi

    void retranslateUi(QWidget *RemoteControlView)
    {
        RemoteControlView->setWindowTitle(QApplication::translate("RemoteControlView", "Form", Q_NULLPTR));
        radioButtonClient->setText(QApplication::translate("RemoteControlView", "Client", Q_NULLPTR));
        radioButtonServer->setText(QApplication::translate("RemoteControlView", "Server", Q_NULLPTR));
        groupBoxNetworkParams->setTitle(QApplication::translate("RemoteControlView", "Verbindungseinstellungen", Q_NULLPTR));
        label->setText(QApplication::translate("RemoteControlView", "IP Adresse", Q_NULLPTR));
        label_2->setText(QApplication::translate("RemoteControlView", "Port", Q_NULLPTR));
        pushButtonStopListenOrConnection->setText(QApplication::translate("RemoteControlView", "Stop", Q_NULLPTR));
        pushButtonListenOrConnect->setText(QApplication::translate("RemoteControlView", "Listen / Connect", Q_NULLPTR));
        labelErrorMessages->setText(QString());
        groupBoxConnectionStatus->setTitle(QApplication::translate("RemoteControlView", "Verbindungsstatus", Q_NULLPTR));
        radioButtonConnected->setText(QApplication::translate("RemoteControlView", "Connected", Q_NULLPTR));
        radioButtonConnecting->setText(QApplication::translate("RemoteControlView", "Connecting", Q_NULLPTR));
        radioButtonListening->setText(QApplication::translate("RemoteControlView", "Listening", Q_NULLPTR));
        radioButtonUnconnected->setText(QApplication::translate("RemoteControlView", "Unconnected", Q_NULLPTR));
        radioButtonHostLookup->setText(QApplication::translate("RemoteControlView", "HostLookup", Q_NULLPTR));
        radioButtonBound->setText(QApplication::translate("RemoteControlView", "Bound", Q_NULLPTR));
        radioButtonClosing->setText(QApplication::translate("RemoteControlView", "Closing", Q_NULLPTR));
        groupBoxDataExchange->setTitle(QApplication::translate("RemoteControlView", "Sende- / Empfangstest", Q_NULLPTR));
        label_3->setText(QApplication::translate("RemoteControlView", "Eingangsbytes:", Q_NULLPTR));
        pushButtonClearLineEditInByte->setText(QApplication::translate("RemoteControlView", "L\303\266schen", Q_NULLPTR));
        label_4->setText(QApplication::translate("RemoteControlView", "Ausgangsbytes:", Q_NULLPTR));
        pushButtonSendOutputBytes->setText(QApplication::translate("RemoteControlView", "Senden", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RemoteControlView: public Ui_RemoteControlView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTECONTROLVIEW_H
