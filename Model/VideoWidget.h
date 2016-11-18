#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>
#include <QFont>

class IVideo
{
public:
    virtual void fullSrc()=0;
    virtual void setbkColor(QColor color)=0;
    //virtual void setTipMsg(const QString& msg)=0;
   // virtual QVariant getHwnd()const =0;

};


class VideoWidget :public QWidget,public IVideo
{
    Q_OBJECT
public:
    explicit VideoWidget(QWidget *parent=0);
    ~VideoWidget();
signals:
    void selectVideo(QWidget* widget);
public slots:

protected:
    QColor     m_bkColor;
    bool       m_isSelected;
    bool       m_isFullSrc;
    //QString    m_tipMsg;
    bool       m_isSignaled;
private:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void fullSrc();
public:
    void setbkColor(QColor color);
    void select(bool isSelected);
    //void setTipMsg(const QString& msg);

public:
    //视频的附属选项
    //bool addSubTitle(const QString &subtitle,QPoint point,QFont font,QColor color);//添加字幕

};


#endif // QVIDEOWIDGET_H

















