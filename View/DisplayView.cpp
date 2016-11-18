#include "DisplayView.h"

#include <QTime>

DisplayView::DisplayView(QWidget *parent) :
    QWidget(parent),m_timeload(0)
{
    m_globalLay = new QGridLayout(this);

    m_btnMovieMode = new QPushButton("PGM",this);
    m_btnResolution = new QPushButton("Resolution",this);
    m_btnLive = new QPushButton("Live",this);
    m_btnRecord = new QPushButton("Record",this);

    m_globalLay->addWidget(m_btnMovieMode,0,0);
    m_globalLay->addWidget(m_btnResolution,0,1);
    m_globalLay->addWidget(m_btnLive,0,2);
    m_globalLay->addWidget(m_btnRecord,0,3);

    m_btnOneKey = new QPushButton("OneKey",this);
    connect(m_btnOneKey,SIGNAL(clicked()),this,SLOT(onOnekey()));
    m_globalLay->addWidget(m_btnOneKey,1,1,1,2);

    m_btnPause = new QPushButton("pause",this);
    connect(m_btnPause,SIGNAL(clicked()),this,SLOT(onPause()));
    m_btnPause->setVisible(false);
    m_globalLay->addWidget(m_btnPause,2,1);

    m_btnStop = new QPushButton("Stop",this);
    connect(m_btnStop,SIGNAL(clicked()),this,SLOT(onStop()));
    m_btnStop->setVisible(false);
    m_globalLay->addWidget(m_btnStop,2,2);

    m_hormanualLay = new QHBoxLayout();
    m_hormanualLay->setMargin(0);
    m_hormanualLay->setSpacing(0);
    m_btnmanual = new QPushButton("Manual",this);
    m_btnSelfAuto = new QPushButton("Self-Auto",this);
    m_btnAuto = new QPushButton("Auto",this);

    m_hormanualLay->addWidget(m_btnmanual);
    m_hormanualLay->addWidget(m_btnSelfAuto);
    m_hormanualLay->addWidget(m_btnAuto);

    m_globalLay->addLayout(m_hormanualLay,3,0,1,4);

    m_globalLay->setSpacing(3);
    m_globalLay->setMargin(0);

    m_recordTime = new QTimer(this);
    connect(m_recordTime,SIGNAL(timeout()),this,SLOT(RecordTime()));


    this->setLayout(m_globalLay);
}






void DisplayView::onOnekey()
{
    m_btnPause->setVisible(true);
    m_btnStop->setVisible(true);
    m_btnOneKey->setEnabled(false);
    m_recordTime->start(999);
    m_btnOneKey->setText("00:00:00");


}

void DisplayView::onPause()
{
   if(m_recordTime->isActive())
   {
       m_recordTime->stop();
   }
   else
   {
       m_recordTime->start(999);
   }
}

void DisplayView::onStop()
{
    m_recordTime->stop();
    m_timeload = 0;
    m_btnOneKey->setEnabled(true);
    m_btnOneKey->setText("Onekey");

    m_btnPause->setVisible(false);
    m_btnStop->setVisible(false);
}

void DisplayView::RecordTime()
{
    ++m_timeload;
    QTime t(0,0,0);
    t=t.addSecs(m_timeload);
    m_btnOneKey->setText(t.toString("HH:mm:ss"));
}
