#ifndef VIDEOEFFECTVIEW_H
#define VIDEOEFFECTVIEW_H

#include <QWidget>
#include "Model/VideoWidget.h"
#include <QTabWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QEvent>
#include <QButtonGroup>

/******************************************
 *
 *   视频效果
 *  特效      分割
 *
 ******************************************/

class EffectView;
class CutView;


class VideoEffectView : public QTabWidget
{
    Q_OBJECT
    friend class EffectView;
    friend class CutView;
public:
    explicit VideoEffectView(QWidget *parent = 0);
    void setVideo(VideoWidget* video);
signals:

public slots:
private:
    void init();
private:
    VideoWidget    *m_videowidget;//需要操作的视频控件
    EffectView     *m_effectView;
    CutView        *m_cutView;

};



/**
 * 特效
 */

class EffectView: public QWidget
{
    Q_OBJECT
public:
    explicit EffectView(QWidget *parent = 0);

signals:

public slots:
private:
    QGridLayout      *m_globalLay;
    QPushButton      *m_btnLeftEnter,*m_btnTopEnter,*m_btnRightEnter,*m_btnBottomEnter,
                     *m_btnLeftTopEnter,*m_btnRightTopEnter,*m_btnRightBottomEnter,*m_btnLeftBottomEnter,
                     *m_btnFadeIn,*m_btnFadeOut;
private:
    void init();
    bool event(QEvent *);

};

/**
 * 画面分割
 */

class CutView: public QWidget
{
    Q_OBJECT
public:
    explicit CutView(QWidget *parent = 0);

signals:

public slots:
private:
    QPushButton    m_btnOnlyOnce,m_btnMainSubMix,m_btnMainSubDevide,m_btnDoubleMain,
                   m_btnLeftTwoRightOne,m_btnLeftOneRightTwo,m_btnTopOneBottomTwo,m_btnFourMain,
                   m_btnFive,m_btnU1,m_btnU2,m_btnU3;
    QGridLayout    *m_globalLay;
    QButtonGroup   *m_grp;

private:
    void init();
    bool event(QEvent *);
};




#endif // VIDEOEFFECTVIEW_H
