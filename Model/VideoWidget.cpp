
#include "VideoWidget.h"

#define SRC_DIFF 1000

VideoWidget::VideoWidget(QWidget *parent):QWidget(parent),m_isSelected(false),
    m_bkColor(0,0,0),m_isFullSrc(false),m_isSignaled(false)
{

}

VideoWidget::~VideoWidget()
{

}

void VideoWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(rect(),m_bkColor);
//    if(!m_isSignaled)
//    {
//        painter.setFont(QFont("Times",50*rect().width()/SRC_DIFF));
//        painter.setPen(QPen(QBrush(QColor("blue")),4));
//        painter.drawText(rect(),Qt::AlignCenter,m_tipMsg);
//        this->update();
//    }

    if(m_isSelected && !m_isFullSrc)
    {
        painter.setPen(QPen(QColor(0,255,0), 3));
        painter.drawRect(rect());
    }
}

void VideoWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            m_isSelected=!m_isSelected;
            //if(m_isSelected)
            {
                emit selectVideo((QWidget*)this);
            }
        }
        else if(event->type()==QEvent::MouseButtonDblClick)
        {
            fullSrc();
        }
        this->update();
    }
    QWidget::mousePressEvent(event);
}

void VideoWidget::fullSrc()
{
//    if(this->isFullScreen())
//    {
//        this->setWindowFlags(Qt::SubWindow);
//        this->showNormal();
//        m_isFullSrc=false;
//    }
//    else
//    {
//       this->setWindowFlags(Qt::Dialog);
//       this->showFullScreen();
//        m_isFullSrc=true;
//    }
}

void VideoWidget::setbkColor(QColor color)
{
    m_bkColor = color;
}


void VideoWidget::select(bool isSelected)
{
    m_isSelected = isSelected;
}

//void VideoWidget::setTipMsg(const QString &msg)
//{
//    m_tipMsg = msg;
//}
