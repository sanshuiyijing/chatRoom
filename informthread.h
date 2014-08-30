/*

  �����һ�����̡߳����ڷ������ߵ���Ϣ��������ʱ�������к��ѷ���������Ϣ������ʱ�����������ߺ��ѷ���������Ϣ

  */


#ifndef INFROMTHREAD_H
#define INFORMTHREAD_H
#include<QTcpSocket>
#include<QList>
#include<QThread>
#include "data.h"

class InformThread:public QThread
{
    Q_OBJECT
public:
    InformThread(QObject *parent=0);
    ~InformThread();
    void run();
    void setoffline();
private:
    void sendto(const Contact&);
    void sendmessage(const QString &);
    QString createmessage();
    QTcpSocket *sender;
    bool exit;
    QString flags;
};

#endif // INFORMTHREAD_H
