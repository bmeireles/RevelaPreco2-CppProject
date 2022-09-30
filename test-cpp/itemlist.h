#pragma once

#include <QString>
#include <QHash>
#include <QJsonObject>

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

private:
    QHash<QString, Item> items;
};
