#ifndef REMOTESERVER_H
#define REMOTESERVER_H

#include <QObject>
#include <QTcpServer>

class RemoteServer : public QTcpServer
{
    Q_OBJECT

    Q_PROPERTY(QString ipAddress READ ipAddress WRITE setIpAddress NOTIFY ipAddressChanged)
    Q_PROPERTY(quint16 port READ port WRITE setPort NOTIFY portChanged)


public:
    RemoteServer(QObject* parent = Q_NULLPTR);
    ~RemoteServer();

    QString ipAddress() const;
    quint16 port() const;


public slots:
    void setIpAddress(QString ipAddress);
    void setPort(quint16 port);
    void onListenOrConnect();
    void onStopListenOrConnect();

signals:
    void ipAddressChanged(QString ipAddress);
    void portChanged(quint16 port);
    void serverMessage(const QString& errorMessage);
    void connectionError(const QString& errorString);
    void serverStateChanged(QAbstractSocket::SocketState);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void onClientConnectionError(QAbstractSocket::SocketError);

    void onClientReadyRead();
private:
    QString m_ipAddress;
    quint16 m_port;
    QTcpSocket* m_clientConnection = Q_NULLPTR;

};

#endif // REMOTESERVER_H
