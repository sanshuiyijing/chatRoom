/*

  �������������ϵ�˵���
  ���������ϵ�˵İ�ť������������ϵ��
  ����ϵ�����ֻ��ߺ����Ѿ����ڣ�����Ӵ���
  ���Ҹ�������ԭ��

  */


#ifndef NEWCONTACT_H
#define NEWCONTACT_H

#include <QDialog>
#include "data.h"

namespace Ui {
    class NewContact;
}

class NewContact : public QDialog
{
    Q_OBJECT

public:
    explicit NewContact(QWidget *parent = 0);
    ~NewContact();
   QList<Contact>* getnewcontacts();
private slots:
    void OkButtonClicked();     //ȷ����ť��������

private:
    bool contatcCorrect(const Contact &);  //�ж���ϵ�˺ͺ����Ƿ���д��ȷ
    bool iscontainedperson(const QString &); //������ǰ����ϵ�˵������Ƿ��Ѿ�����
    bool iscontainednumber(const QString &);//������ǰ����ϵ�˵ĺ����Ƿ��Ѵ���
    Ui::NewContact *ui;
    QList<Contact> newcontacts;
};

#endif // NEWCONTACT_H
