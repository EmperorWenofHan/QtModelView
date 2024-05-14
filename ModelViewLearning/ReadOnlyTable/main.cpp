#include <QtWidgets/QApplication>
#include <QTableView>
#include <TableDataModel.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTableView tableView;
    TableDataModel dataModel(nullptr);
    tableView.setModel(&dataModel);
    tableView.show();

    return a.exec();
}
