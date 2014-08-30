#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QWidget>
#include "data.h"
#include <QTcpSocket>

namespace Ui {
class ChatDialog;
}

class ChatDialog : public QWidget
{
    Q_OBJECT
    
public:
    explicit ChatDialog(QWidget* parent=0);
    void setcontact(const Contact&);
    Contact& getcontact();   //������ϵ��
    void updatepanel(const QString &,const Message &); //����Ϣ��ӵ��ѷ��ʹ���
    void contactonline(); //����ϵ����������ʱ���ؽ�����
    ~ChatDialog();
    void setwhite();   //���ƶ���ϵ����ʱ��������״̬
    void setdark();
signals:
    void chatfinished();    //�����ڹر�ʱ�����ʹ��ź�
protected:
    virtual void closeEvent (QCloseEvent *);
private slots:
    bool iswhitecontact();  //�ж���ϵ���Ƿ������԰�����
    void sockerror();
    void haveconected();     //�Ѿ�����
    void disconnect();   //���ӶϿ�
    void sendmessage();  // ������Ϣ
private:
    QString createmessage();
    Ui::ChatDialog *ui;
    Contact contact;
    QTcpSocket sender;
    bool couldsend;
};

#endif // CHATDIALOG_H
