#include "qmainwindowwidget.h"
#include <QMessageBox>
QMainWindowWidget::QMainWindowWidget(QWidget *parent)
    : QWidget(parent)
{

    grdview = new GradleView(this);
    vv = new VideoWidget(this);
    lay = new QVBoxLayout(this);
    lay->addWidget(vv);
    this->setLayout(lay);
}


void QMainWindowWidget::T()
{

}

void QMainWindowWidget::P()
{
  QMessageBox::about(this,"tip","pressed");
}
void QMainWindowWidget::C()
{
 QMessageBox::about(this,"tip","clicked");
}
QMainWindowWidget::~QMainWindowWidget()
{

}
