#ifndef VIDEOATTACHVIEW_H
#define VIDEOATTACHVIEW_H

#include <QWidget>
#include <QTabWidget>
#include "Model/VideoWidget.h"
#include "Model/DragWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPaintEvent>

/******************************************
 *
 *   视频附加选项
 *
 *   角标     时间        OSD
 *
 ******************************************/


class SubScriptView;
class TimeView;
class OnScreenDisplayView;


class VideoAttachView : public QTabWidget
{
    Q_OBJECT
    friend class SubScriptView;
    friend class TimeView;
    friend class OnScreenDisplayView;
public:
    explicit VideoAttachView(QWidget *parent = 0);
    void setVideo(VideoWidget* video);

signals:

public slots:
private:
    void init();
private:
    VideoWidget       *m_videowidget;
    SubScriptView     *m_subScriptView;
    TimeView          *m_timeView;
    OnScreenDisplayView *m_onScreenDisplay;

};


/**
 * 角标
 */

class SubScriptView: public QWidget
{
    Q_OBJECT
public:
    explicit SubScriptView(QWidget *parent = 0);

signals:

public slots:
private:
    DragWidget  *m_dw;
    QVBoxLayout *m_globalLay;
    QLabel       m_labPGM,m_labPVM;
    QPushButton  *m_btnPGMInsert,*m_btnPVMInsert;
    QGridLayout  *m_subLay;

    void paintEvent(QPaintEvent*);

};


class TimeView: public QWidget
{
    Q_OBJECT
public:
    explicit TimeView(QWidget *parent = 0);

signals:

public slots:
private:

};


class OnScreenDisplayView: public QWidget
{
    Q_OBJECT
public:
    explicit OnScreenDisplayView(QWidget *parent = 0);

signals:

public slots:
private:

};


#endif // VIDEOATTACHVIEW_H
