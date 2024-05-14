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
    int row = index.row();
    int col = index.column();

    switch (role)
    {
    case Qt::DisplayRole:
    {
        return m_gridData[index.row()][index.column()];
    }
    default:
        break;
    }
    return QVariant();
}

bool TableDataModel::setData(const QModelIndex& index, const QVariant& value, int role /*= Qt::EditRole*/)
{
    if (role == Qt::EditRole)
    {
        m_gridData[index.row()][index.column()] = value.toString();
        QString result = m_gridData[index.row()][index.column()];
        emit editCompleted(result);
    }
    return true;
}

Qt::ItemFlags TableDataModel::flags(const QModelIndex& index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}