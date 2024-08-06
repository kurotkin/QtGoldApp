#ifndef CUSTOMDELEGATE_H
#define CUSTOMDELEGATE_H
#include <QStyledItemDelegate>


class CustomDelegate : public QStyledItemDelegate
{
     using BaseClass = QStyledItemDelegate;
public:
    CustomDelegate(QObject* parent = nullptr);
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // CUSTOMDELEGATE_H
