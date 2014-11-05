#include "treemodel.h"

TreeModel::TreeModel(QObject *parent) :
    QAbstractItemModel(parent)
{
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return this->createIndex(row, column);
}

QModelIndex TreeModel::parent(const QModelIndex & index) const
{
    Q_UNUSED(index);
    return QModelIndex();
}

int TreeModel::rowCount(const QModelIndex & parent) const
{
    if (!parent.isValid()) {
        return 2;
    }

    return 0;
}

int TreeModel::columnCount(const QModelIndex & parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant TreeModel::data(const QModelIndex & index, int role) const
{
    if (index.isValid()) {
        if (Qt::DisplayRole == role) {
            return QString("testItem_" + QString("%1_%2").arg(index.row()).arg(index.column()));
        }
    }

    return QVariant();
}
