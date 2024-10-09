/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickedlabel.h"

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *m_err_tip;
    QWidget *head_widget;
    QGridLayout *gridLayout;
    QLabel *m_head_label;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *m_email_lb;
    QLineEdit *m_email_edit;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *m_pass_label;
    QLineEdit *m_pass_edit;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    ClickedLabel *m_forget_label;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *m_login_btn;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *m_reg_btn;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(300, 500);
        LoginDialog->setMinimumSize(QSize(300, 500));
        LoginDialog->setMaximumSize(QSize(300, 500));
        verticalLayout = new QVBoxLayout(LoginDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 5, 5, 5);
        m_err_tip = new QLabel(LoginDialog);
        m_err_tip->setObjectName(QString::fromUtf8("m_err_tip"));
        m_err_tip->setMinimumSize(QSize(0, 25));
        m_err_tip->setMaximumSize(QSize(16777215, 25));
        m_err_tip->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(m_err_tip);

        head_widget = new QWidget(LoginDialog);
        head_widget->setObjectName(QString::fromUtf8("head_widget"));
        head_widget->setMinimumSize(QSize(200, 230));
        gridLayout = new QGridLayout(head_widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_head_label = new QLabel(head_widget);
        m_head_label->setObjectName(QString::fromUtf8("m_head_label"));
        m_head_label->setMinimumSize(QSize(200, 200));
        m_head_label->setMaximumSize(QSize(200, 200));
        m_head_label->setStyleSheet(QString::fromUtf8("image: url(:/res/ice.png);"));

        gridLayout->addWidget(m_head_label, 1, 0, 1, 1);


        verticalLayout_2->addWidget(head_widget);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_email_lb = new QLabel(LoginDialog);
        m_email_lb->setObjectName(QString::fromUtf8("m_email_lb"));
        m_email_lb->setMinimumSize(QSize(0, 25));
        m_email_lb->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(m_email_lb);

        m_email_edit = new QLineEdit(LoginDialog);
        m_email_edit->setObjectName(QString::fromUtf8("m_email_edit"));
        m_email_edit->setMinimumSize(QSize(0, 25));
        m_email_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(m_email_edit);

        horizontalSpacer_6 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        m_pass_label = new QLabel(LoginDialog);
        m_pass_label->setObjectName(QString::fromUtf8("m_pass_label"));
        m_pass_label->setMinimumSize(QSize(0, 25));
        m_pass_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(m_pass_label);

        m_pass_edit = new QLineEdit(LoginDialog);
        m_pass_edit->setObjectName(QString::fromUtf8("m_pass_edit"));
        m_pass_edit->setMinimumSize(QSize(0, 25));
        m_pass_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(m_pass_edit);

        horizontalSpacer_7 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        m_forget_label = new ClickedLabel(LoginDialog);
        m_forget_label->setObjectName(QString::fromUtf8("m_forget_label"));

        horizontalLayout_4->addWidget(m_forget_label);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        m_login_btn = new QPushButton(LoginDialog);
        m_login_btn->setObjectName(QString::fromUtf8("m_login_btn"));
        m_login_btn->setMinimumSize(QSize(100, 30));

        horizontalLayout_5->addWidget(m_login_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        m_reg_btn = new QPushButton(LoginDialog);
        m_reg_btn->setObjectName(QString::fromUtf8("m_reg_btn"));
        m_reg_btn->setMinimumSize(QSize(100, 30));

        horizontalLayout_6->addWidget(m_reg_btn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        m_err_tip->setText(QString());
        m_head_label->setText(QString());
        m_email_lb->setText(QCoreApplication::translate("LoginDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        m_email_edit->setText(QCoreApplication::translate("LoginDialog", "3194811890@qq.com", nullptr));
        m_pass_label->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        m_pass_edit->setText(QCoreApplication::translate("LoginDialog", "123456", nullptr));
        m_forget_label->setText(QCoreApplication::translate("LoginDialog", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        m_login_btn->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        m_reg_btn->setText(QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
