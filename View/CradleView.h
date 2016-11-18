/**
 *
 * 云台控制视图
 *
 *
 */

#ifndef GRADLE_VIEW_H
#define GRADLE_VIEW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QSlider>
//#include <QVector>
#include <QLabel>
#include <QButtonGroup>

class GradleView :public QWidget
{
    Q_OBJECT
public:
    explicit GradleView(QWidget *parent=0);
    ~GradleView();
signals:
private slots:
    void onLeft();
    void onRight();
    void onUp();
    void onDown();
    void onHome();
    void onZoomUp();
    void onZoomDown();
    void onStop();
    void updateSpeed(int);
    void updateZoom();
protected:
    QPushButton *m_btnLeft,*m_btnRight,*m_btnUp,*m_btnDown,*m_btnHome,
                *m_btnZoomUp,*m_btnZoomDown;
    QSlider     *m_sldZoom,*m_sldSpeed;
    QPushButton  m_arryBtnPreCall[8],m_arryBtnPix[6];
    QLabel       m_labTitle,m_labSpeed;
    QGridLayout  *m_globalLay;
    QButtonGroup *m_grpPrecall,*m_grpPixel;
private:
    int          m_speed;
    int          m_preCall;
    int          m_pixel;

public:
    int getSpeed()const;
    int getPreCall()const;
    int getPixel()const;

};


#endif
