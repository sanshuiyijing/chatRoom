/*
  �����һ��������࣬������һ��chatdialog�࣬������������ڡ�֮���Լ��������
  ����Ϊ�����촰�ڹر�ʱ�����ñ�ǣ���MessageWind��ķ���������

  */


#ifndef CHAT_H
#define CHAT_H
#include "chatdialog.h"
#include "data.h"
class Chat:public QObject
{
    Q_OBJECT
public:
    Chat(const Contact&);
    ~Chat();
    bool dialog_have_closed();
    Contact& getcontact();
    void activateWindow();
    void addnewmessage(const QString &,const Message &);
    void close();
    void contatonline();
    void setwhite();
    void setdark();
signals:
    void have_chat_dialog_closed();
private slots:
    void on_chat_dialog_closed();
private:
    ChatDialog chatdialog;
    bool closed;
};

#endif // CHAT_H
