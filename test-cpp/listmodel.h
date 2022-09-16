#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QStandardItemModel>

class ListModel : public QStandardItemModel
{
public:
    ListModel(QObject* parent = nullptr);
};

#endif // LISTMODEL_H
