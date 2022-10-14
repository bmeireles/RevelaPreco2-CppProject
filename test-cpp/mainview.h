#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "itemlist.h"

#include <QListView>
#include <QStackedWidget>
#include <QWidget>

class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = nullptr);

private:
    void onItemClicked(const QModelIndex &index);

private:
    ItemList* itemList{nullptr};
    ItemModel* model{nullptr};
    QListView* view{nullptr};
    QStackedWidget* stackedWidget{nullptr};
};

#endif // MAINVIEW_H
