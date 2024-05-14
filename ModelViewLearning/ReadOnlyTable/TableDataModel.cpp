#include "TableDataModel.h"
#include <QFont>
#include <QBrush>

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
        if (row == 0 && col == 1) return QString("<--left");
        if (row == 1 && col == 1) return QString("right-->");

        return QString("Row%1 , Column%2")
            .arg(index.row() + 1)
            .arg(index.column() + 1);
        break;
    }
    case Qt::FontRole:
    {
        // 只改变（0,0）处的字体
        if (row == 0 && col == 0)
        {
            QFont boldFont;
            boldFont.setBold(true);
            return boldFont;
        }
        break;
    }
    case Qt::BackgroundRole:
    {
        // 只改变（1,2）处的颜色
        if (row == 1 && col == 2)  
        {
            QBrush redBackground(Qt::red);
            return redBackground;
        }
        break;
    }
    case Qt::TextAlignmentRole:
    {
        // 改变（1,1）处的对齐格式
        if (row == 1 && col == 1)
        {
            return Qt::AlignRight + Qt::AlignVCenter;
        }
        break;
    }
    case Qt::CheckStateRole:
    {
        if (row == 1 && col == 0)
        {
            return Qt::Checked;
        }
        break;
    }
    default:
        break;
    }
    return QVariant();
}
