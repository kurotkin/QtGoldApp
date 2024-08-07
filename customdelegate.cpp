#include "customdelegate.h"

#include <QPainter>
#include <QAbstractItemView>
#include <QDebug>

CustomDelegate::CustomDelegate(QObject* parent) : BaseClass(parent)
{ }

void CustomDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    double changePrice = index.model()->data(index, Qt::DisplayRole).toReal();

    if(changePrice > 0.0){
        painter->fillRect(option.rect, Qt::green);
        BaseClass::paint(painter, option, index);
    }

    if(changePrice < 0.0){
        painter->fillRect(option.rect, Qt::red);
        BaseClass::paint(painter, option, index);
    }
}
