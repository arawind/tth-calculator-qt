#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QDebug>

//void callbackFunction(void *data,unsigned long long offset)
//{
//    if(callbackCheck == 10000)
//    {
//    //MainWindow *mWindow= static_cast<MainWindow*>(data);
//    //mWindow->indProgressSetter(offset);
//    callbackCheck=0;
//    }
//    callbackCheck++;
//   // indProgressSetter(offset);
//}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->hide();
    ui->individualHashing->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNewFolder()
{
    QString directoryPath = QFileDialog::getExistingDirectory(this, tr("Select your music directory"), QDir::homePath());
    if(directoryPath!=NULL)
    {
    directoryPath=QFileInfo(directoryPath).absoluteFilePath();
    directoryList.append(directoryPath);
    //directoryList.sort();
    while(!checkList(&directoryList))
    {
        //do nothing
    }

    ui->listWidget->clear();
    ui->listWidget->addItems(directoryList);
    }
}

void MainWindow::calculateFiles()
{
    filePaths.clear();
    for(int i=0;i<directoryList.count();i++)
    {
        QDirIterator dirWalker(directoryList.at(i),QDir::Files|QDir::NoSymLinks,QDirIterator::Subdirectories);

        while(dirWalker.hasNext())
        {

            dirWalker.next();
            ui->label->setText("Adding "+dirWalker.filePath());
            filePaths.append(dirWalker.filePath());

        }
    }
    ui->label->setText("");
}

void MainWindow::addMultipleFolders()
{
    dirview = new dirViewer(this);
    dirview->setModal(true);
    dirview->directoryList = this->directoryList;
    if(dirview->exec()==dirViewer::Accepted)
    {
        this->directoryList.append(dirview->directoryList);
        //directoryList.sort();
        while(!checkList(&directoryList))
        {
            //do nothing
        }

        ui->listWidget->clear();
        ui->listWidget->addItems(directoryList);
    }


    //delete dirview;
}

void MainWindow::on_actionAdd_New_Folder_triggered()
{
    addNewFolder();
}

void MainWindow::on_actionAdd_Multiple_Folders_triggered()
{
    addMultipleFolders();
}

bool MainWindow::checkList(QStringList *items)
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

void MainWindow::on_butTTH_clicked()
{

  ui->statusProgress->setTextVisible(false);
  ui->statusProgress->setMinimum(0);
  ui->statusProgress->setMaximum(0);
  ui->statusProgress->setValue(-1);
    calculateFiles();
  //const char* filepath = "C:/dell/drivers/R220357/Releases.txt";
  unsigned char digest[64];
  char output[130];
  unsigned long numFiles;
  rhash_library_init(); /* initialize static data */
  QFile TTHstorage("/home/arawind/tthCalcGuiOutput.txt");
  TTHstorage.open(QIODevice::Append|QIODevice::Text);
  QTextStream out(&TTHstorage);
  ui->statusProgress->setMaximum(100);
  numFiles=filePaths.count();
  for(unsigned int i=0; i<numFiles; i++)
  {
      ui->statusProgress->setValue((i+1)*100/numFiles);
      QString labelText;
      labelText = "Hashing ";
      labelText += QString::number(i+1);
      labelText += " of ";
      labelText += QString::number(numFiles);
      ui->label->setText(labelText);
//      QDir directory(directoryList.at(i));
//      QStringList filesInDirectory = directory.entryList(QDir::Files|QDir::NoDotAndDotDot|QDir::NoSymLinks);
//      for(int j=0; j<filesInDirectory.count(); j++)
//      {
          //QByteArray ba = directoryList.at(i).toUtf8()+"/"+filesInDirectory.at(j).toUtf8();
          QByteArray ba = filePaths.at(i).toUtf8();
          const char *filepath = ba.data();
          //ui->indHashLabel->setText(QString::number(filesize));
          ui->individualHashing->show();
          //filepath  directoryList.at(j);
          int res = rhash_file_2(RHASH_TTH, filepath, digest);
          if(res < 0) {
              fprintf(stderr, "LibRHash error: %s: %s\n", filepath, strerror(errno));
              //return 1;
              //return NULL;
          }

          /* convert binary digest to hexadecimal string */
          rhash_print_bytes(output, digest, rhash_get_digest_size(RHASH_TTH), (RHPR_BASE32 | RHPR_UPPERCASE));
            //rhash_get_name(RHASH_TTH)+" "filepath+" " +output

          out <<rhash_get_name(RHASH_TTH)<<" "<< filepath<< " " << output<<"\n";

 //     }
  }
    TTHstorage.flush();
    TTHstorage.close();
    ui->indHashProg->setValue(100);
    //ui->individualHashing->hide();
  //return 0;

}


//rhash_callback_t MainWindow::callbackFunction(void *dataCallback,unsigned long long offset)
//{
//    void (*tempFunc)(void *dataCallback2,unsigned long long offset2){

//    }


//    tempFunc(dataCallback,offset);

//    printf("%d\n",offset);
//}




int MainWindow::rhash_file_2(unsigned hash_id, const char* filepath, unsigned char* result)
{
//    class abc
//    {
//    public:
//        void callbackFunction(void *dataCallback, unsigned long long offset);
//    };

//    void abc::callbackFunction(void *dataCallback, unsigned long long offset)
//    {

//    }


    FILE* fd;
    rhash ctx;
    int res;
    //unsigned long long size;
    //void *callbackData;
    hash_id &= RHASH_ALL_HASHES;
    if(hash_id == 0) return -1;

    if((fd = fopen(filepath, "rb")) == NULL) return -1;

    if((ctx = rhash_init(hash_id)) == NULL) return -1;
    //FileSize
    //fseek(fd,0,SEEK_END);
    //filesize=ftell(fd);
    filesize=QFileInfo(filepath).size();
    //fseek(fd,0,SEEK_SET);

    //progSetterPointer = &MainWindow::indProgressSetter;
    //callbackData = progSetterPointer;

    //rhash_set_callback(ctx,callbackFunction,callbackData);
    res = rhash_file_update_2(ctx, fd); /* hash the file */

    fclose(fd);

    rhash_final(ctx, result);
    rhash_free(ctx);
    //printf("%llu",size);
    return res;
}

int MainWindow::rhash_file_update_2(rhash ctx, FILE* fd)
{
    rhash_context_ext* const ectx = (rhash_context_ext*)ctx;
    const size_t block_size = 8192;
    unsigned char *buffer, *pmem;
    size_t length = 0, align8;
    int res = 0;
    if(ectx->state != STATE_ACTIVE) return 0; /* do nothing if canceled */

    if(ctx == NULL) {
        errno = EINVAL;
        return -1;
    }

    pmem = (unsigned char*)malloc(block_size + 8);
    if(!pmem) return -1; /* errno is set to ENOMEM according to UNIX 98 */

    align8 = ((unsigned char*)0 - pmem) & 7;
    buffer = pmem + align8;

    while(!feof(fd)) {
        if(ectx->state != STATE_ACTIVE) break; /* stop if canceled */

        length = fread(buffer, 1, block_size, fd);
        /* read can return -1 on error */
        if(length == (size_t)-1) {
            res = -1; /* note: fread sets errno */
            break;
        }
        rhash_update(ctx, buffer, length);
        //MainWindow::indProgressSetter(ectx->rc.msg_size);
//        if(ectx->callback) {
//            ((rhash_callback_t)ectx->callback)(ectx->callback_data, ectx->rc.msg_size);
//        }


    }

    free(buffer);
    return res;
}

void MainWindow::indProgressSetter(unsigned long long value)
{
    float progVal;
    progVal= value*100/filesize;
    ui->indHashProg->setValue(progVal);
    QString labelText;
    labelText=QString::number(value);
    labelText+=" ";
    labelText+=QString::number(filesize);
    ui->indHashLabel->setText(labelText);
}
