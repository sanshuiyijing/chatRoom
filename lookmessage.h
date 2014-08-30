#ifndef LOOKMESSAGE_H
#define LOOKMESSAGE_H

#include <QDialog>
#include "data.h"
#include "readthread.h"

namespace Ui {
class LookMessage;
}

class LookMessage : public QDialog
{
    Q_OBJECT
    
public:
    explicit LookMessage(const Message &m, QWidget *parent = 0);
    ~LookMessage();
    
private slots:
    void on_closeButton_clicked();

    void on_readButton_clicked();

    void on_stopButton_clicked();

private:
    Ui::LookMessage *ui;

    ReadThread read;    //read���ڶ���Ϣ���̣߳�ע�������ܶ���Ϊ�ֲ�����������ᵼ�¹����ͷš�
    Message my;
};

#endif // LOOKMESSAGE_H
