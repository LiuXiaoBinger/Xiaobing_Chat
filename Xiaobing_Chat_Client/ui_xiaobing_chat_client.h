/********************************************************************************
** Form generated from reading UI file 'xiaobing_chat_client.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XIAOBING_CHAT_CLIENT_H
#define UI_XIAOBING_CHAT_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Xiaobing_Chat_Client
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *Xiaobing_Chat_Client)
    {
        if (Xiaobing_Chat_Client->objectName().isEmpty())
            Xiaobing_Chat_Client->setObjectName(QString::fromUtf8("Xiaobing_Chat_Client"));
        Xiaobing_Chat_Client->resize(300, 500);
        Xiaobing_Chat_Client->setMinimumSize(QSize(300, 500));
        Xiaobing_Chat_Client->setMaximumSize(QSize(300, 537));
        centralwidget = new QWidget(Xiaobing_Chat_Client);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(300, 500));
        centralwidget->setMaximumSize(QSize(300, 500));
        Xiaobing_Chat_Client->setCentralWidget(centralwidget);

        retranslateUi(Xiaobing_Chat_Client);

        QMetaObject::connectSlotsByName(Xiaobing_Chat_Client);
    } // setupUi

    void retranslateUi(QMainWindow *Xiaobing_Chat_Client)
    {
        Xiaobing_Chat_Client->setWindowTitle(QCoreApplication::translate("Xiaobing_Chat_Client", "XBChart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Xiaobing_Chat_Client: public Ui_Xiaobing_Chat_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XIAOBING_CHAT_CLIENT_H
