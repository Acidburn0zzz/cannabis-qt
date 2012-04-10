#ifndef MYDATEEDIT_H
#define MYDATEEDIT_H

#include <QDateEdit>
#include <QStyledItemDelegate>

class MyDateEditDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit MyDateEditDelegate(QObject *parent = 0);

    QWidget * createEditor(QWidget*parent,const QStyleOptionViewItem &opcion,
                            const QModelIndex &index) const;

    void setEditorData(QWidget *editor,const QModelIndex &index) const;

    void setModelData(QWidget* editor,QAbstractItemModel *model,
                        const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                                const QModelIndex &index) const;

    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

signals:
    
public slots:
    
};

#endif // MYDATEEDIT_H
