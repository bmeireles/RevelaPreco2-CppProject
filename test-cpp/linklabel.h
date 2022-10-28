#ifndef LINKLABEL_H
#define LINKLABEL_H

#include <QLabel>
#include <QUrl>

class LinkLabel : public QLabel
{
public:
    LinkLabel(QWidget *parent = nullptr);
    void setUrl(const QUrl& url);

protected:
    void mousePressEvent(QMouseEvent *ev) override;

private:
    QUrl url;
};

#endif // LINKLABEL_H
