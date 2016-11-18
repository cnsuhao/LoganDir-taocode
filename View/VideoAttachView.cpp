#include "VideoAttachView.h"
#include <QLabel>
#include <QPainter>
VideoAttachView::VideoAttachView(QWidget *parent) :
    QTabWidget(parent),m_videowidget(NULL)
{
    init();
}

void VideoAttachView::init()
{
    m_subScriptView = new SubScriptView(this);
    m_timeView = new TimeView(this);
    m_onScreenDisplay = new OnScreenDisplayView(this);

    this->addTab(m_subScriptView,"SubScript");
    this->addTab(m_timeView,"Time");
    this->addTab(m_onScreenDisplay,"OSD");
}

void VideoAttachView::setVideo(VideoWidget *video)
{
    m_videowidget = video;
}



/************************************************************/




SubScriptView::SubScriptView(QWidget* parent):
    QWidget(parent),m_labPGM("PGM"),m_labPVM("PVM")
{
    m_globalLay = new QVBoxLayout(this);

    m_dw = new DragWidget(this);
    m_dw->setImg(":/Skin/logo");
    m_dw->setFixImgSize(QSize(79,29));
    m_globalLay->addWidget(m_dw,5);

    m_btnPGMInsert = new QPushButton(tr("Insert"),this);
    m_btnPVMInsert = new QPushButton(tr("Insert"),this);

    m_subLay = new QGridLayout();

    m_subLay->addWidget(&m_labPGM,0,0,1,1,Qt::AlignRight);
    m_subLay->addWidget(m_btnPGMInsert,0,1);
    m_subLay->addWidget(&m_labPVM,0,2,1,1,Qt::AlignRight);
    m_subLay->addWidget(m_btnPVMInsert,0,3);

    m_globalLay->addLayout(m_subLay,1);
    this->setLayout(m_globalLay);
}


void SubScriptView::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter p(this);
    p.fillRect(m_dw->geometry(),QColor(35,35,35));
    p.end();
}


/**********************************************************/

TimeView::TimeView(QWidget* parent):
    QWidget(parent)
{

}


/*******************************************************/

OnScreenDisplayView::OnScreenDisplayView(QWidget* parent):
    QWidget(parent)
{

}
