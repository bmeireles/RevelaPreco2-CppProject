#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "itemlist.h"

#include <QTableView>
#include <QWidget>

class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = nullptr);

signals:


private:
    ItemList* itemList{nullptr};
    ItemModel* model{nullptr};
    QTableView* view{nullptr};
};

#endif // MAINVIEW_H
