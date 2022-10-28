#include "mainview.h"
#include "listviewdelegate.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QStackedWidget>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QPushButton>

MainView::MainView(QWidget *parent)
    : QWidget{parent}
{
    stackedWidget = new QStackedWidget();
    auto overviewPage = new QWidget();
    auto detailedPage = new QWidget();
    stackedWidget->addWidget(overviewPage);
    stackedWidget->addWidget(detailedPage);

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

    // Detailed page
    // TODO: make detailed page a separate class
    QVBoxLayout* detailedLayout = new QVBoxLayout(detailedPage);
    auto backButton = new QPushButton("<--");
    auto nameEdit = new QLineEdit();
    auto priceEdit = new QDoubleSpinBox();
    auto companyEdit = new QLineEdit();
    auto pictureView = new QLabel();
    detailedLayout->addWidget(backButton);
    detailedLayout->addWidget(nameEdit);
    detailedLayout->addWidget(priceEdit);
    detailedLayout->addWidget(companyEdit);
    detailedLayout->addWidget(pictureView);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(stackedWidget);

    connect(view, &QListView::clicked, this, &MainView::onItemClicked);
    connect(backButton, &QPushButton::clicked, this, [this]() {
       stackedWidget->setCurrentIndex(0);
    });
}

void MainView::onItemClicked(const QModelIndex &index)
{
    if (!index.isValid())
        return;

    stackedWidget->setCurrentIndex(1);

    // TODO: copy the data to the detailed page
}
