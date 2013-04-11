/********************************************************************************
** Form generated from reading UI file 'dirviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIRVIEWER_H
#define UI_DIRVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dirViewer
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QTreeView *tree;
    QListWidget *dirList;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *butOK;
    QPushButton *butCancel;

    void setupUi(QDialog *dirViewer)
    {
        if (dirViewer->objectName().isEmpty())
            dirViewer->setObjectName(QStringLiteral("dirViewer"));
        dirViewer->resize(624, 409);
        verticalLayout_2 = new QVBoxLayout(dirViewer);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(dirViewer);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 0));
        label->setScaledContents(false);
        label->setWordWrap(true);
        label->setMargin(0);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(dirViewer);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setStyleSheet(QLatin1String("QLabel{\n"
"\n"
"color:rgb(149, 6, 8);\n"
"}"));

        verticalLayout_2->addWidget(label_2);

        frame = new QFrame(dirViewer);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 8);
        splitter = new QSplitter(frame);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setOpaqueResize(true);
        tree = new QTreeView(splitter);
        tree->setObjectName(QStringLiteral("tree"));
        splitter->addWidget(tree);
        dirList = new QListWidget(splitter);
        dirList->setObjectName(QStringLiteral("dirList"));
        splitter->addWidget(dirList);

        verticalLayout->addWidget(splitter);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setEnabled(true);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(489, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        butOK = new QPushButton(frame_2);
        butOK->setObjectName(QStringLiteral("butOK"));

        horizontalLayout_2->addWidget(butOK);

        butCancel = new QPushButton(frame_2);
        butCancel->setObjectName(QStringLiteral("butCancel"));

        horizontalLayout_2->addWidget(butCancel);


        verticalLayout->addWidget(frame_2);


        verticalLayout_2->addWidget(frame);


        retranslateUi(dirViewer);
        QObject::connect(butOK, SIGNAL(clicked()), dirViewer, SLOT(accept()));
        QObject::connect(butCancel, SIGNAL(clicked()), dirViewer, SLOT(reject()));

        QMetaObject::connectSlotsByName(dirViewer);
    } // setupUi

    void retranslateUi(QDialog *dirViewer)
    {
        dirViewer->setWindowTitle(QApplication::translate("dirViewer", "Directory Viewer", 0));
        label->setText(QApplication::translate("dirViewer", "Select directories you want to hash:", 0));
        label_2->setText(QApplication::translate("dirViewer", "Note: If subdirectories are selected then only they will be hashed even though the root directory is selected", 0));
        butOK->setText(QApplication::translate("dirViewer", "OK", 0));
        butCancel->setText(QApplication::translate("dirViewer", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class dirViewer: public Ui_dirViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIRVIEWER_H
