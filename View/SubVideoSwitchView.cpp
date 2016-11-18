#include "SubVideoSwitchView.h"

#include "Model/ConfigFile.h"
#include <QFile>
#include <QDir>
#include <QMutex>

SubVideoSwitchView::SubVideoSwitchView(QWidget *parent) :
    QWidget(parent),m_selectedVideo(NULL)
{
    m_queueVideo.clear();
    //左右切换按钮
    m_btnLeft = new QPushButton("<<",this);
    m_btnLeft->setFixedSize(25,80);
    m_btnLeft->setObjectName("LeftSwitch");
    connect(m_btnLeft,SIGNAL(clicked()),this,SLOT(onLeftSwitch()));

    m_btnRight = new QPushButton(">>",this);
    m_btnRight->setObjectName("RightSwitch");
    m_btnRight->setFixedSize(25,80);
    connect(m_btnRight,SIGNAL(clicked()),this,SLOT(onRightSwitch()));

    m_globalLay = new QHBoxLayout(this);
    m_globalLay->addWidget(m_btnLeft);
    m_globalLay->setSpacing(3);
    m_globalLay->setMargin(2);

    for(int i=0;i<VIDEO_SIZE;i++)
    {
        VideoWidget *vw = new VideoWidget();
        if(i==0)
        {
            vw->select(true);
            m_selectedVideo = vw;
        }
        connect(vw,SIGNAL(selectVideo(QWidget*)),this,SLOT(singleSelect(QWidget*)));
        m_globalLay->addWidget(vw);
        m_queueVideo.push_back(vw);
    }

    dealvideo();
    m_globalLay->addWidget(m_btnRight);

    this->setLayout(m_globalLay);

}

SubVideoSwitchView::~SubVideoSwitchView()
{
//   while(!m_queueVideo.empty())
//   {
//       VideoAnimation delVA=m_queueVideo.back();
//       delete delVA.animation;
//       delete delVA.videowidget;
//       m_queueVideo.pop_back();
//   }
}

void SubVideoSwitchView::onLeftSwitch()
{
    this->update();
    leftAnimation();
}

void SubVideoSwitchView::onRightSwitch()
{
    this->update();
    rightAnimation();
}


void SubVideoSwitchView::dealvideo()
{
    QQueue<VideoWidget*>tmp = m_queueVideo;

    while(tmp.size()>4)
    {
        tmp.back()->setVisible(false);
        tmp.pop_back();
    }
    tmp.clear();
}

void SubVideoSwitchView::leftAnimation()
{
    m_queueVideo.push_back(m_queueVideo.front());
    m_queueVideo.pop_front();

    for(int i=0;i<m_queueVideo.size();i++)
    {
        if(i<4)
        {
            m_queueVideo.at(i)->setVisible(true);
        }
        else
        {
            m_queueVideo.at(i)->setVisible(false);
        }
    }
    this->update();
}

void SubVideoSwitchView::rightAnimation()
{
    m_queueVideo.push_front(m_queueVideo.back());
    m_queueVideo.pop_back();

    for(int i=0;i<m_queueVideo.size();i++)
    {
        if(i<4)
        {
            m_queueVideo.at(i)->setVisible(true);
        }
        else
        {
            m_queueVideo.at(i)->setVisible(false);
        }
    }
    this->update();
}


bool SubVideoSwitchView::event(QEvent *e)
{
    if(e->type()==QEvent::Resize)
    {
        static QMutex m;
        m.lock();
        QDir d=QDir::currentPath();
        QString path=d.path()+"/"+"logan.conf";
        QFile file(path);
        ConfigFile cfg(path.toStdString());
        for(int i=0;i<4;i++)
        {
            QString x = QString("%1").arg(mapToGlobal(m_queueVideo.at(i)->pos()).x());
            QString y = QString("%1").arg(mapToGlobal(m_queueVideo.at(i)->pos()).y());
            QString width = QString("%1").arg(m_queueVideo.at(i)->geometry().width());
            QString height = QString("%1").arg(m_queueVideo.at(i)->geometry().height());
            QString title = QString("SUB_%1").arg(i+1);
            cfg.addValue("x",x.toStdString(),title.toStdString());
            cfg.addValue("y",y.toStdString(),title.toStdString());
            cfg.addValue("width",width.toStdString(),title.toStdString());
            cfg.addValue("height",height.toStdString(),title.toStdString());

        }
        cfg.save();
        m.unlock();


    }
    return QWidget::event(e);
}

void SubVideoSwitchView::singleSelect(QWidget * w)
{
    VideoWidget *v =static_cast<VideoWidget*>(w);
    m_selectedVideo = v;
    for(int i=0;i<m_queueVideo.size();i++)
    {
        if(v!=m_queueVideo.at(i))
             m_queueVideo.at(i)->select(false);
        else
             m_queueVideo.at(i)->select(true);
    }
    this->update();

}


int SubVideoSwitchView::getVideoCount()const
{
    return m_queueVideo.size();
}
VideoWidget* SubVideoSwitchView::getCurrentSelectedVideo()const
{
    return m_selectedVideo;
}
