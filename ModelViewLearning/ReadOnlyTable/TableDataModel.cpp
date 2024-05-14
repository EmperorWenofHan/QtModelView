#include "TableDataModel.h"

TableDataModel::TableDataModel(QObject* parent /*= nulllpte*/)
    : QAbstractTableModel(parent)
{

}

int TableDataModel::rowCount(const QModelIndex& parent /*= QModelIndex()*/) const
{
    return 2;
}

int TableDataModel::columnCount(const QModelIndex& parent /*= QModelIndex()*/) const
{
    return 3;
}

QVariant TableDataModel::data(const QModelIndex& index, int role /*= Qt::DisplayRole*/) const
{
    if (Qt::DisplayRole == role)
    {
        return QString("Row%1 , Column%2")
            .arg(index.row() + 1)
            .arg(index.column() + 1);
    }
    return QVariant();
}
