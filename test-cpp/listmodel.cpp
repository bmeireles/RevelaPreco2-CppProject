#include "listmodel.h"

ListModel::ListModel(QObject *parent) : QStandardItemModel(parent)
{
    setRowCount(5);
    setColumnCount(1);
    setData(index(0, 0), "Main");
    setData(index(1, 0), "Scan");
    setData(index(2, 0), "Cart");
    setData(index(3, 0), "Settings");
    setData(index(4, 0), "Quit");

    setData(index(2, 0), QIcon(":/Cart.png"), Qt::DecorationRole);
}
