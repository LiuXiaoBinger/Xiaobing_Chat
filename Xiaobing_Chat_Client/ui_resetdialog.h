/********************************************************************************
** Form generated from reading UI file 'resetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETDIALOG_H
#define UI_RESETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <ctimerbtn.h>

QT_BEGIN_NAMESPACE

class Ui_ResetDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *m_err_tip;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *m_user_lb;
    QLineEdit *m_user_edit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *m_email_lb;
    QLineEdit *m_email_edit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *m_varify_lb;
    QLineEdit *m_varify_edit;
    CTimerBtn *m_varify_btn;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *m_pwd_lb;
    QLineEdit *m_pwd_edit;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *m_sure_btn;
    QPushButton *m_return_btn;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *ResetDialog)
    {
        if (ResetDialog->objectName().isEmpty())
            ResetDialog->setObjectName(QString::fromUtf8("ResetDialog"));
        ResetDialog->resize(354, 538);
        verticalLayout = new QVBoxLayout(ResetDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        m_err_tip = new QLabel(ResetDialog);
        m_err_tip->setObjectName(QString::fromUtf8("m_err_tip"));
        m_err_tip->setMinimumSize(QSize(0, 25));
        m_err_tip->setMaximumSize(QSize(16777215, 25));
        m_err_tip->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(m_err_tip);

        widget = new QWidget(ResetDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_user_lb = new QLabel(widget);
        m_user_lb->setObjectName(QString::fromUtf8("m_user_lb"));
        m_user_lb->setMinimumSize(QSize(0, 25));
        m_user_lb->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(m_user_lb);

        m_user_edit = new QLineEdit(widget);
        m_user_edit->setObjectName(QString::fromUtf8("m_user_edit"));
        m_user_edit->setMinimumSize(QSize(0, 25));
        m_user_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(m_user_edit);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(ResetDialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_email_lb = new QLabel(widget_2);
        m_email_lb->setObjectName(QString::fromUtf8("m_email_lb"));
        m_email_lb->setMinimumSize(QSize(48, 25));
        m_email_lb->setMaximumSize(QSize(48, 25));

        horizontalLayout_2->addWidget(m_email_lb);

        m_email_edit = new QLineEdit(widget_2);
        m_email_edit->setObjectName(QString::fromUtf8("m_email_edit"));
        m_email_edit->setMinimumSize(QSize(0, 25));
        m_email_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(m_email_edit);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(ResetDialog);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        m_varify_lb = new QLabel(widget_3);
        m_varify_lb->setObjectName(QString::fromUtf8("m_varify_lb"));
        m_varify_lb->setMinimumSize(QSize(0, 25));
        m_varify_lb->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(m_varify_lb);

        m_varify_edit = new QLineEdit(widget_3);
        m_varify_edit->setObjectName(QString::fromUtf8("m_varify_edit"));
        m_varify_edit->setMinimumSize(QSize(0, 25));
        m_varify_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(m_varify_edit);

        m_varify_btn = new CTimerBtn(widget_3);
        m_varify_btn->setObjectName(QString::fromUtf8("m_varify_btn"));
        m_varify_btn->setMinimumSize(QSize(0, 25));
        m_varify_btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(m_varify_btn);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(ResetDialog);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        m_pwd_lb = new QLabel(widget_4);
        m_pwd_lb->setObjectName(QString::fromUtf8("m_pwd_lb"));
        m_pwd_lb->setMinimumSize(QSize(0, 25));
        m_pwd_lb->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(m_pwd_lb);

        m_pwd_edit = new QLineEdit(widget_4);
        m_pwd_edit->setObjectName(QString::fromUtf8("m_pwd_edit"));
        m_pwd_edit->setMinimumSize(QSize(0, 25));
        m_pwd_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(m_pwd_edit);


        verticalLayout->addWidget(widget_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        widget_5 = new QWidget(ResetDialog);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        m_sure_btn = new QPushButton(widget_5);
        m_sure_btn->setObjectName(QString::fromUtf8("m_sure_btn"));
        m_sure_btn->setMinimumSize(QSize(0, 25));
        m_sure_btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(m_sure_btn);

        m_return_btn = new QPushButton(widget_5);
        m_return_btn->setObjectName(QString::fromUtf8("m_return_btn"));
        m_return_btn->setMinimumSize(QSize(0, 25));
        m_return_btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(m_return_btn);


        verticalLayout->addWidget(widget_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(ResetDialog);

        QMetaObject::connectSlotsByName(ResetDialog);
    } // setupUi

    void retranslateUi(QDialog *ResetDialog)
    {
        ResetDialog->setWindowTitle(QCoreApplication::translate("ResetDialog", "Dialog", nullptr));
        m_err_tip->setText(QCoreApplication::translate("ResetDialog", "1", nullptr));
        m_user_lb->setText(QCoreApplication::translate("ResetDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        m_email_lb->setText(QCoreApplication::translate("ResetDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        m_varify_lb->setText(QCoreApplication::translate("ResetDialog", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        m_varify_btn->setText(QCoreApplication::translate("ResetDialog", "\350\216\267\345\217\226", nullptr));
        m_pwd_lb->setText(QCoreApplication::translate("ResetDialog", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        m_sure_btn->setText(QCoreApplication::translate("ResetDialog", "\347\241\256\350\256\244", nullptr));
        m_return_btn->setText(QCoreApplication::translate("ResetDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetDialog: public Ui_ResetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETDIALOG_H
