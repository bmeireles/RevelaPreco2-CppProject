#include "listviewdelegate.h"

#include <QApplication>
#include <QPainter>

ListViewDelegate::ListViewDelegate(QObject* parent) : QStyledItemDelegate(parent)
{

}

void ListViewDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();

    if (option.showDecorationSelected && (option.state & QStyle::State_Selected)){
        painter->fillRect(option.rect, option.palette.highlight().color());
    }

    QIcon icon = qvariant_cast<QIcon>(index.data(Qt::DecorationRole));
    QSize iconsize = icon.actualSize(option.decorationSize);
    QPixmap pixmap = icon.pixmap(iconsize.width(), iconsize.height());
    painter->drawPixmap(option.rect.left(), option.rect.top(), pixmap);

    QString title = qvariant_cast<QString>(index.data(ListViewDelegate::TitleRole));
    QRect titleRect = option.rect;
    titleRect.adjust(iconsize.width(), 0, -iconsize.width(), 0);
    painter->drawText(titleRect, title);

    QFontMetrics fm(QApplication::font());

    QString text = qvariant_cast<QString>(index.data(ListViewDelegate::TextRole));
    QRect textRect = option.rect;
    textRect.adjust(iconsize.width(), fm.height(), -iconsize.width(), 0);
    painter->drawText(textRect, text);

    painter->restore();
}

QSize ListViewDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QIcon icon = qvariant_cast<QIcon>(index.data(Qt::DecorationRole));
    QSize iconsize = icon.actualSize(option.decorationSize);
    QFont font = QApplication::font();
    QFontMetrics fm(font);

    return QSize(iconsize.width(), iconsize.height() + fm.height());
}
