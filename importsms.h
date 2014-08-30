/*
���ڴ������ļ��е������

*/

#ifndef IMPORTSMS_H
#define IMPORTSMS_H

#include <QDialog>
#include "data.h"
#include <QList>
#include <QXmlStreamReader>

namespace Ui {
class ImportSms;
}

class ImportSms : public QDialog
{
    Q_OBJECT
    
public:
    explicit ImportSms(QWidget *parent = 0);
    ~ImportSms();
private slots:
    void importButtonClicked();
    
private:
    bool readSmsFromFile(const QString &);//���ļ��ж�ȡ����
    void readMessage();        //��ʼ��ȡ
    void readSms();           //��ȡ��Ϣ
    void insertSms(Message &); //���ݶ������ݺͺ��룬��ŵ������λ��
    QString readElement();//��ȡ��ǰԪ��
    Ui::ImportSms *ui;
    QXmlStreamReader reader;
};

#endif // IMPORTSMS_H
