#ifndef CUSTOMIZABLEDETAILEDPAGE_H
#define CUSTOMIZABLEDETAILEDPAGE_H

#include <QWidget>
#include <QMap>
#include <QVBoxLayout>
#include <QPushButton>

class CustomizableDetailedPage : public QWidget
{
    Q_OBJECT
public:
    explicit CustomizableDetailedPage(QWidget *parent = nullptr);

    void addField(const QString& name, QWidget* widget);
    void setData(const QString& name, const QVariant& data);

signals:
    void backButtonClicked();

private:
    QMap<QString, QWidget*> fields;
    QVBoxLayout* layout{nullptr};
    QPushButton* backButton{nullptr};
};

#endif // CUSTOMIZABLEDETAILEDPAGE_H
