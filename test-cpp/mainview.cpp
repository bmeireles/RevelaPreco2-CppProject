#include "mainview.h"
#include "listviewdelegate.h"
#include "linklabel.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QStackedWidget>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QPushButton>

MainView::MainView(QWidget *parent)
    : QWidget{parent}
{
    stackedWidget = new QStackedWidget(); //create a stakedwidget in the mainview
    auto overviewPage = new QWidget(); //create an overview window for all the products
    stackedWidget->addWidget(overviewPage); //add the overviewpage to the stack
    detailedPage = new CustomizableDetailedPage(); //create a detailed page for extra info about the products
    stackedWidget->addWidget(detailedPage); //add the detailedpage to the stack

    // overview page
    QVBoxLayout* overviewLayout = new QVBoxLayout(overviewPage);

    itemList = new ItemList();
    itemList->loadFromFile("items.json");

    model = new ItemModel(this);
    model->setList(itemList);

    view = new QListView();
    overviewLayout->addWidget(view);

    view->setModel(model);
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);

    auto listdelegate = new ListViewDelegate(nullptr);
    view->setItemDelegate(listdelegate);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(stackedWidget);

    connect(view, &QListView::clicked, this, &MainView::onItemClicked);

    // Detailed page
    detailedPage->addField("Name", new QLineEdit);
    detailedPage->addField("Price", new QDoubleSpinBox);
    detailedPage->addField("Picture", new QLabel);
    detailedPage->addField("Url", new LinkLabel);
    connect(detailedPage, &CustomizableDetailedPage::backButtonClicked, this, [this]() {
        stackedWidget->setCurrentIndex(0);
    });
}

void MainView::onItemClicked(const QModelIndex &index)
{
    if (!index.isValid())
        return;

    stackedWidget->setCurrentIndex(1);

    // "copy" the data to the detailed page
    detailedPage->setData("Name", index.data(ListViewDelegate::DataRole::TitleRole).toString());
    detailedPage->setData("Price", index.data(ListViewDelegate::DataRole::TextRole).toDouble());
    detailedPage->setData("Picture", index.data(Qt::DecorationRole).value<QIcon>());
    detailedPage->setData("Url", index.data(ListViewDelegate::DataRole::UrlRole).toString());
}
