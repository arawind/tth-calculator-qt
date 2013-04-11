#include <QtWidgets/QApplication>
#include "mainwindow.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}

//void callbackFunction(void *data,unsigned long long offset)
//{
//    printf("%d\n",offset);
//}
