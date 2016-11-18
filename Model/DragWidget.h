#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
class QLabel;
QT_END_NAMESPACE

class DragWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DragWidget(QWidget *parent = 0);
    QPoint getImgPos()const;
    void setImg(const QString& fileName);
    void setFixImgSize(const QSize& size);

signals:

public slots:
private:
    QLabel  *m_labshow;
    QPoint   m_point;
    QSize    m_size;
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);
};

#endif // DRAGWIDGET_H
