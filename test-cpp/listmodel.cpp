#include "listmodel.h"

ListModel::ListModel(QObject *parent) : QStandardItemModel(parent)
{
    setRowCount(7);
    setColumnCount(1);
    setData(index(0, 0), "Main");
    setData(index(1, 0), "Scan");
    setData(index(2, 0), "Cart");
    setData(index(3, 0), "Wishlist");
    setData(index(4, 0), "Companies");
    setData(index(5, 0), "Settings");
    setData(index(6, 0), "Quit");

    setData(index(0, 0), QIcon(":/images/home_icon.png"), Qt::DecorationRole);
    setData(index(1, 0), QIcon(":/images/qrcode_icon.png"), Qt::DecorationRole);
    setData(index(2, 0), QIcon(":/images/Cart.png"), Qt::DecorationRole);
    setData(index(3, 0), QIcon(":/images/wishlist.png"), Qt::DecorationRole);
    setData(index(4, 0), QIcon(":/images/companies.png"), Qt::DecorationRole);
    setData(index(5, 0), QIcon(":/images/settings_icon.png"), Qt::DecorationRole);
    setData(index(6, 0), QIcon(":/images/quit_icon.png"), Qt::DecorationRole);

}
