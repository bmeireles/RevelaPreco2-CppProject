#include "itemlist.h"

#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

ItemList::ItemList()
{

}

void ItemList::loadFromFile(const QString &filePath)
{
    if (!QFile::exists(filePath)) {
        qDebug() << "File " << filePath << " doesn't exist";
        return;
    }

    QFile file(filePath);
    if (!file.open(QFile::ReadOnly)) {
        qDebug() << "Can't open file " << filePath;
        return;
    }

    QByteArray data = file.readAll();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Json parse error " << parseError.errorString();
        return;
    }

    if (!jsonDoc.isArray()) {
        qDebug() << "The json file is not an array";
        return;
    }

    auto array = jsonDoc.array();
    for (const QJsonValue& value : array) {
        QJsonObject obj = value.toObject();
        Item item;
        item.fromJson(obj);
        addItem(item);
        qDebug() << item.toJson();
    }
}

void ItemList::addItem(const Item &item)
{
    if (items.contains(item.id))
        return;

    items[item.id] = item;
}

void ItemList::removeItem(const QString &id)
{
    items.remove(id);
}

void ItemList::updateItem(const Item &item)
{
    items[item.id] = item;
}

QJsonObject Item::toJson() const
{
    QJsonObject obj;
    obj["id"] = id;
    obj["name"] = name;
    obj["price"] = price;
    obj["pictureFilePath"] = pictureFilePath;
    return obj;
}

void Item::fromJson(const QJsonObject &obj)
{
    // TODO: Check if all the fields exist

    id = obj["id"].toString();
    name = obj["name"].toString();
    price = obj["price"].toDouble();
    pictureFilePath = obj["pictureFilePath"].toString();
}
