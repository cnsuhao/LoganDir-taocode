#ifndef VIDEOOPTIONVIEW_H
#define VIDEOOPTIONVIEW_H

#include <QWidget>
#include <QTabWidget>
#include "Model/VideoWidget.h"
#include <QColorDialog>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QColor>
#include <QFormLayout>
#include <QSlider>
#include <QComboBox>

/******************************************
 *
 *   视频选项
 *  字幕    声音
 *
 ******************************************/

class SubTitleView;
class SoundView;


class VideoOptionView : public QTabWidget
{
    Q_OBJECT
    friend class SubTitleView;
    friend class SoundView;
public:
    explicit VideoOptionView(QWidget *parent = 0);
    void setVideo(VideoWidget* video);
signals:

public slots:
private:
    void init();
private:
    SubTitleView     *m_subTitleView;
    SoundView        *m_soundView;
    VideoWidget      *m_videowidget;

};


/**
 * 字幕
 */

class SubTitleView: public QWidget
{
    Q_OBJECT
public:
    explicit SubTitleView(QWidget *parent = 0);

signals:

public slots:
private slots:
    void onOpenColor();
    void onSet();
private:
    QGridLayout    *m_globalLay;
    QPushButton    *m_btnSetting,*m_btnColorPanel;
    QLineEdit      *m_editSubTitle,*m_editLocal,*m_editSize,*m_editColor;
    QLabel          m_labSubTitleContent,m_labSubTitlePoint,m_labSubTitleSize,m_labSubTitleColor;

    QColor          m_currentColor;
private:
    void init();

};
/**
 * 声音
 */

class SoundView: public QWidget
{
    Q_OBJECT
public:
    explicit SoundView(QWidget *parent = 0);

signals:

public slots:
private:
    QSlider   *m_sldInputAudio,*m_sldOutputAudio,*m_sldRtmpStreamAudio,*m_sldRecordAudio;
    QLabel    lab_input,lab_output,lab_rtmp,lab_record;
    QGridLayout *m_globalLay;

};

#endif // VIDEOOPTIONVIEW_H
