#ifndef _TABLEDATA_MODEL_H_
#define _TABLEDATA_MODEL_H_

#include <QAbstractTableModel>
#include <QVariant>

const int COLS = 3;
const int ROWS = 2;

class TableDataModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    TableDataModel(QObject* parent = nullptr);

    // 需要告诉View  这个Model有多少行，多少列，数据是什么
    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    virtual int columnCount(const QModelIndex& parent = QModelIndex())const override;

    virtual QVariant data(const QModelIndex& index , int role = Qt::DisplayRole)const override;

    // 编辑数据
    virtual bool setData(const QModelIndex& index , const QVariant& value , int role = Qt::EditRole) override;

    virtual Qt::ItemFlags flags(const QModelIndex& index)const override;

private:
    QString m_gridData[ROWS][COLS];

signals:
    void editCompleted(const QString& );

};


#endif // _TABLEDATA_MODEL_H_


