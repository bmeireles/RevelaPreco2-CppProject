#include "customizabledetailedpage.h"
#include "linklabel.h"

#include <QDoubleSpinBox>
#include <QLabel>
#include <QLineEdit>
#include <QUrl>

CustomizableDetailedPage::CustomizableDetailedPage(QWidget *parent)
    : QWidget{parent}
{
    layout = new QVBoxLayout(this);

    backButton = new QPushButton("Back");
    layout->addWidget(backButton);
    connect(backButton, &QPushButton::clicked, this, &CustomizableDetailedPage::backButtonClicked);
}

void CustomizableDetailedPage::addField(const QString &name, QWidget *widget)
{
    fields[name] = widget;

    auto label = new QLabel(name);
    auto hLayout = new QHBoxLayout;
    hLayout->addWidget(label);
    hLayout->addWidget(widget);
    layout->addLayout(hLayout);
}

void CustomizableDetailedPage::setData(const QString& name, const QVariant& data)
{
    if (!fields.contains(name))
        return;

    auto widget = fields[name];
    if (auto lineEdit = dynamic_cast<QLineEdit*>(widget)) {
        lineEdit->setText(data.toString());
    }
    else if (auto spinBox = dynamic_cast<QDoubleSpinBox*>(widget)) {
        spinBox->setValue(data.toDouble());
    }
    else if (auto url = dynamic_cast<LinkLabel*>(widget)) {
        url->setUrl(QUrl(data.toString()));
    }
    else if (auto label = dynamic_cast<QLabel*>(widget)) {
        label->setPixmap(data.value<QIcon>().pixmap(100, 100));
    }
}
