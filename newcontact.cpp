﻿/*

  这个是增加新联系人的类
  点击增加联系人的按钮，可以增加联系人
  若联系人名字或者号码已经存在，则添加错误
  并且给出错误原因
  */


#include "newcontact.h"
#include "ui_newcontact.h"
#include <QMessageBox>

NewContact::NewContact(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewContact)
{
    ui->setupUi(this);
    this->setFixedSize(width(),height());
    setWindowTitle(tr("添加新联系人"));
    ui->whiteRadioButton->setChecked(true);
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->OkButton,SIGNAL(clicked()),this,SLOT(OkButtonClicked()));
}

NewContact::~NewContact()
{
    delete ui;
}
void NewContact::OkButtonClicked()   //确定按钮点击后调用，增加联系人或者黑名单
{
    Contact tempcontact;
    tempcontact.name=ui->nameEdit->text();
    tempcontact.number=ui->numberEdit->text();
    if(contatcCorrect(tempcontact)&&!iscontainedperson(tempcontact.name)&&!iscontainednumber(tempcontact.number))
    {
        if(ui->whiteRadioButton->isChecked())
        {
            tempcontact.isWhite=true;
            tempcontact.onLine=false;
            allContacts.append(tempcontact);  //添加白名单
            newcontacts.append(tempcontact);
        }
        else
        {
            tempcontact.isWhite=false;
            allContacts.append(tempcontact); // 添加黑名单
            newcontacts.append(tempcontact);
        }
        QMessageBox::information(this,tr("提示"),tr("添加\"")+tempcontact.name+tr("\"成功！"));
        ui->nameEdit->clear();
        ui->numberEdit->clear();
        ui->OkButton->setText(tr("继续添加"));
    }
    else
        if(!contatcCorrect(tempcontact))
        {
            QMessageBox::critical(this,tr("错误"),tr("信息填写错误！"));
            ui->nameEdit->clear();
            ui->numberEdit->clear();
        }
        else
            if(iscontainedperson(tempcontact.name))
            {
                QMessageBox::critical(this,tr("错误"),tempcontact.name+tr("已存在！"));
                ui->nameEdit->clear();
                ui->numberEdit->clear();
            }
            else
            {
                QMessageBox::critical(this,tr("错误"),tempcontact.number+tr("已存在！"));
                ui->nameEdit->clear();
                ui->numberEdit->clear();

            }
}

bool NewContact::contatcCorrect(const Contact &contact) //判断新联系人姓名或者号码是否填写正确
{
    if(!contact.name.isEmpty()&&!contact.number.isEmpty())
        return true;
    else
        return false;
}

bool NewContact::iscontainedperson(const QString &name)//判断姓名是否已存在
{
    int i;
    for(i=0;i<allContacts.count();i++)
    {
        if(allContacts[i].name==name)
            return true;
    }
    for(i=0;i<strangers.count();i++)
    {
        if(strangers[i].name==name)
            return  true;
    }
    return false;
}

bool NewContact::iscontainednumber(const QString &number)//判断号码是否已存在
{
    int i;
    for(i=0;i<allContacts.count();i++)
    {
        if(allContacts[i].number==number)
            return true;
    }
    for(i=0;i<strangers.count();i++)
    {
        if(strangers[i].number==number)
            return  true;
    }
    return false;
}

QList<Contact>* NewContact::getnewcontacts()
{
    return &newcontacts;
}

 
