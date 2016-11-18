#ifndef SUBVIDEOSWITCHVIEW_H
#define SUBVIDEOSWITCHVIEW_H

/******************************************
 *
 *   可以动画切换的视频切换控件
 *
 ******************************************/

#include <QWidget>
#include <QAnimationGroup>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QQueue>
#include <QPushButton>
#include <QHBoxLayout>
#include "Model/VideoWidget.h"
#include <QEvent>

#define VIDEO_SIZE  7


class SubVideoSwitchView : public QWidget
{
    Q_OBJECT
public:
    explicit SubVideoSwitchView(QWidget *parent = 0);
    ~SubVideoSwitchView();
signals:

private slots:
    void onLeftSwitch();
    void onRightSwitch();
    void singleSelect(QWidget*);
private:
    QQueue<VideoWidget*>   m_queueVideo;
    QPushButton     *m_btnLeft,*m_btnRight;
    QHBoxLayout     *m_globalLay;
    VideoWidget     *m_selectedVideo;
private:
    void dealvideo();
    void leftAnimation();
    void rightAnimation();
    bool event(QEvent *);
public:
    int getVideoCount()const;
    VideoWidget* getCurrentSelectedVideo()const;

};

#endif // SUBVIDEOSWITCHVIEW_H
