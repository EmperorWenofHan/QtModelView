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
    QStandardItem* rootNode = m_standardModel->invisibleRootItem();

    QStandardItem* americaItem = new QStandardItem("America");
    QStandardItem* mexicoItem = new QStandardItem("Canada");
    QStandardItem* chinaItem = new QStandardItem("China");
    QStandardItem* bostonItem = new QStandardItem("Boston");
    QStandardItem* europeItem = new QStandardItem("Europe");
    QStandardItem* italyItem = new QStandardItem("Italy");
    QStandardItem* romeItem = new QStandardItem("Rome");
    QStandardItem* veronaItem = new QStandardItem("Verona");

    rootNode->appendRow(americaItem);
    rootNode->appendRow(europeItem);
    americaItem->appendRow(mexicoItem);
    rootNode->appendRow(chinaItem);
    chinaItem->appendRow(bostonItem);
    europeItem->appendRow(italyItem);
    italyItem->appendRow(romeItem);
    italyItem->appendRow(veronaItem);

    m_treeView->setModel(m_standardModel);
    m_treeView->expandAll();

    QItemSelectionModel* selectionModel = m_treeView->selectionModel();
    connect(selectionModel, SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&))
        , this, SLOT(selectionChangedSlot(const QItemSelection&, const QItemSelection&)));
}

TreeView::~TreeView()
{}

void TreeView::selectionChangedSlot(const QItemSelection& newSelection, const QItemSelection& oldSelection)
{
    const QModelIndex index = m_treeView->selectionModel()->currentIndex();
    QString selectedText = index.data(Qt::DisplayRole).toString();
    int hierarchyLevel = 1;
    QModelIndex seekRoot = index;

    while (seekRoot.parent() != QModelIndex())
    {
        seekRoot = seekRoot.parent();
        ++ hierarchyLevel;
    }
    QString showString = QString("%1, Level %2").arg(selectedText)
        .arg(hierarchyLevel);
    setWindowTitle(showString);
}

QList<QStandardItem*> TreeView::prepareRow(const QString& first, const QString& second, const QString& third)
{
    QList<QStandardItem*> rowItems;
    rowItems << new QStandardItem(first);
    rowItems << new QStandardItem(second);
    rowItems << new QStandardItem(third);
    return rowItems;
}
