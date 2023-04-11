#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>


#define BIND_PORT 12345

const int MSG_BIND_PORT =12346;

class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject *parent = nullptr);
    void InitSocket( void );
    void ReadDatagram( QNetworkDatagram datagram);
    void SendDatagram(QByteArray data );
    void SendMSGDatagram(QByteArray data );


private slots:
    void readPendingDatagrams(void);

public slots:
    void readMSGPendingDatagrams (void);

private:
    QUdpSocket* serviceUdpSocket;
    QUdpSocket* messageUDPSocket;
    const int MSG_BIND_PORT {12346};

signals:
    void sig_sendTimeToGUI(QDateTime data);
    void sig_sendMSGToGUI(const QHostAddress, const int);
};

#endif // UDPWORKER_H
