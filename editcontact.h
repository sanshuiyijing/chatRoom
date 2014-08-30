/*
  �������ڱ༭��ϵ�˲��ұ���
  */


#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "data.h"
namespace Ui {
    class EditContact;
}

class EditContact : public QDialog
{
    Q_OBJECT

public:
    explicit EditContact(Contact *,QWidget *parent = 0);
    ~EditContact();
protected slots:
    void editButtonClicked();//�༭��ϵ�˲�����

private:
    bool contatcCorrect(const Contact &);  //�ж���ϵ�˺ͺ����Ƿ���д��ȷ
    bool iscontainedperson(const QString &); //������ǰ����ϵ�˵������Ƿ��Ѿ�����
    bool iscontainednumber(const QString &);//������ǰ����ϵ�˵ĺ����Ƿ��Ѵ���
    Ui::EditContact *ui;
    Contact *contact;
    bool editButtonClickednum;
    Contact precontact;

};

#endif // DIALOG_H
