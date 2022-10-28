#include "itemlist.h"
#include "listviewdelegate.h"

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
    if (findItem(item.id) != -1)
        return;

    items.append(item);
}

void ItemList::removeItem(const QString &id)
{
    int index = findItem(id);
    items.remove(index);
}

void ItemList::updateItem(const Item &item)
{
    int index = findItem(item.id);
    if (index == -1)
        return;

    items[index] = item;
}

int ItemList::findItem(const QString& id)
{
    int index = 0;
    for (const auto& item: items) {
        if (item.id == id)
            return index;
        index ++;
    }
    return -1;
}

QList<Item>& ItemList::getItems() {
    return items;
}

QJsonObject Item::toJson() const
{
    QJsonObject obj;
    obj["id"] = id;
    obj["name"] = name;
    obj["price"] = price;
    obj["pictureFilePath"] = pictureFilePath;
    obj["itemURL"] = itemUrl;
    return obj;
}

void Item::fromJson(const QJsonObject &obj)
{
    // TODO: Check if all the fields exist
    if (!obj.contains("id")) {
        qDebug() << "The field id in " << obj << " doesn't exist";
        return;
    }
    id = obj["id"].toString();

    if (!obj.contains("name")) {
        qDebug() << "The field name in " << obj << " doesn't exist";
        return;
    }
    name = obj["name"].toString();

    if (!obj.contains("price")) {
        qDebug() << "The field price in " << obj << " doesn't exist";
        return;
    }
    price = obj["price"].toDouble();

    if (!obj.contains("pictureFilePath")) {
        qDebug() << "The field pictureFilePath in " << obj << " doesn't exist";
        return;
    }
    pictureFilePath = obj["pictureFilePath"].toString();

    if (!obj.contains("itemUrl")) {
        qDebug() << "The field itemUrl in " << obj << " doesn't exist";
        return;
    }
    itemUrl = obj["itemUrl"].toString();
}

ItemModel::ItemModel(QObject *parent) : QStandardItemModel(parent)
{

}

//void ItemModel::setList(ItemList *list)
//{
//    this->list = list;
//}

//int ItemModel::rowCount(const QModelIndex &parent) const
//{
//    return list->getItems().count();
//}

//int ItemModel::columnCount(const QModelIndex& parent) const
//{
//    return 4;
//}

//QVariant ItemModel::data(const QModelIndex& index, int role) const
//{
//    if (!index.isValid())
//        return {};

//    if (role != Qt::DisplayRole)
//        return {};

//    auto data = list->getItems();
//    switch (index.column()) {
//    case 0:
//        return data[index.row()].id;
//    case 1:
//        return data[index.row()].name;
//    case 2:
//        return data[index.row()].price;
//    case 3:
//        return data[index.row()].pictureFilePath;
//    }
//    return {};
//}

//QVariant ItemModel::headerData(int section, Qt::Orientation orientation, int role) const
//{
//    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
//        switch (section) {
//        case 0:
//            return QString("ID");
//        case 1:
//            return QString("Name");
//        case 2:
//            return QString("Price");
//        case 3:
//            return QString("Picture");
//        }
//    }
//    return QVariant();
//}

void ItemModel::setList(ItemList* list)
{
    auto data = list->getItems();
    setColumnCount(5);
    setHorizontalHeaderLabels(QStringList{"ID", "Name", "Price", "Picture", "URL"});
    setRowCount(data.count());

    int row = 0;
    for (auto itr = data.begin(); itr != data.end(); itr ++) {
        setData(index(row, 0), itr->id);
        setData(index(row, 0), itr->name, ListViewDelegate::DataRole::TitleRole);
        setData(index(row, 0), itr->price, ListViewDelegate::DataRole::TextRole);
        QIcon icon(itr->pictureFilePath);
        setData(index(row, 0), icon, Qt::DecorationRole);
        setData(index(row, 0), itr->itemUrl, ListViewDelegate::DataRole::UrlRole);
        row ++;
    }
}
