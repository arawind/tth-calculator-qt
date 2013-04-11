#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtCore>
#include <QtGui>
#include <dirviewer.h>
#include <rhash.h>
#include <errno.h>

#define STATE_ACTIVE  0xb01dbabe
#define STATE_STOPED  0xdeadbeef
#define STATE_DELETED 0xdecea5ed
#define RCTX_AUTO_FINAL 0x1
#define RCTX_FINALIZED  0x2
#define RCTX_FINALIZED_MASK (RCTX_AUTO_FINAL | RCTX_FINALIZED)
#define RHPR_FORMAT (RHPR_RAW | RHPR_HEX | RHPR_BASE32 | RHPR_BASE64)
#define RHPR_MODIFIER (RHPR_UPPERCASE | RHPR_REVERSE)

typedef struct rhash_vector_item
{
    struct rhash_hash_info* hash_info;
    void *context;
} rhash_vector_item;

typedef struct rhash_context_ext
{
    struct rhash_context rc;
    unsigned hash_vector_size; /* number of contained hash sums */
    unsigned flags;
    unsigned state;
    void *callback, *callback_data;
    void *bt_ctx;
    rhash_vector_item vector[1]; /* contexts of contained hash sums */
} rhash_context_ext;

//void callbackFunction(void *data,unsigned long long offset);
//void (*progSetterPointer)(unsigned long long);

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //QStringList directoryPaths;
    QStringList filePaths;
    QStringList directoryList;


    
private slots:
    void on_actionAdd_New_Folder_triggered();

    void on_actionAdd_Multiple_Folders_triggered();

    void on_butTTH_clicked();

private:
    Ui::MainWindow *ui;
    void addNewFolder();
    void calculateFiles();
    void addMultipleFolders();
    dirViewer *dirview;
    bool checkList(QStringList *items);
    //void callbackFunction(void* dataCallback,unsigned long long offset );
    void indProgressSetter(unsigned long long value);
    int rhash_file_2(unsigned hash_id, const char* filepath, unsigned char* result);
    unsigned long long filesize;
    int rhash_file_update_2(rhash ctx, FILE* fd);
};

#endif // MAINWINDOW_H
