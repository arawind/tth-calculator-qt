/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_New_Folder;
    QAction *actionAdd_Multiple_Folders;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFrame *individualHashing;
    QVBoxLayout *verticalLayout_2;
    QProgressBar *indHashProg;
    QLabel *indHashLabel;
    QListWidget *listWidget;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QProgressBar *statusProgress;
    QPushButton *butTTH;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(492, 324);
        actionAdd_New_Folder = new QAction(MainWindow);
        actionAdd_New_Folder->setObjectName(QStringLiteral("actionAdd_New_Folder"));
        actionAdd_Multiple_Folders = new QAction(MainWindow);
        actionAdd_Multiple_Folders->setObjectName(QStringLiteral("actionAdd_Multiple_Folders"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        individualHashing = new QFrame(centralWidget);
        individualHashing->setObjectName(QStringLiteral("individualHashing"));
        individualHashing->setFrameShape(QFrame::StyledPanel);
        individualHashing->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(individualHashing);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        indHashProg = new QProgressBar(individualHashing);
        indHashProg->setObjectName(QStringLiteral("indHashProg"));
        indHashProg->setValue(24);
        indHashProg->setTextVisible(false);

        verticalLayout_2->addWidget(indHashProg);

        indHashLabel = new QLabel(individualHashing);
        indHashLabel->setObjectName(QStringLiteral("indHashLabel"));

        verticalLayout_2->addWidget(indHashLabel);


        verticalLayout->addWidget(individualHashing);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        statusProgress = new QProgressBar(frame);
        statusProgress->setObjectName(QStringLiteral("statusProgress"));
        statusProgress->setEnabled(true);
        statusProgress->setMinimum(0);
        statusProgress->setMaximum(100);
        statusProgress->setValue(0);
        statusProgress->setAlignment(Qt::AlignCenter);
        statusProgress->setTextVisible(false);
        statusProgress->setTextDirection(QProgressBar::TopToBottom);

        horizontalLayout->addWidget(statusProgress);

        butTTH = new QPushButton(frame);
        butTTH->setObjectName(QStringLiteral("butTTH"));

        horizontalLayout->addWidget(butTTH);


        verticalLayout->addWidget(frame);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 492, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setEnabled(true);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionAdd_New_Folder);
        menuFile->addAction(actionAdd_Multiple_Folders);
        mainToolBar->addAction(actionAdd_New_Folder);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAdd_Multiple_Folders);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAdd_New_Folder->setText(QApplication::translate("MainWindow", "Add New Folder", 0));
        actionAdd_Multiple_Folders->setText(QApplication::translate("MainWindow", "Add Multiple Folders", 0));
        indHashLabel->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        butTTH->setText(QApplication::translate("MainWindow", "Calculate TTH", 0));
        label->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
