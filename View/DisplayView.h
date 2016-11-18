#ifndef DISPLAYVIEW_H
#define DISPLAYVIEW_H

/******************************************
 *
 *   快捷操作显示视图
 *
 ******************************************/


#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QTimer>

class DisplayView : public QWidget
{
    Q_OBJECT
public:
    explicit DisplayView(QWidget *parent = 0);

signals:

public slots:
private slots:
    void onOnekey();
    void onPause();
    void onStop();
    void RecordTime();
private:
    QPushButton   *m_btnMovieMode,*m_btnResolution,*m_btnLive,*m_btnRecord,
                  *m_btnOneKey,*m_btnPause,*m_btnStop,*m_btnAuto,*m_btnSelfAuto,*m_btnmanual;


    QGridLayout   *m_globalLay;
    QHBoxLayout   *m_hormanualLay;

    QTimer        *m_recordTime;
    quint64        m_timeload;


};

#endif // DISPLAYVIEW_H
