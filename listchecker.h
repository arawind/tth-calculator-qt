#ifndef LISTCHECKER_H
#define LISTCHECKER_H

#include <QStringList>

class listChecker
{
public:
    listChecker();
    bool checkList(QStringList items);
    QStringList directoryList;
};

#endif // LISTCHECKER_H
