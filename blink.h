/*
  ����Ǹ��ڵ���ӽڵ����˸�Ļ��࣬�������ʵ���䴿�麯��


  */

#ifndef BLINK_H
#define BLINK_H

#include <QObject>
#include <QTimer>
class QTreeWidgetItem;
class Blink : public QObject
{
    Q_OBJECT
public:
    explicit Blink(QTreeWidgetItem *,QObject *parent = 0);
    virtual ~Blink();
    QTreeWidgetItem* getitem();       //����item
    virtual void setitem(QTreeWidgetItem *);  //����item
    QTreeWidgetItem* getparentitem(); //����item�ĸ��ڵ�
    void startblink(); //��ʼ��˸
    void stopblink();   // ֹͣ��˸

signals:
    
protected slots:
    virtual void changeicon()=0;
protected:
    virtual void reset()=0;
    QTreeWidgetItem *item;
    QTimer timer;
    bool display;
    QString text;
};

#endif // BLINK_H
