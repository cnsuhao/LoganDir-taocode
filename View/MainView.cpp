#include "MainView.h"

#include <QDesktopWidget>
#include <QApplication>
#include <QPainter>
#include <Model/ConfigFile.h>
#include <QDir>
#include <QFile>
#include <QMutex>

#define TOOL_SIZE  QSize(30,30)

MainView::MainView(QWidget *parent) :
    QWidget(parent),m_selectedVideo(NULL)
{
    fitnessScreen();

    appinfo = new AppInfo(this);
    appinfo->setFixedHeight(30);

    m_globalLay = new QGridLayout(this);
    m_btnSetting = new QPushButton("settting",this);
    m_btnSetting->setFixedSize(TOOL_SIZE);
    connect(m_btnSetting,SIGNAL(clicked()),this,SLOT(onSettting()));

    m_btnFile = new QPushButton("File",this);
    m_btnFile->setFixedSize(TOOL_SIZE);
    connect(m_btnFile,SIGNAL(clicked()),this,SLOT(onFile()));

    m_btnProfile = new QPushButton("Profile",this);
    m_btnProfile->setFixedSize(TOOL_SIZE);
    connect(m_btnProfile,SIGNAL(clicked()),this,SLOT(onProfile()));

    m_btnClose = new QPushButton("close",this);
    m_btnClose->setFixedSize(TOOL_SIZE);
    connect(m_btnClose,SIGNAL(clicked()),this,SLOT(onClose()));

    //标题栏按钮
    m_horTitleBarLay = new QHBoxLayout();
    appinfo->setIcon(":/Skin/icon");
    appinfo->setLogo(":/Skin/logo");
    m_horTitleBarLay->addWidget(appinfo,0,Qt::AlignLeft);
    m_horTitleBarLay->addStretch(100);
    m_horTitleBarLay->addWidget(m_btnFile,0,Qt::AlignRight);
    m_horTitleBarLay->addWidget(m_btnSetting,0,Qt::AlignRight);
    m_horTitleBarLay->addWidget(m_btnProfile,0,Qt::AlignRight);
    m_horTitleBarLay->addWidget(m_btnClose,0,Qt::AlignRight);
    m_horTitleBarLay->setMargin(0);
    m_horTitleBarLay->setSpacing(5);
    m_globalLay->addLayout(m_horTitleBarLay,0,0,1,5);


    //电影和预览
    m_videoPGM = new VideoWidget(this);
    m_videoPGM->select(true);
    m_selectedVideo = m_videoPGM;
    connect(m_videoPGM,SIGNAL(selectVideo(QWidget*)),this,SLOT(updateVideoSelect(QWidget*)));
    m_videoPVM = new VideoWidget(this);
    connect(m_videoPVM,SIGNAL(selectVideo(QWidget*)),this,SLOT(updateVideoSelect(QWidget*)));
    m_horMainVideoLay = new QHBoxLayout();
    m_horMainVideoLay->addWidget(m_videoPGM);
    m_horMainVideoLay->addWidget(m_videoPVM);
    m_horMainVideoLay->setSpacing(3);
    m_horMainVideoLay->setMargin(0);
    m_globalLay->addLayout(m_horMainVideoLay,1,0,4,4);


    //控制功能区
    m_gradleview = new GradleView(this);
    m_verCtrlLay = new QVBoxLayout();

    m_displayview = new DisplayView(this);

    m_verTimeLay = new QVBoxLayout();

    m_verCtrlLay->addWidget(m_displayview);
    m_verCtrlLay->addWidget(m_gradleview);

    //时间 & 日期
    m_labTime = new QLabel("00:00:00",this);
    m_labDate = new QLabel("0000-00-00",this);

    m_updateTimeTimer = new QTimer(this);
    connect(m_updateTimeTimer,SIGNAL(timeout()),this,SLOT(updateTimeAndDate()));
    m_updateTimeTimer->start(100);

    m_verTimeLay->addWidget(m_labTime,0,Qt::AlignHCenter);
    m_verTimeLay->addWidget(m_labDate,0,Qt::AlignHCenter);
    m_verTimeLay->setMargin(0);

    m_verCtrlLay->addLayout(m_verTimeLay);
    m_globalLay->addLayout(m_verCtrlLay,1,4,6,1);



    // 可滚动子视频区
    m_videoSwitchView = new SubVideoSwitchView(this);
    m_horSubVideoLay = new QHBoxLayout();
    m_horSubVideoLay->addWidget(m_videoSwitchView);
    m_globalLay->addLayout(m_horSubVideoLay,5,0,2,4);

    //功能区
    m_horFunctionLay = new QHBoxLayout();
    m_horFunctionLay->setSpacing(5);
    m_horFunctionLay->setMargin(0);
    m_videoEffectView = new VideoEffectView(this);
    m_videoOptionView = new VideoOptionView(this);
    m_videoAttachView = new VideoAttachView(this);

    m_horFunctionLay->addWidget(m_videoEffectView,1);
    m_horFunctionLay->addWidget(m_videoOptionView,1);
    m_horFunctionLay->addWidget(m_videoAttachView,1);

    m_globalLay->addLayout(m_horFunctionLay,7,0,3,5);
    for(int i=0;i<7;i++)
    {
        m_globalLay->setRowStretch(i,1);
        if(i<4)
            m_globalLay->setColumnStretch(i,1);
    }



    m_globalLay->setMargin(3);
    m_globalLay->setSpacing(0);
    this->setLayout(m_globalLay);


}

void MainView::fitnessScreen()
{
    this->setWindowFlags(Qt::FramelessWindowHint |Qt::CustomizeWindowHint);

    QRect DeskRect = QApplication::desktop()->screenGeometry();
    this->resize(DeskRect.width(),DeskRect.height());
}

void MainView::onClose()
{
    this->close();
    //qApp->exit(0);
}

void MainView::onFile()
{

}
void MainView::onSettting()
{

}
void MainView::onProfile()
{

}


void MainView::updateVideoSelect(QWidget *w)
{
    VideoWidget* v = static_cast<VideoWidget*>(w);
    m_videoPGM->select(false);
    m_videoPVM->select(false);
    m_selectedVideo = v;
    v->select(true);
    this->update();
}

VideoWidget* MainView::getCurrentVideo()const
{
    return m_selectedVideo;
}


void MainView::updateTimeAndDate()
{
    QDate date=QDate::currentDate();
    m_labDate->setText(date.toString("yyyy-MM-dd"));

    QTime time = QTime::currentTime();
    m_labTime->setText(time.toString("HH:mm:ss"));

}


void MainView::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
    QPainter painter;
    painter.begin(this);

    painter.fillRect(m_verTimeLay->geometry(),QColor(0,120,0));
    painter.fillRect(m_displayview->geometry(),QColor(0,123,211));
    painter.fillRect(m_gradleview->geometry(),QColor(32,200,0));
    painter.fillRect(m_horTitleBarLay->geometry(),QColor(123,123,0));
    painter.end();
}


bool MainView::event(QEvent *e)
{
    if(e->type()==QEvent::Resize)
    {
        static QMutex m;
        m.lock();
        QDir d=QDir::currentPath();
        QString path=d.path()+"/"+"logan.conf";
        QFile file(path);
        ConfigFile cfg(path.toStdString());

        //PGM
        QString x = QString("%1").arg(mapToGlobal(m_videoPGM->pos()).x());
        QString y = QString("%1").arg(mapToGlobal(m_videoPGM->pos()).y());
        QString width = QString("%1").arg(m_videoPGM->geometry().width());
        QString height = QString("%1").arg(m_videoPGM->geometry().height());
        cfg.addValue("x",x.toStdString(),"PGM");
        cfg.addValue("y",y.toStdString(),"PGM");
        cfg.addValue("width",width.toStdString(),"PGM");
        cfg.addValue("height",height.toStdString(),"PGM");

        //PVM
        x = QString("%1").arg(mapToGlobal(m_videoPVM->pos()).x());
        y = QString("%1").arg(mapToGlobal(m_videoPVM->pos()).y());
        width = QString("%1").arg(m_videoPVM->geometry().width());
        height = QString("%1").arg(m_videoPVM->geometry().height());
        cfg.addValue("x",x.toStdString(),"PVM");
        cfg.addValue("y",y.toStdString(),"PVM");
        cfg.addValue("width",width.toStdString(),"PVM");
        cfg.addValue("height",height.toStdString(),"PVM");

        cfg.save();
        m.unlock();


    }
    return QWidget::event(e);
}

/***********************************************************/


AppInfo::AppInfo(QWidget* parent):QWidget(parent)
{
    m_appIcon = new QLabel(this);
    m_appIcon->setFixedSize(30,30);
    m_appLogo = new QLabel(this);
    m_appLogo->setFixedSize(60,20);
    m_appVersion = new QLabel("ver 0.0.0",this);
    m_appVersion->setFixedHeight(10);
    m_globalLay = new QGridLayout(this);
    m_globalLay->addWidget(m_appIcon,0,0,2,2,Qt::AlignLeft);
    m_globalLay->addWidget(m_appLogo,0,2,1,5,Qt::AlignLeft);
    m_globalLay->addWidget(m_appVersion,1,2,1,5,Qt::AlignLeft);
    m_globalLay->setMargin(0);
    m_globalLay->setSpacing(3);
    this->setLayout(m_globalLay);

}

AppInfo::~AppInfo()
{

}

void AppInfo::setLogo(const QString &ImgFile)
{
    QString s=QString("QLabel{image: url(%1);}").arg(ImgFile);
    m_appLogo->setStyleSheet(s);
}

void AppInfo::setVersion(const QString &ver)
{
    m_versionInfo = ver;
    m_appVersion->setText(ver);
}

void AppInfo::setIcon(const QString& ImgFile)
{
    QString s=QString("QLabel{image: url(%1);}").arg(ImgFile);
    m_appIcon->setStyleSheet(s);
}

QString AppInfo::getVersion()
{
    return m_versionInfo;
}
