#ifndef DETAILEDPAGE_H
#define DETAILEDPAGE_H

#include "linklabel.h"

#include <QWidget>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QModelIndex>

class DetailedPage : public QWidget
{
Q_OBJECT

public:
    DetailedPage(QWidget *parent = NULL);
    void setData(const QModelIndex& index);

signals:
    void backButtonClicked();

private:
    QModelIndex currentIndex;
    LinkLabel* urlLabel{nullptr};
    QLineEdit* nameEdit{nullptr};
    QDoubleSpinBox* priceEdit{nullptr};
    QLineEdit* companyEdit{nullptr};
    QLabel* pictureView{nullptr};
};

#endif // DETAILEDPAGE_H
