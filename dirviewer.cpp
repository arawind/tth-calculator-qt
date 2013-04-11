#include "dirviewer.h"
#include "ui_dirviewer.h"


dirViewer::dirViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dirViewer)
{
    ui->setupUi(this);
    model = new QFileSystemModel(this);
    model->setRootPath("");
    model->setFilter(QDir::Dirs|QDir::NoDotAndDotDot);

    //QTreeView *tree = new QTreeView(this);
    ui->tree->setModel(model);

    ui->tree->setSelectionMode(QAbstractItemView::MultiSelection);
    // Demonstrating look and feel features
    ui->tree->setAnimated(false);
    ui->tree->setIndentation(20);
    ui->tree->setSortingEnabled(true);
    ui->tree->sortByColumn(0,Qt::AscendingOrder);
    ui->tree->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->tree->resizeColumnToContents(0);
    //ui->tree->setWindowTitle(QObject::tr("Dir View"));
//#if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5)
  //  ui->tree->showMaximized();

//#else
    //ui->tree->resize(640, 480);
//    tree->show();
    //vertLayout->addWidget(tree);


    //connect(butTree,clicked(),close());
//#endif


}

dirViewer::~dirViewer()
{
    delete ui;
}

void dirViewer::on_tree_clicked(const QModelIndex &index)
{
    parseList();
}

void dirViewer::updateList(QStringList *items)
{
    ui->dirList->clear();
    ui->dirList->addItems(*items);
    directoryList = *items;
}

void dirViewer::parseList()
{
    QModelIndex tempindex;
    QModelIndexList selectedList = ui->tree->selectionModel()->selectedRows(0);
    QStringList items;

    foreach(tempindex,selectedList)
    {
        QString text = model->filePath(tempindex);
        items.append(text);
    }
    //items.sort();
    directoryList = items;

    while(!checkList(&items))
    {
        //do nothing
    }
    directoryList = items;
    updateList(&items);
}

bool dirViewer::checkList(QStringList *items)
{
    int i;
    int k=items->count();
    bool chkvar=true;
    for(i=0;i<k;i++)
    {
        for(int j=i+1; j<k ;j++)
        {
            if(items->at(j).contains(items->at(i)))
            {
                items->removeAt(i);
                chkvar=false;
                break;
            }
        }
        if(!chkvar)
            break;
        for(int j=i-1; j>-1 ;j--)
        {
            if(items->at(j).contains(items->at(i)))
            {
                items->removeAt(i);
                chkvar=false;
                break;
            }
        }
        if(!chkvar)
            break;
        chkvar=true;
    }


    return chkvar;

}

void dirViewer::on_butOK_clicked()
{

}
