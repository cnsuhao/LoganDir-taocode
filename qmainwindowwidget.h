#ifndef QMAINWINDOWWIDGET_H
#define QMAINWINDOWWIDGET_H

#include <QWidget>
#include "Model/VideoWidget.h"
#include <QVBoxLayout>
#include <QPushButton>

#include "View/CradleView.h"


class QMainWindowWidget : public QWidget
{
    Q_OBJECT

public:
    QMainWindowWidget(QWidget *parent = 0);
    ~QMainWindowWidget();
    GradleView *grdview;
    VideoWidget *vv;
    QVBoxLayout *lay;
private slots:
    void P();
    void C();
    void T();
};

#endif // QMAINWINDOWWIDGET_H
