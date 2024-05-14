#include "TableDataModel.h"
#include <QFont>
#include <QBrush>
#include <QTime>
#include <QTimer>

TableDataModel::TableDataModel(QObject* parent /*= nulllpte*/)
    : QAbstractTableModel(parent)
{
    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    connect(m_timer , SIGNAL(timeout()) , this , SLOT(timerHint()));
    m_timer->start();
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
        return QString("Row%1 , Column%2")
            .arg(index.row() + 1)
            .arg(index.column() + 1);
    }
    default:
        break;
    }
    return QVariant();
}

QVariant TableDataModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (Qt::DisplayRole == role)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString("first");
            case 1:
                return QString("second");
            case 2:
                return QString("third");
            default:
                return QVariant();
            }
        }
    }
    return QVariant();
}

void TableDataModel::timerHint()
{
    QModelIndex topLeft = createIndex(0, 0);
    // 告知数据改变
    emit dataChanged(topLeft, topLeft);
}
