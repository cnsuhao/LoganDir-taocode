#include "CradleView.h"

#include <QMessageBox>
#define DIR_WIDTH    35
#define PRE_WIDTH    30
#define PIX_WIDTH    30
#define ZOOM_WIDTH   25

GradleView::GradleView(QWidget* parent):QWidget(parent),m_speed(50),
    m_preCall(1),m_pixel(1),m_labTitle(tr("Gradle Ctrl")),m_labSpeed(tr("Speed"))
{
    m_btnLeft = new QPushButton("Left",this);
    m_btnLeft->setFixedSize(DIR_WIDTH,DIR_WIDTH);
    m_btnLeft->setToolTip(tr("Turn Left"));
    connect(m_btnLeft,SIGNAL(pressed()),this,SLOT(onLeft()));
    connect(m_btnLeft,SIGNAL(clicked()),this,SLOT(onStop()));

    m_btnRight = new QPushButton("Right",this);
    m_btnRight->setFixedSize(DIR_WIDTH,DIR_WIDTH);
    m_btnRight->setToolTip(tr("Turn Right"));
    connect(m_btnRight,SIGNAL(pressed()),this,SLOT(onRight()));
    connect(m_btnRight,SIGNAL(clicked()),this,SLOT(onStop()));

    m_btnUp = new QPushButton("Up",this);
    m_btnUp->setFixedSize(DIR_WIDTH,DIR_WIDTH);
    m_btnUp->setToolTip(tr("Turn Up"));
    connect(m_btnUp,SIGNAL(pressed()),this,SLOT(onUp()));
    connect(m_btnUp,SIGNAL(clicked()),this,SLOT(onStop()));

    m_btnDown = new QPushButton("Down",this);
    m_btnDown->setFixedSize(DIR_WIDTH,DIR_WIDTH);
    m_btnDown->setToolTip(tr("Turn Down"));
    connect(m_btnDown,SIGNAL(pressed()),this,SLOT(onDown()));
    connect(m_btnDown,SIGNAL(clicked()),this,SLOT(onStop()));

    m_btnHome = new QPushButton("Home",this);
    m_btnHome->setFixedSize(DIR_WIDTH,DIR_WIDTH);
    m_btnHome->setToolTip(tr("Home"));
    connect(m_btnHome,SIGNAL(clicked()),this,SLOT(onHome()));

    m_btnZoomUp = new QPushButton("zoomUP",this);
    m_btnZoomUp->setFixedSize(ZOOM_WIDTH,ZOOM_WIDTH);
    m_btnZoomUp->setToolTip(tr("Zoom Up"));
    connect(m_btnZoomUp,SIGNAL(pressed()),this,SLOT(onZoomUp()));
    connect(m_btnZoomUp,SIGNAL(clicked()),this,SLOT(onStop()));

    m_btnZoomDown = new QPushButton("zoomDown",this);
    m_btnZoomDown->setFixedSize(ZOOM_WIDTH,ZOOM_WIDTH);
    m_btnZoomDown->setToolTip(tr("Zoom Down"));
    connect(m_btnZoomDown,SIGNAL(pressed()),this,SLOT(onZoomDown()));
    connect(m_btnZoomDown,SIGNAL(clicked()),this,SLOT(onStop()));


    m_sldZoom = new QSlider(Qt::Horizontal,this);
    m_sldZoom->setValue(50);
    m_sldZoom->setFixedSize(60,18);
    m_sldZoom->setMinimum(0);
    m_sldZoom->setMaximum(100);

    m_sldSpeed = new QSlider(Qt::Horizontal,this);
    m_sldSpeed->setValue(50);
    m_sldSpeed->setFixedSize(100,18);
    m_sldSpeed->setMinimum(0);
    m_sldSpeed->setMaximum(100);
    connect(m_sldSpeed,SIGNAL(valueChanged(int)),this,SLOT(updateSpeed(int)));

    m_grpPrecall = new QButtonGroup(this);

    for(int i=0;i<8;i++)
    {
        QString s;
        s=QString("%1").arg(i);
        m_arryBtnPreCall[i].setText(s);
        m_arryBtnPreCall[i].setFixedSize(PRE_WIDTH,PRE_WIDTH);
        m_grpPrecall->addButton(&m_arryBtnPreCall[i],i);
    }

    m_grpPixel = new QButtonGroup(this);

    for(int i=0;i<6;i++)
    {
        m_arryBtnPix[i].setText("dsada");
        m_arryBtnPix[i].setFixedSize(PIX_WIDTH,PIX_WIDTH);
        m_grpPixel->addButton(&m_arryBtnPix[i],i);
    }

    m_globalLay = new QGridLayout(this);

    m_globalLay->addWidget(&m_labTitle,0,0,1,6,Qt::AlignCenter);
    m_globalLay->addWidget(m_btnUp,1,1,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(m_btnLeft,2,0,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(m_btnHome,2,1,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(m_btnRight,2,2,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(m_btnDown,3,1,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(m_btnZoomDown,1,3,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(m_sldZoom,1,4,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(m_btnZoomUp,1,5,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(&m_arryBtnPix[0],2,3,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(&m_arryBtnPix[1],2,4,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(&m_arryBtnPix[2],2,5,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(&m_arryBtnPix[3],3,3,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(&m_arryBtnPix[4],3,4,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(&m_arryBtnPix[5],3,5,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(&m_labSpeed,4,3,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(m_sldSpeed,4,4,1,2,Qt::AlignCenter);
    for(int i=0;i<4;i++)
    {
        if(i!=3)
        m_globalLay->addWidget(&m_arryBtnPreCall[i],5,i+1,1,1,Qt::AlignCenter);
        else
        {
            m_globalLay->addWidget(&m_arryBtnPreCall[i],5,i+1,1,1,Qt::AlignLeft);
        }
    }

    for(int i=4;i<8;i++)
    {
        if(i!=7)
        m_globalLay->addWidget(&m_arryBtnPreCall[i],6,i-3,1,1,Qt::AlignCenter);
        else
        {
            m_globalLay->addWidget(&m_arryBtnPreCall[i],6,i-3,1,1,Qt::AlignLeft);
        }
    }

    m_globalLay->setSpacing(5);
    m_globalLay->setMargin(0);
    this->setLayout(m_globalLay);


}

GradleView::~GradleView()
{

}

int GradleView::getSpeed()const
{
    return m_speed;
}

int GradleView::getPreCall()const
{
    return m_preCall;
}

int GradleView::getPixel()const
{
    return m_pixel;
}

void GradleView::onLeft()
{
    QMessageBox::about(this,"tip","left");
}
void GradleView::onRight()
{

}
void GradleView:: onUp()
{

}
void GradleView::onDown()
{

}
void GradleView::onHome()
{

}
void GradleView::onStop()
{

}
void GradleView::onZoomUp()
{

}
void GradleView::onZoomDown()
{

}

void GradleView::updateSpeed(int speed)
{
    m_speed = speed;
}

void GradleView::updateZoom()
{

}
