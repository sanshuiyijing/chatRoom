#ifndef CHILDBLINK_H
#define CHILDBLINK_H
#include "blink.h"
#include "QIcon"

class ChildBlink:public Blink
{
    Q_OBJECT
public:
    ChildBlink(QTreeWidgetItem *);
    virtual ~ChildBlink();
    virtual void setitem(QTreeWidgetItem *);
    QString getnumber();          //���������
    void settext(const QString&);  //��˸������
    void setonlineicon();  //����Ϊ����ʱ��ͼ��
    void setofflineicon();  // ����Ϊ���ߵ�ͼ��
protected slots:
    virtual void changeicon();
protected:
    virtual void parentadd();
    virtual void parentdec();
    virtual void reset();
private:
    QIcon icon;
};

#endif // CHILDBLINK_H
