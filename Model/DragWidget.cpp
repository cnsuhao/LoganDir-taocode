#include "DragWidget.h"

#include <QLabel>

#include <QMimeData>
#include <QDragEnterEvent>
#include <QDropEvent>
DragWidget::DragWidget(QWidget *parent) :
    QWidget(parent),m_size(60,30)
{
     m_labshow = new QLabel("1",this);
     //setImg(":/Skin/logo");
     //setFixImgSize(QSize(100,30));
     setAcceptDrops(true);
}


void DragWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasText()) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void DragWidget::dropEvent(QDropEvent *event)
{
     QString s;
    if ((event->mimeData()->hasText() ||event->mimeData()->hasImage())&& event->pos().x()>0 && event->pos().y()>0) {
        const QMimeData *mime = event->mimeData();
        QStringList pieces = mime->text().split(QRegExp("\\s+"),
                             QString::SkipEmptyParts);
        QPoint position = event->pos();
        QPoint hotSpot;

        QList<QByteArray> hotSpotPos = mime->data("application/x-hotspot").split(' ');
        if (hotSpotPos.size() == 2) {
            hotSpot.setX(hotSpotPos.first().toInt());
            hotSpot.setY(hotSpotPos.last().toInt());
            m_point = hotSpot;
        }

        if(event->mimeData()->hasImage())
        {
             const QMimeData *mime = event->mimeData();
             s=mime->imageData().toString();
        }
        foreach (QString piece, pieces) {
            QLabel *newLabel = new QLabel(piece, this);
            newLabel->move(position - hotSpot);
            newLabel->show();
            newLabel->setFixedSize(m_size);
            QString str =QString("%1,%2").arg(newLabel->pos().x()).arg(newLabel->pos().y());
            newLabel->setToolTip(str);
            newLabel->setStyleSheet(s);
            newLabel->setAttribute(Qt::WA_DeleteOnClose);

            position += QPoint(newLabel->width(), 0);
        }

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
    foreach (QObject *child, children()) {
        if (child->inherits("QWidget")) {
            QWidget *widget = static_cast<QWidget *>(child);
            if (!widget->isVisible())
                widget->deleteLater();
        }
    }
}

void DragWidget::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if (!child)
        return;

    QPoint hotSpot = event->pos() - child->pos();

    QMimeData *mimeData = new QMimeData;
    mimeData->setText(child->text());
    mimeData->setImageData(child->styleSheet());
    mimeData->setData("application/x-hotspot",
                      QByteArray::number(hotSpot.x())
                      + " " + QByteArray::number(hotSpot.y()));

    QPixmap pixmap(child->size());
//    QSize s=child->size();
//    s.setHeight(s.height()-20);
//     QPixmap pixmap(s);
    child->render(&pixmap);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(hotSpot);

    Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);

    if (dropAction == Qt::MoveAction)
        child->close();
}


QPoint DragWidget::getImgPos()const
{
    return m_point;
}
void DragWidget::setImg(const QString& fileName)
{
    QString s=QString("QLabel{image: url(%1)};").arg(fileName);
    m_labshow->setStyleSheet(s);
}
void DragWidget::setFixImgSize(const QSize& size)
{
   // if(size.width()!=0 &&size.height()!=0)
    {
        m_labshow->setFixedSize(size);
        m_size = size;

    }
}
