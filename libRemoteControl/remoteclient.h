#ifndef REMOTECLIENT_H
#define REMOTECLIENT_H

#include <QObject>
#include <QTcpSocket>

class RemoteClient : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString hostAddress READ hostAddress WRITE setHostAddress NOTIFY hostAddressChanged)
    Q_PROPERTY(quint16 port READ port WRITE setPort NOTIFY portChanged)

public:
    explicit RemoteClient(QObject *parent = nullptr);

    QString hostAddress() const;
    quint16 port() const;

signals:
    void socketStateChanged(QAbstractSocket::SocketState);
    void hostAddressChanged(QString hostAddress);
    void portChanged(quint16 port);
    void clientMessage(const QString& message);

public slots:
    void connectToHost();
    void disconnectFromHost();
    void onStateChanged(QAbstractSocket::SocketState newSocketState);
    void setHostAddress(QString hostAddress);
    void setPort(quint16 port);

    void onReadyRead();
    void onConnected();

    void sendOutputBytes(QByteArray outByteArray);
private slots:
    void onError(QAbstractSocket::SocketError);

private:
    QTcpSocket m_clientConnection;
    QString m_hostAddress;
    quint16 m_port;
};

#endif // REMOTECLIENT_H
