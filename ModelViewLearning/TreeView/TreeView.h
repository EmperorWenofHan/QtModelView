#ifndef _TREEVIEW_H_
#define _TREEVIEW_H_

#include <QtWidgets/QMainWindow>
#include "ui_TreeView.h"
#include <QString>
#include <QList>

class QTreeView;
class QStandardItemModel;
class QStandardItem;

class TreeView : public QMainWindow
{
    Q_OBJECT

public:
    TreeView(QWidget *parent = nullptr);
    ~TreeView();

public slots:
    void selectionChangedSlot(const QItemSelection& , const QItemSelection& );

private:
    QList<QStandardItem*> prepareRow(const QString& first , const QString& second, const QString& third);

private:
    Ui::TreeViewClass ui;

    QTreeView* m_treeView;
    QStandardItemModel* m_standardModel;
};

#endif  // _TREEVIEW_H_