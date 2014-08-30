#ifndef MESSAGEWIND_H
#define MESSAGEWIND_H

#include <QMainWindow>
#include <QTimer>
#include <QTreeWidgetItem>
#include "informthread.h"
#include <QList>
#include "data.h"
#include <QTcpSocket>
#include <QTcpServer>
#include "clientsocket.h"
#include "parentblink.h"
#include "childblink.h"
#include "chat.h"
namespace Ui {
class MessageWind;
}

class MessageWind : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MessageWind(QWidget *parent = 0);
    ~MessageWind();
signals:
    void newSms();   //���յ�����Ϣ��֪ͨ�����������б�Ҫ�ĸ���
private slots:
    void DoubleClicked(QTreeWidgetItem *,int);  //˫����ϵ���б������Ŀʱ
    void Collapsed(QTreeWidgetItem *);        //�ڵ�����ʱ���ã�����ʱ���ڵ���˸��
    void Expanded(QTreeWidgetItem*);          //չ��ʱ�ӽڵ���˸�����ڵ�ֹͣ��˸

    //////////////////////////////////////////
    void havenewSms(); //������ClientSocket���havereadmessage()�ź����ӣ���ȡ�µĶ���
    void haveclientclosed();  //���пͻ����ӶϿ�ʱ���ã�����ɾ�����Ͽ��Ŀͻ�����
    void havechatdialogclosed(); //�������촰�ڹر�ʱ�������ѹرյ����촰��
    void receiveBoxButtonClicked();  //��ʾ�ռ���
    void writeButtonClicked();//��������Ϣ
    void sendBoxButtonClicked(); //��ʾ������
    void draftBoxButtonClicked(); //��ʾ�ݸ���
    void settingButtonClicked(); //��ʾ�������
    void newclient();         //�����µ�TCP����
    void on_action_Add_triggered();  //�������ϵ��

    void on_action_Edit_triggered();  //�༭��ϵ��

    void on_action_Move_to_dark_triggered(); //�ƶ���ϵ�˵�������

    void on_action_Move_to_white_triggered(); //�ƶ���ϵ�˵�������

    void on_action_Delete_triggered();        //ɾ����ϵ��

    void on_action_Send_Message_triggered();   //����Ϣ

    void on_action_Find_triggered();         //������ϵ��

protected:
    virtual void contextMenuEvent (QContextMenuEvent *);//�Ҽ��˵�
    virtual void	closeEvent (QCloseEvent *);    //�ر�������ʱ��������д���ļ�
private:
    void init();         //��ʼ������ͷ���������Ϣ
    void update();          //����������
    Contact* indexofcontact(const QString&,QList<Contact> **contactlist=NULL,int *index=NULL);
    bool chatdialogexist(const Contact&,Chat **);   //���촰���Ѿ�����
    void addchildblink(QTreeWidgetItem *);          //�õ�ǰ��ϵ����˸
    void contact_online(const QString &,bool);      //�յ���ϵ�����ߵ���Ϣʱ����ʾ��ϵ������
    void contact_offline(const QString &);          //�յ���ϵ�˵�������Ϣʱ����ʾ��ϵ������
    Contact texttocontact(const QString&);          //��ȡ�ı��е���ϵ����Ϣ
    void initserver();                      //��ʼ��������
    void insertSms(Message);          //���ݶ��ź���Ͷ������ݣ����˶��ű��浽���ʵļ�����
    QString getmyownnumber();     //��ȡ���Լ��ĺ���
    void sendmessage(const QString &,const QString &); //�յ���ϵ�˵�������Ϣʱ��������Ӧ��Ϣ
    int totalunreadsms();        //δ�����ŵĸ���
    int totalunreadrubishsms();        //δ���������ŵĸ���
    void newblinkparent(QTreeWidgetItem*);  //�����ӽڵ���˸ʱ���жϸ��ڵ��Ƿ���˸
    QTreeWidgetItem* finditem(const QString &);  //���ݺ�����Ҷ�Ӧ�Ķ���

    Ui::MessageWind *ui;
    QList<ChildBlink*> childBlinkItems;     //�ӽڵ���˸����
    QList<ParentBlink*> parentBlinkItems;    //���ڵ���˸����
    InformThread informer;                 //֪ͨ�̣߳�����֪ͨ���ߺ����ߺ�ˢ����ϵ���б�
    QTcpServer *server;    //�����������ڽ��ն���
    QList<ClientSocket *> clients; //���TCP���ӵļ���
    QList<Chat*> chats;
};

#endif // MESSAGEWIND_H
