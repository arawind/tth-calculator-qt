#ifndef DIRVIEWER_H
#define DIRVIEWER_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFileSystemModel>
#include "listchecker.h"
//#include "mainwindow.h"

namespace Ui {
class dirViewer;
}

class dirViewer : public QDialog
{
    Q_OBJECT
    
public:
    explicit dirViewer(QWidget *parent = 0);
    ~dirViewer();
    QStringList directoryList;

    
private slots:
    void on_tree_clicked(const QModelIndex &index);

    void on_butOK_clicked();

private:
    Ui::dirViewer *ui;
    QFileSystemModel *model;
    void parseList();
    void updateList(QStringList *items);
    bool checkList(QStringList *items);

};

#endif // DIRVIEWER_H
