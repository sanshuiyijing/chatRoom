#ifndef BaseMessageBox_H
#define BaseMessageBox_H

#include <QDialog>
#include "data.h"
#include <QListWidgetItem>
#include <QThread>
#include "readthread.h"

namespace Ui {
class BaseMessageBox;
}

class BaseMessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit BaseMessageBox(int w, QWidget *parent = 0);
    ~BaseMessageBox();

protected:
    virtual void contextMenuEvent(QContextMenuEvent *event);

private slots:
    void on_actionLook_triggered();

    void on_actionEdit_triggered();

    void on_actionSend_triggered();

    void on_actionReply_triggered();

    void on_actionRead_triggered();

    void on_actionMove_triggered();

    void on_actionDelete_triggered();

    void on_actionDeleteALL_triggered();

    void on_actionBack_triggered();

    void on_exitButton_clicked();

private:
    Ui::BaseMessageBox *ui;
    int which;      //whichָʾ��ǰ���䣺-1Ϊ�ݸ��䣬0Ϊ�����䣬1Ϊ�ռ��䣬2Ϊ������
    ReadThread read;    //read���ڶ�����Ϣ����Ҫ����Ϊ�ֲ����������������ͷ�

    void update();
    int analysis(QListWidgetItem * item,QList<Message> **);    //��������Ϣ���������allMessages�еĴ洢�±�
};

#endif // BaseMessageBox_H
