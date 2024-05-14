#ifndef _TABLEDATA_MODEL_H_
#define _TABLEDATA_MODEL_H_

#include <QAbstractTableModel>

class QTimer;

class TableDataModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    TableDataModel(QObject* parent = nullptr);

    // 需要告诉View  这个Model有多少行，多少列，数据是什么
    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    virtual int columnCount(const QModelIndex& parent = QModelIndex())const override;

    QVariant data(const QModelIndex& index , int role = Qt::DisplayRole)const override;

public slots:
    void timerHint();

private:
    QTimer* m_timer;

};


#endif // _TABLEDATA_MODEL_H_


