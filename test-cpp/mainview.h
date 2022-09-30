#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "itemlist.h"

#include <QWidget>

class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = nullptr);

signals:


private:
    ItemList* itemList{nullptr};
};

#endif // MAINVIEW_H
