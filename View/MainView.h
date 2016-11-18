#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "Model/VideoWidget.h"
#include "CradleView.h"
#include "DisplayView.h"
#include "SubVideoSwitchView.h"
#include "VideoEffectView.h"
#include "VideoAttachView.h"
#include "VideoOptionView.h"
#include <QLabel>
#include <QDate>
#include <QTime>
#include <QTimer>
#include <QPaintEvent>
#include <QEvent>

class AppInfo :public QWidget
{
    Q_OBJECT
public:
    explicit AppInfo(QWidget* parent);
    ~AppInfo();
private:
    QLabel  *m_appIcon,*m_appLogo,*m_appVersion;
    QString m_versionInfo;
    QGridLayout *m_globalLay;
public:
    void setLogo(const QString& ImgFile);
    void setVersion(const QString& ver);
    void setIcon(const QString& ImgFile);
    QString getVersion();

};



class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = 0);
    ~MainView()
    {
        delete m_horTitleBarLay;
        m_horTitleBarLay = NULL;
        delete m_horMainVideoLay;
        m_horMainVideoLay = NULL;
    }
signals:

public slots:
    void onClose();
    void onFile();
    void onSettting();
    void onProfile();

    void updateVideoSelect(QWidget*);
    void updateTimeAndDate();

private:
    QPushButton *m_btnFile,*m_btnSetting,*m_btnProfile,*m_btnClose;
    AppInfo     *appinfo;
    QGridLayout *m_globalLay;
    QHBoxLayout *m_horTitleBarLay,*m_horFunctionLay,*m_horMainVideoLay,*m_horSubVideoLay;
    QVBoxLayout *m_verCtrlLay;//右侧控制区布局
    QVBoxLayout *m_verTimeLay;//时间布局

    VideoWidget *m_videoPGM,*m_videoPVM;//电影  & 预览模式
    GradleView  *m_gradleview;
    SubVideoSwitchView   *m_videoSwitchView;
    DisplayView *m_displayview;//状态显示视图
    VideoEffectView *m_videoEffectView;
    VideoAttachView *m_videoAttachView;
    VideoOptionView *m_videoOptionView;


    VideoWidget *m_selectedVideo;
    QTimer      *m_updateTimeTimer;//更新时间计时器
    QLabel      *m_labTime,*m_labDate;
private:
    void fitnessScreen();
    VideoWidget* getCurrentVideo()const;

private:
    void paintEvent(QPaintEvent *);
    bool event(QEvent *);

};

#endif // MAINVIEW_H
