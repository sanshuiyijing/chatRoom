/*
  ����һ���ͻ��࣬���ڴ�socket��ȡ��Ϣ�������ɶ��ţ����������ɳɹ��󣬸ı��Լ���״̬��
  �����ź�havereadmessage()֪ͨ���� �ⲿ��������ȡ����
  */


#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H
#include <QTcpSocket>
#include "data.h"
#include <QString>
#include <QList>
class ClientSocket : public QObject
{
    Q_OBJECT
public:
    ClientSocket(QTcpSocket *);
    ~ClientSocket();
    bool haveread();   //��Ϣ�Ƿ����
    bool haveclosed(); //�����Ƿ�Ͽ�
    QList<Message> * getSms();      //��ȡ��Ϣ
signals:
    void havereadmessage();   //֪ͨ�ⲿ��������ȡ����
    void haveclientclosed();
private slots:
    void readmessage();      //��ȡ��Ϣ
    void clientclosed();
private:
    void createSms(const QString &);//���ɶ���
    bool readstate;              //��־��ǰ״̬
    bool socketclosed;
    QList<Message> smsset;             //����������ݣ����ⲿ������ȡ
    QTcpSocket *socket;
    quint16 blocksizereceive;
};

#endif // CLIENTSOCKET_H
