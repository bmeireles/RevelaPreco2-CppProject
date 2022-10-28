#pragma once

#include <QStyleOptionViewItem>
#include <QStyledItemDelegate>

class ListViewDelegate : public QStyledItemDelegate
{
public:
    ListViewDelegate(QObject* parent = nullptr);

    enum DataRole {
        TitleRole = Qt::UserRole + 1,
        TextRole,
        UrlRole,
    };

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex&index) const;
};
