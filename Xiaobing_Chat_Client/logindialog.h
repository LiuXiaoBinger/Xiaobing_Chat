#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
/******************************************************************************
 *
 * @file       logindialog.h
 * @brief      登录界面
 *
 * @author     刘小饼儿
 * @date       2024/05/26
 * @history
 *****************************************************************************/
#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
signals:
    void Converttoregistration_signals();
private:
    //初始化信号槽链接
    void initConnont();
private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
