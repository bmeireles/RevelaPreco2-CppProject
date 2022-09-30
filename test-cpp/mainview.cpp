#include "mainview.h"

#include <QVBoxLayout>
#include <QLabel>

MainView::MainView(QWidget *parent)
    : QWidget{parent}
{
    QLabel* label = new QLabel("Main View 2");
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(label);

    itemList = new ItemList();
    itemList->loadFromFile("items.json");
}
