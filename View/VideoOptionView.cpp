#include "VideoOptionView.h"

#include <QLabel>
#include <QRgb>

VideoOptionView::VideoOptionView(QWidget *parent) :
    QTabWidget(parent),m_videowidget(NULL)
{
    init();
}


void VideoOptionView::init()
{
    m_soundView = new SoundView(this);
    m_subTitleView = new SubTitleView(this);
    this->addTab(m_subTitleView,"Subtitle");
    this->addTab(m_soundView,"Sound");

}

void VideoOptionView::setVideo(VideoWidget *video)
{
    m_videowidget = video;
}




/**************************************************************/


SubTitleView::SubTitleView(QWidget* parent):
    QWidget(parent),m_labSubTitleContent(tr("SubTitle Content")),
    m_labSubTitlePoint(tr("SubTitle Point")),m_labSubTitleSize(tr("SubTitle Size")),
    m_labSubTitleColor(tr("SubTitle Color")),m_currentColor(0,0,0)
{
    init();
}


void SubTitleView::init()
{
    m_globalLay = new QGridLayout(this);

    m_editSubTitle = new QLineEdit(this);
    m_editLocal = new QLineEdit(this);
    m_editSize = new QLineEdit(this);
    m_editColor = new QLineEdit(this);

    m_btnSetting = new QPushButton(tr("set"),this);
    connect(m_btnSetting,SIGNAL(clicked()),this,SLOT(onSet()));
    m_btnColorPanel = new QPushButton(tr("color"),this);
    connect(m_btnColorPanel,SIGNAL(clicked()),this,SLOT(onOpenColor()));

    m_globalLay->addWidget(&m_labSubTitleContent,0,0);
    m_globalLay->addWidget(m_editSubTitle,0,1,1,2);
    m_globalLay->addWidget(m_btnSetting,0,3);

    m_globalLay->addWidget(&m_labSubTitlePoint,1,0);
    m_globalLay->addWidget(m_editLocal,1,1,1,3);

    m_globalLay->addWidget(&m_labSubTitleSize,2,0);
    m_globalLay->addWidget(m_editSize,2,1,1,3);

    m_globalLay->addWidget(&m_labSubTitleColor,3,0);
    m_globalLay->addWidget(m_editColor,3,1,1,2);
    m_globalLay->addWidget(m_btnColorPanel,3,3);
    m_editColor->setText(m_currentColor.name());

    this->setLayout(m_globalLay);
}


void SubTitleView::onOpenColor()
{
   // m_currentColor=QColorDialog::getColor(m_currentColor,0,tr("select"),QColorDialog::NoButtons);

    QColorDialog ql;
    ql.setWindowFlags(Qt::WindowStaysOnTopHint);
    m_currentColor=ql.getColor(m_currentColor);

    m_editColor->setText(m_currentColor.name());
}

void SubTitleView::onSet()
{

}

/************************************************************/


SoundView::SoundView(QWidget* parent):
    QWidget(parent),lab_input(tr("Input")),lab_output(tr("Output")),
    lab_rtmp(tr("Rtmp")),lab_record(tr("Record"))
{

    m_globalLay = new QGridLayout(this);
    m_sldInputAudio  = new QSlider(Qt::Horizontal,this);
    m_sldInputAudio->setMinimum(0);
    m_sldInputAudio->setMaximum(100);
    m_sldInputAudio->setValue(50);

    m_sldOutputAudio  = new QSlider(Qt::Horizontal,this);
    m_sldOutputAudio->setMinimum(0);
    m_sldOutputAudio->setMaximum(100);
    m_sldOutputAudio->setValue(50);

    m_sldRtmpStreamAudio  = new QSlider(Qt::Horizontal,this);
    m_sldRtmpStreamAudio->setMinimum(0);
    m_sldRtmpStreamAudio->setMaximum(100);
    m_sldRtmpStreamAudio->setValue(50);

    m_sldRecordAudio  = new QSlider(Qt::Horizontal,this);
    m_sldRecordAudio->setMinimum(0);
    m_sldRecordAudio->setMaximum(100);
    m_sldRecordAudio->setValue(50);


    m_globalLay->addWidget(&lab_input,0,0,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(&lab_output,1,0,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(&lab_rtmp,2,0,1,1,Qt::AlignCenter);
    m_globalLay->addWidget(&lab_record,3,0,1,1,Qt::AlignCenter);

    m_globalLay->addWidget(m_sldInputAudio,0,1,1,3);
    m_globalLay->addWidget(m_sldOutputAudio,1,1,1,3);
    m_globalLay->addWidget(m_sldRtmpStreamAudio,2,1,1,3);
    m_globalLay->addWidget(m_sldRecordAudio,3,1,1,3);
    this->setLayout(m_globalLay);

}
