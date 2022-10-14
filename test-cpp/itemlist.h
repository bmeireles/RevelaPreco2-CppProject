#pragma once

#include <QString>
#include <QHash>
#include <QJsonObject>
#include <QStandardItemModel>

struct Item {
    QString id;
    QString name;
    double price;
    QString pictureFilePath;

    QJsonObject toJson() const;
    void fromJson(const QJsonObject& obj);
};

// A list of items
class ItemList
{
public:
    ItemList();

    void loadFromFile(const QString& filePath);
//    void loadFromDB();
//    void saveToFile(const QString& filePath);
//    void saveToDB();

    void addItem(const Item& item);
    void removeItem(const QString& id);
    void updateItem(const Item& item);
    int findItem(const QString& id);
    QList<Item>& getItems();

private:
    QList<Item> items;
};

class ItemModel: public QStandardItemModel {
public:
    ItemModel(QObject* parent = nullptr);

    // Copy the data from ItemList to the model
    void setList(ItemList* list);
};

//class ItemModel: public QAbstractTableModel {
//public:
//    ItemModel(QObject* parent = nullptr);

//    void setList(ItemList* list);
//    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
//    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
//    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
//    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

//private:
//    ItemList* list{nullptr};
//};
