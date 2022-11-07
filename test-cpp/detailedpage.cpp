#include "detailedpage.h"
#include "linklabel.h"
#include "itemlist.h"
#include "listviewdelegate.h"

DetailedPage::DetailedPage(QWidget *parent) : QWidget(parent) {
    QPushButton* backButton = new QPushButton("<--");
    nameEdit = new QLineEdit();
    priceEdit = new QDoubleSpinBox();
    companyEdit = new QLineEdit();
    pictureView = new QLabel();
    urlLabel = new LinkLabel(); //unknown type linklabel

    QVBoxLayout* detailedLayout = new QVBoxLayout();
    detailedLayout->addWidget(backButton);
    detailedLayout->addWidget(nameEdit);
    detailedLayout->addWidget(priceEdit);
    detailedLayout->addWidget(companyEdit);
    detailedLayout->addWidget(pictureView);
    detailedLayout->addWidget(urlLabel);
    detailedLayout->addStretch();
    this->setLayout(detailedLayout);

    connect(backButton, &QPushButton::clicked, this, &DetailedPage::backButtonClicked);
}

void DetailedPage::setData(const QModelIndex& index)
{
    currentIndex = index;
    auto id = index.data().toInt();
    auto name = index.data(ListViewDelegate::DataRole::TitleRole).toString();
    auto price = index.data(ListViewDelegate::DataRole::TextRole).toDouble();
    auto urlStr = index.data(ListViewDelegate::DataRole::UrlRole).toString();
    auto icon = index.data(Qt::DecorationRole).value<QIcon>();
    urlLabel->setUrl(QUrl(urlStr));
    nameEdit->setText(name);
    priceEdit->setValue(price);
    pictureView->setPixmap(icon.pixmap(100, 100));
}
