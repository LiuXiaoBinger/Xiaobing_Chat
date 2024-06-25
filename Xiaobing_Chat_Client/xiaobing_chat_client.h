#ifndef XIAOBING_CHAT_CLIENT_H
#define XIAOBING_CHAT_CLIENT_H
#include <QMainWindow>
#include "logindialog.h"
#include "register_dialog.h"
#include"resetdialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Xiaobing_Chat_Client; }
QT_END_NAMESPACE

class Xiaobing_Chat_Client : public QMainWindow
{
    Q_OBJECT

public:
    Xiaobing_Chat_Client(QWidget *parent = nullptr);
    ~Xiaobing_Chat_Client();
public slots:
    //切换登录注册界面
    void ConverttoregistrationSlots();

    void SlotSwitchReg();
    void SlotSwitchLogin();
    void SlotSwitchReset();
    void SlotSwitchLogin2();
private:
    void initUi();
private:
    Ui::Xiaobing_Chat_Client *ui;
    //登录注册窗口
    LoginDialog* m_Login_dlg=nullptr;
    register_Dialog *m_Register_dlg=nullptr;
    ResetDialog *m_reset_dlg =nullptr;
};
#endif // XIAOBING_CHAT_CLIENT_H
