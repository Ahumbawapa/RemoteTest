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
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *RemoteControlView)
    {
        if (RemoteControlView->objectName().isEmpty())
            RemoteControlView->setObjectName(QStringLiteral("RemoteControlView"));
        RemoteControlView->resize(561, 357);
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
        groupBoxNetworkParams->setTitle(QApplication::translate("RemoteControlView", "GroupBox", Q_NULLPTR));
        label->setText(QApplication::translate("RemoteControlView", "IP Adresse", Q_NULLPTR));
        label_2->setText(QApplication::translate("RemoteControlView", "Port", Q_NULLPTR));
        pushButtonStopListenOrConnection->setText(QApplication::translate("RemoteControlView", "Stop", Q_NULLPTR));
        pushButtonListenOrConnect->setText(QApplication::translate("RemoteControlView", "Listen / Connect", Q_NULLPTR));
        labelErrorMessages->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RemoteControlView: public Ui_RemoteControlView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTECONTROLVIEW_H
