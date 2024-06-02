#ifndef REGISTER_DIALOG_H
#define REGISTER_DIALOG_H
/******************************************************************************
 *
 * @file       register_dialog.h
 * @brief      注册界面
 *
 * @author     刘小饼儿
 * @date       2024/05/26
 * @history
 *****************************************************************************/
#include <QDialog>
#include "globa.h"
namespace Ui {
class register_Dialog;
}

class register_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit register_Dialog(QWidget *parent = nullptr);
    ~register_Dialog();


private slots:
    void on_get_code_slot_m();
    //http返回登录
    void slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err);
private:
    void initUi();
    //初始化信号槽链接
    void initConnont();
    void showTip(QString str, bool b_ok);
    void init_handle_Fun();
private:
    Ui::register_Dialog *ui;

    //id对应的函数
    QMap<int,std::function<void(const QJsonObject&)>> _handle_Fun;
};

#endif // REGISTER_DIALOG_H
