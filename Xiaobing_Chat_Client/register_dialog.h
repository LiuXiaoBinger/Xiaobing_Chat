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

    bool checkUserValid();
    bool checkPassValid();
    bool checkEmailValid();
    bool checkVarifyValid();
    bool checkConfirmValid();
    void ChangeTipPage();
signals:
    void sigSwitchLogin();
public slots:
    //添加错误提示，删除错误提示
    void AddTipErr(TipErr te, QString tips);
    void DelTipErr(TipErr te);
private slots:
    void on_get_code_slot_m();
    //http返回登录
    void slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err);
    void on_m_sure_btn_clicked();

    void on_m_return_btn_clicked();

    void on_m_cancel_btn_clicked();

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

    //_tip_errs用来缓存各个输入框输入完成后提示的错误，如果该输入框错误清除后就显示剩余的错误，每次只显示一条实现添加错误和删除错误
    QMap<TipErr, QString> _tip_errs;
    QTimer * _countdown_timer;
    int _countdown;


};

#endif // REGISTER_DIALOG_H
