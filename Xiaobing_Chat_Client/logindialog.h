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
#include "globa.h"
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();


public slots:
    void slot_forget_pwd();
    void initHead();//初始化登录头像
    void showTip(QString str, bool b_ok);
    bool checkUserValid();
    bool checkPwdValid();
signals:
    void Converttoregistration_signals();
    void switchReset();
    //根据状态服务器返回的数据，去连接chat服务
     void sig_connect_tcp(ServerInfo);
private slots:
    void on_m_login_btn_clicked();
    void slot_login_mod_finish(ReqId id, QString res, ErrorCodes err);
    void slot_tcp_con_finish(bool );
private:
    //初始化信号槽链接
    void initConnont();
    void AddTipErr(TipErr te, QString tips);
    void DelTipErr(TipErr te);
    bool enableBtn(bool enabled);
    //初始化函数对应表
    void initFun_Hand();
private:
    Ui::LoginDialog *ui;
    QMap<TipErr, QString> _tip_errs;
    QMap<ReqId,std::function<void(const QJsonObject&)>> m_Funhands;
    int _uid;
    QString _token;
};

#endif // LOGINDIALOG_H
