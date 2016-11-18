#include "VideoEffectView.h"

#include <iostream>

VideoEffectView::VideoEffectView(QWidget *parent) :
    QTabWidget(parent),m_videowidget(NULL)
{
    init();
}


void VideoEffectView::init()
{

   m_effectView = new EffectView(this);

   m_cutView = new CutView(this);

   this->addTab(m_effectView,"Effect");
   this->addTab(m_cutView,"Cut");
}


void VideoEffectView::setVideo(VideoWidget *video)
{
    m_videowidget = video;
}



/******************************************************/


EffectView::EffectView(QWidget* parent):
QWidget(parent)
{
    init();
}


void EffectView::init()
{
    m_globalLay = new QGridLayout(this);
    m_globalLay->setSpacing(10);
    m_globalLay->setMargin(10);

    m_btnLeftEnter = new QPushButton(this);
    m_btnLeftEnter->setToolTip(tr("Left Enter"));

    m_btnTopEnter = new QPushButton(this);
    m_btnTopEnter->setToolTip(tr("Top Enter"));

    m_btnRightEnter = new QPushButton(this);
    m_btnRightEnter->setToolTip(tr("Right Enter"));

    m_btnBottomEnter = new QPushButton(this);
    m_btnBottomEnter->setToolTip(tr("Bottom Enter"));


    m_btnLeftTopEnter = new QPushButton(this);
    m_btnLeftTopEnter->setToolTip(tr("LeftTop Enter"));

    m_btnRightTopEnter = new QPushButton(this);
    m_btnRightTopEnter->setToolTip(tr("RightTop Enter"));

    m_btnRightBottomEnter = new QPushButton(this);
    m_btnRightBottomEnter->setToolTip(tr("RightBotton Enter"));

    m_btnLeftBottomEnter = new QPushButton(this);
    m_btnLeftBottomEnter->setToolTip(tr("LeftBottom Enter"));

    m_btnFadeIn = new QPushButton(this);
    m_btnFadeIn->setToolTip(tr("Fade In"));

    m_btnFadeOut = new QPushButton(this);
    m_btnFadeOut->setToolTip(tr("Fade Out"));


    m_globalLay->addWidget(m_btnLeftEnter,0,0);
    m_globalLay->addWidget(m_btnTopEnter,0,1);
    m_globalLay->addWidget(m_btnRightEnter,0,2);
    m_globalLay->addWidget(m_btnBottomEnter,0,3);

    m_globalLay->addWidget(m_btnLeftTopEnter,1,0);
    m_globalLay->addWidget(m_btnRightTopEnter,1,1);
    m_globalLay->addWidget(m_btnRightBottomEnter,1,2);
    m_globalLay->addWidget(m_btnLeftBottomEnter,1,3);

    m_globalLay->addWidget(m_btnFadeIn,2,1);
    m_globalLay->addWidget(m_btnFadeOut,2,2);


    this->setLayout(m_globalLay);



}


bool EffectView::event(QEvent *e)
{

     QWidget::event(e);
    if(e->type()==QEvent::Resize)
    {
        int width =m_globalLay->geometry().width();

        width-=50;
        width/=4;
        m_btnLeftEnter->setFixedSize(width,width);
        m_btnTopEnter->setFixedSize(width,width);
        m_btnRightEnter->setFixedSize(width,width);
        m_btnBottomEnter->setFixedSize(width,width);
        m_btnLeftTopEnter->setFixedSize(width,width);
        m_btnRightTopEnter->setFixedSize(width,width);
        m_btnRightBottomEnter->setFixedSize(width,width);
        m_btnLeftBottomEnter->setFixedSize(width,width);
        m_btnFadeIn->setFixedSize(width,width);
        m_btnFadeOut->setFixedSize(width,width);

    }
    return true;
}

/*****************************************************/


CutView::CutView(QWidget* parent):
QWidget(parent)
{
    init();
}

void CutView::init()
{
    m_globalLay = new QGridLayout(this);

    m_globalLay->addWidget(&m_btnOnlyOnce,0,0);
    m_globalLay->addWidget(&m_btnMainSubMix,0,1);
    m_globalLay->addWidget(&m_btnMainSubDevide,0,2);
    m_globalLay->addWidget(&m_btnDoubleMain,0,3);

    m_globalLay->addWidget(&m_btnLeftTwoRightOne,1,0);
    m_globalLay->addWidget(&m_btnLeftOneRightTwo,1,1);
    m_globalLay->addWidget(&m_btnTopOneBottomTwo,1,2);
    m_globalLay->addWidget(&m_btnFourMain,1,3);

    m_globalLay->addWidget(&m_btnFive,2,0);
    m_globalLay->addWidget(&m_btnU1,2,1);
    m_globalLay->addWidget(&m_btnU2,2,2);
    m_globalLay->addWidget(&m_btnU3,2,3);

    m_grp = new QButtonGroup(this);

    m_grp->addButton(&m_btnOnlyOnce);
    m_grp->addButton(&m_btnMainSubMix);
    m_grp->addButton(&m_btnMainSubDevide);
    m_grp->addButton(&m_btnDoubleMain);
    m_grp->addButton(&m_btnLeftTwoRightOne);
    m_grp->addButton(&m_btnLeftOneRightTwo);
    m_grp->addButton(&m_btnTopOneBottomTwo);
    m_grp->addButton(&m_btnFourMain);
    m_grp->addButton(&m_btnFive);
    m_grp->addButton(&m_btnU1);
    m_grp->addButton(&m_btnU2);
    m_grp->addButton(&m_btnU3);

    this->setLayout(m_globalLay);
}


bool CutView::event(QEvent *e)
{

     QWidget::event(e);
    if(e->type()==QEvent::Resize)
    {
        int width =m_globalLay->geometry().width();

        width-=50;
        width/=4;
        m_btnOnlyOnce.setFixedSize(width,width);
        m_btnMainSubMix.setFixedSize(width,width);
        m_btnMainSubDevide.setFixedSize(width,width);
        m_btnDoubleMain.setFixedSize(width,width);
        m_btnLeftTwoRightOne.setFixedSize(width,width);
        m_btnLeftOneRightTwo.setFixedSize(width,width);
        m_btnTopOneBottomTwo.setFixedSize(width,width);
        m_btnFourMain.setFixedSize(width,width);
        m_btnFive.setFixedSize(width,width);
        m_btnU1.setFixedSize(width,width);
        m_btnU2.setFixedSize(width,width);
        m_btnU3.setFixedSize(width,width);

    }
    return true;
}





