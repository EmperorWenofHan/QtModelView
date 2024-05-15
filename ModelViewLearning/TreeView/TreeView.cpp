#include "TreeView.h"
#include <QTreeView>
#include <QStandardItemModel>

const int ROWS = 2;
const int COLUMNS = 3;

TreeView::TreeView(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    m_treeView = new QTreeView(this);
    setCentralWidget(m_treeView);

    m_standardModel = new QStandardItemModel;
    QList<QStandardItem*> preparedRow = prepareRow("first", "second", "third");
    QStandardItem* item = m_standardModel->invisibleRootItem();
    item->appendRow(preparedRow);

    QList<QStandardItem*> secondRow = prepareRow("111", "222", "333");
    // adding a row to an item starts a subtree
    preparedRow.first()->appendRow(secondRow);

    m_treeView->setModel(m_standardModel);
    m_treeView->expandAll();
}

TreeView::~TreeView()
{}

QList<QStandardItem*> TreeView::prepareRow(const QString& first, const QString& second, const QString& third)
{
    QList<QStandardItem*> rowItems;
    rowItems << new QStandardItem(first);
    rowItems << new QStandardItem(second);
    rowItems << new QStandardItem(third);
    return rowItems;
}
