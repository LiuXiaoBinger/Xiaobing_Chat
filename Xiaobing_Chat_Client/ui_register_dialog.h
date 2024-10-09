/********************************************************************************
** Form generated from reading UI file 'register_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_DIALOG_H
#define UI_REGISTER_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <ctimerbtn.h>
#include "clickedlabel.h"

QT_BEGIN_NAMESPACE

class Ui_register_Dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *m_err_tip;
    QHBoxLayout *horizontalLayout;
    QLabel *m_user_label;
    QLineEdit *m_user_edit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *m_email_label;
    QLineEdit *m_email_edit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *m_pass_label;
    QLineEdit *m_pass_edit;
    ClickedLabel *m_pass_visible;
    QHBoxLayout *horizontalLayout_5;
    QLabel *m_confirm_label;
    QLineEdit *m_confirm_edit;
    ClickedLabel *m_confirm_visible;
    QHBoxLayout *horizontalLayout_6;
    QLabel *m_varify_label;
    QLineEdit *m_varify_edit;
    CTimerBtn *m_get_code;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *m_sure_btn;
    QPushButton *m_cancel_btn;
    QSpacerItem *verticalSpacer_3;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_5;
    QLabel *m_tip_lb;
    QLabel *m_tip2_lb;
    QSpacerItem *verticalSpacer_6;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_return_btn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *register_Dialog)
    {
        if (register_Dialog->objectName().isEmpty())
            register_Dialog->setObjectName(QString::fromUtf8("register_Dialog"));
        register_Dialog->resize(300, 500);
        register_Dialog->setMinimumSize(QSize(300, 500));
        register_Dialog->setMaximumSize(QSize(300, 500));
        verticalLayout_2 = new QVBoxLayout(register_Dialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(register_Dialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        widget = new QWidget(page);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        m_err_tip = new QLabel(widget);
        m_err_tip->setObjectName(QString::fromUtf8("m_err_tip"));
        m_err_tip->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(m_err_tip);


        verticalLayout_3->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_user_label = new QLabel(page);
        m_user_label->setObjectName(QString::fromUtf8("m_user_label"));
        m_user_label->setMinimumSize(QSize(0, 25));
        m_user_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(m_user_label);

        m_user_edit = new QLineEdit(page);
        m_user_edit->setObjectName(QString::fromUtf8("m_user_edit"));
        m_user_edit->setMinimumSize(QSize(0, 25));
        m_user_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(m_user_edit);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        m_email_label = new QLabel(page);
        m_email_label->setObjectName(QString::fromUtf8("m_email_label"));
        m_email_label->setMinimumSize(QSize(0, 25));
        m_email_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(m_email_label);

        m_email_edit = new QLineEdit(page);
        m_email_edit->setObjectName(QString::fromUtf8("m_email_edit"));
        m_email_edit->setMinimumSize(QSize(0, 25));
        m_email_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(m_email_edit);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        m_pass_label = new QLabel(page);
        m_pass_label->setObjectName(QString::fromUtf8("m_pass_label"));
        m_pass_label->setMinimumSize(QSize(0, 25));
        m_pass_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(m_pass_label);

        m_pass_edit = new QLineEdit(page);
        m_pass_edit->setObjectName(QString::fromUtf8("m_pass_edit"));
        m_pass_edit->setMinimumSize(QSize(0, 25));
        m_pass_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(m_pass_edit);

        m_pass_visible = new ClickedLabel(page);
        m_pass_visible->setObjectName(QString::fromUtf8("m_pass_visible"));
        m_pass_visible->setMinimumSize(QSize(20, 20));
        m_pass_visible->setMaximumSize(QSize(20, 20));
        m_pass_visible->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_4->addWidget(m_pass_visible);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        m_confirm_label = new QLabel(page);
        m_confirm_label->setObjectName(QString::fromUtf8("m_confirm_label"));
        m_confirm_label->setMinimumSize(QSize(0, 25));
        m_confirm_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(m_confirm_label);

        m_confirm_edit = new QLineEdit(page);
        m_confirm_edit->setObjectName(QString::fromUtf8("m_confirm_edit"));
        m_confirm_edit->setMinimumSize(QSize(0, 25));
        m_confirm_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(m_confirm_edit);

        m_confirm_visible = new ClickedLabel(page);
        m_confirm_visible->setObjectName(QString::fromUtf8("m_confirm_visible"));
        m_confirm_visible->setMinimumSize(QSize(20, 20));
        m_confirm_visible->setMaximumSize(QSize(20, 20));
        m_confirm_visible->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_5->addWidget(m_confirm_visible);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        m_varify_label = new QLabel(page);
        m_varify_label->setObjectName(QString::fromUtf8("m_varify_label"));
        m_varify_label->setMinimumSize(QSize(0, 25));
        m_varify_label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_6->addWidget(m_varify_label);

        m_varify_edit = new QLineEdit(page);
        m_varify_edit->setObjectName(QString::fromUtf8("m_varify_edit"));
        m_varify_edit->setMinimumSize(QSize(0, 25));
        m_varify_edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_6->addWidget(m_varify_edit);

        m_get_code = new CTimerBtn(page);
        m_get_code->setObjectName(QString::fromUtf8("m_get_code"));
        m_get_code->setMinimumSize(QSize(0, 25));
        m_get_code->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_6->addWidget(m_get_code);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        m_sure_btn = new QPushButton(page);
        m_sure_btn->setObjectName(QString::fromUtf8("m_sure_btn"));
        m_sure_btn->setMinimumSize(QSize(0, 25));
        m_sure_btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_7->addWidget(m_sure_btn);

        m_cancel_btn = new QPushButton(page);
        m_cancel_btn->setObjectName(QString::fromUtf8("m_cancel_btn"));
        m_cancel_btn->setMinimumSize(QSize(0, 25));
        m_cancel_btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_7->addWidget(m_cancel_btn);


        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_5 = new QVBoxLayout(page_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        m_tip_lb = new QLabel(page_2);
        m_tip_lb->setObjectName(QString::fromUtf8("m_tip_lb"));
        m_tip_lb->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(m_tip_lb);

        m_tip2_lb = new QLabel(page_2);
        m_tip2_lb->setObjectName(QString::fromUtf8("m_tip2_lb"));
        m_tip2_lb->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(m_tip2_lb);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_6);

        widget_2 = new QWidget(page_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        m_return_btn = new QPushButton(widget_2);
        m_return_btn->setObjectName(QString::fromUtf8("m_return_btn"));
        m_return_btn->setMinimumSize(QSize(0, 25));
        m_return_btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(m_return_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_5->addWidget(widget_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(register_Dialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(register_Dialog);
    } // setupUi

    void retranslateUi(QDialog *register_Dialog)
    {
        register_Dialog->setWindowTitle(QCoreApplication::translate("register_Dialog", "Dialog", nullptr));
        m_err_tip->setText(QCoreApplication::translate("register_Dialog", "\351\224\231\350\257\257\346\217\220\347\244\272", nullptr));
        m_user_label->setText(QCoreApplication::translate("register_Dialog", "\347\224\250\346\210\267\357\274\232", nullptr));
        m_email_label->setText(QCoreApplication::translate("register_Dialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        m_email_edit->setText(QCoreApplication::translate("register_Dialog", "3194811890@qq.com", nullptr));
        m_pass_label->setText(QCoreApplication::translate("register_Dialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        m_pass_visible->setText(QString());
        m_confirm_label->setText(QCoreApplication::translate("register_Dialog", "\347\241\256\350\256\244\357\274\232", nullptr));
        m_confirm_visible->setText(QString());
        m_varify_label->setText(QCoreApplication::translate("register_Dialog", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        m_get_code->setText(QCoreApplication::translate("register_Dialog", "\350\216\267\345\217\226", nullptr));
        m_sure_btn->setText(QCoreApplication::translate("register_Dialog", "\347\241\256\350\256\244", nullptr));
        m_cancel_btn->setText(QCoreApplication::translate("register_Dialog", "\345\217\226\346\266\210", nullptr));
        m_tip_lb->setText(QCoreApplication::translate("register_Dialog", "\346\263\250\345\206\214\346\210\220\345\212\237\357\274\2145 s\345\220\216\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
        m_tip2_lb->setText(QCoreApplication::translate("register_Dialog", "\345\217\257\347\202\271\345\207\273\350\277\224\345\233\236\346\214\211\351\222\256\347\233\264\346\216\245\350\277\224\345\233\236\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
        m_return_btn->setText(QCoreApplication::translate("register_Dialog", "\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class register_Dialog: public Ui_register_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_DIALOG_H
