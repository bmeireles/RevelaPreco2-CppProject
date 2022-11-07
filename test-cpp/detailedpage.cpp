#include "detailedpage.h"


DetailedPage::DetailedPage(QWidget *parent) : QWidget(parent) {
    QPushButton* backButton = new QPushButton("<--");
    QLineEdit* nameEdit = new QLineEdit();
    QDoubleSpinBox* priceEdit = new QDoubleSpinBox();
    QLineEdit* companyEdit = new QLineEdit();
    QLabel* pictureView = new QLabel();
    //LinkLabel* urlLabel = new LinkLabel(); //unknown type linklabel

    QVBoxLayout* detailedLayout = new QVBoxLayout();
    detailedLayout->addWidget(backButton);
    detailedLayout->addWidget(nameEdit);
    detailedLayout->addWidget(priceEdit);
    detailedLayout->addWidget(companyEdit);
    detailedLayout->addWidget(pictureView);
    //detailedLayout->addWidget(urlLabel);
    detailedLayout->addStretch();
    this->setLayout(detailedLayout);
}
