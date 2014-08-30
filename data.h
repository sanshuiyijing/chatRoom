#ifndef DATA_H
#define DATA_H

#include <QString>
#include <QDateTime>
#include <QList>
#include <QStringList>
#include <QMap>

const QString dateTimeFormat="yyyy-MM-dd,HH:mm:ss";

extern QString myName;
extern QString myNumber;

struct Message
{
    QString number;
    QString content;
    QDateTime time;   //����ʱ�����ʱ��
    int now;    //��ʾ��ǰ����Ϣλ���ĸ�������:-1Ϊ�ݸ��䣬0Ϊ�����䣬1Ϊ�ռ��䣬2Ϊ������,3Ϊδ��
    int from;  //��ʾ����Ϣ����Դ��-1ΪԴ�ڲݸ��䣬0ΪԴ�ڷ����䣬1ΪԴ���ռ����Ѷ�,2��ʾ�������Ѷ�,3Ϊδ��,4Ϊ������Ϣ
};

struct Contact
{
    QString name;
    QString number;
    bool isWhite;
    bool onLine;    //���һ���û��Ƿ����ߵı�ǣ���ʼ��ʱȫ���趨Ϊfalse
};

extern QList<Message> allMessages;
extern QList<Message> unreadsms;
extern QStringList badWords;
extern QList<Contact> allContacts;
extern QList<Contact> strangers;    //������ʾİ���˼���

extern QMap<QString, int> directory;   //ʹ�ø����Ĵʿ�����Զ�ѧϰ����ϵͳ����ʱ��ʼ��
extern QMap<QString, int> numberCount;  //���ڼ�¼�������������еĺ�����ִ�����ʵ������ʶ���ڵ���allMessages�ǳ�ʼ��

int recogniseName(const QString name);    //ʶ���������԰��������Ǻ�����,����������-1������������1
int recogniseNumber(const QString number);    //ʶ��������Ժ��������ǰ�����������������-1������������1
bool hasBadWords(const QString content);

bool isRubishMessage(const Message & newMessage);  //���ݺ���������ж��ǲ���Ӧ�÷���������

//������������ʵ�����ֺͺ�����ת�����������ڣ��򷵻���ͬ���ƣ�������isFind����Ϊfalse��
//�ڶ�����������������Ǹ����ֻ�����Ƿ���ڣ����û���������㣬����ʹ��NULL������
QString nameToNumber(QString name, bool * isFind = NULL);
QString numberToName(QString number, bool * isFind = NULL);

//��������������ת��������ֻ�������
QString namesToNumbers(QString names);
QString numbersToNames(QString numbers);

void study(const Message & newMessage);     //ʵ�ֶ��ŵ����ܷ���

#endif // DATA_H
