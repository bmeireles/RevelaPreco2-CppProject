#include "linklabel.h"

#include <QDesktopServices>

LinkLabel::LinkLabel(QWidget *parent) : QLabel(parent)
{
    setPixmap(QIcon(":/images/map.png").pixmap(32, 32));
}

void LinkLabel::setUrl(const QUrl &url)
{
    this->url = url;
}

void LinkLabel::mousePressEvent(QMouseEvent*ev)
{
    QDesktopServices::openUrl(url);
    QLabel::mousePressEvent(ev);
}
