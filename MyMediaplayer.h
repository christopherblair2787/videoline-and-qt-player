#pragma once
#ifdef _WIN32
#include <basetsd.h>
typedef SSIZE_T ssize_t;
#endif
#include "vlc/vlc.h"
#include "ui_MyMediaplayer.h"
#include <QtWidgets/QWidget>
#include <QTimer>
#include <QFileDialog>
#include <QDebug>
#include <vector>

enum CycleStatus
{
    SingleCycle,
    ListCycle,
    None
};

class MyMediaplayer : public QWidget
{
    Q_OBJECT

public:
    MyMediaplayer(QWidget *parent = Q_NULLPTR);
    ~MyMediaplayer();

public slots:
    //���ŵ�ǰ��Ƶ
    void onPlayCurrentVedio();
    //��ͣ��Ƶ����
    void onPauseCurrentVideo();
    //ֹͣ������Ƶ
    void onStopCurrentVideo();
    //����򿪰�ť��
    void onOpenPushButtonClicked();
    //�����ͣ��ť
    void onPausePushButtonClicked();
    //�����ʼ���Ű�ť
    void onPlayPushButtonClicked();
    //���ֹͣ���Ű�ť
    void onStopPushButtonClicked();
    //�����϶���ĳһ��λ��
    void onSliderRelease(int val);
    //����ѭ����ť���
    void onSingleButtonClicked();
    //ˢ�°�ť��Ϊ�˲��Զ�̬���һ������������
    void onSignalFreshButtonClicked();
    //�������б�item�����
    void onSignalListWidItemClicked(QListWidgetItem* item);

private:
    //��ʼ������
    void initData();
    //��ʼ��vlc����
    bool initVlcData();
    //��ʼ������
    void initConnect();
    //�ͷ�vlc
    void freeVlc();
    //��ղ����б�
    void clearPlayList();
    //�Ѻ���ת��Ϊ�֣������ʽ 
    void transferTime(QString& time, int msTime);
    //���ò����б�
    void addToPlayList(QString path);
    //����index�����б�����Ƶ
    void playVideoAcordIndex(int idx);
    //����listwidget�е�ǰ��
    void setListWidCurrentRow();

protected:
    //vlc�ص��¼��Ĵ���
    static void vlcEvents(const libvlc_event_t* ev, void* param);

private:
    Ui::MyMediaplayerClass ui;
    libvlc_instance_t* m_ptrVlcInstance{ nullptr };
    libvlc_media_t* m_ptrMedia{ nullptr };
    libvlc_media_player_t* m_ptrMediaPlayer{ nullptr };
    libvlc_media_list_player_t* m_ptrListMediaPlayer{ nullptr };
    libvlc_media_list_t* m_ptrMediaList{ nullptr };
    QFileDialog* m_ptrFileDialog{ nullptr };

    bool m_bIsSingleCycle{ false };         //�Ƿ���ѭ��
    std::vector<QString> m_vecPlayList;     //�����б�
    std::vector<QString> m_vecPlayedVideoPathList;   //�����Ѿ����Ź�����Ƶ·���б�
    std::vector<QString> m_vecPlayedVideoNameList;  //���Ź�����Ƶ�����ƣ�˳���·���б�һ��
    int m_iCurVideoPos{ -1 };       //��ǰ��Ƶ���б��е�λ��
    bool m_bIsPlay{ false };       //�Ƿ����ڲ���
    QString m_strCurPath{ "" };     //��ǰҪ���ŵ���Ƶ�ļ���·��
    int m_iCurVedioTotalTime{ 0 };     //��ǰ��Ƶ��ʱ��

    static MyMediaplayer* m_ptrThis;    //ָ���Լ���ָ��
    static int curTime;
};
