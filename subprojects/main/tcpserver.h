#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QString>
#include <QFile>
#include "serializator.h"
#include "message.h"
#include "tcpclient.h"
#include "Calculator/calculator.h"

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    TcpServer(int nPort, QObject* parent = 0);
    ~TcpServer();
    /*!
     * \brief sendMeesageToClient
     * \param pSocket - сокет клиента в который будут отправляться данные
     * \param data - струкутура с данными
     */
    void sendMeesageToClient(QTcpSocket* pSocket,struct Message data);
    QVector<QTcpSocket*> localClient;
private:
    QTcpSocket *socket;
    struct Message data; //cn
    quint16 m_nNextBlockSize; //хранения длины следующего, полученного от сокета блока
    void sendToClient(QTcpSocket* pSocket,struct Message data);
//    void sendMeesageToClient(QTcpSocket* pSocket,struct Message data);
    void messageProcessing(QTcpSocket* pSocket, struct Message dataProcessing);
    void separationInProblembook(struct Message dataProcessing);


public slots:
    void incomingConnection(qintptr socketDescriptor);;
    void slotReadyRead();

signals:
    void dataReceived(const Message &data, QTcpSocket* pClientSocket);
};

#endif // TCPSERVER_H
