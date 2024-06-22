#include "xiaobing_chat_client.h"
#include "ui_xiaobing_chat_client.h"
/******************************************************************************
 *
 * @file       xiaobing_chat_client.cpp
 * @brief      主窗口
 *
 * @author     刘小饼儿
 * @date       2024/05/25
 * @history
 *****************************************************************************/
Xiaobing_Chat_Client::Xiaobing_Chat_Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Xiaobing_Chat_Client)
{
    ui->setupUi(this);
    initUi();

}

Xiaobing_Chat_Client::~Xiaobing_Chat_Client()
{
    delete ui;
}

void Xiaobing_Chat_Client::ConverttoregistrationSlots()
{
    setCentralWidget(m_Register_dlg);
    m_Login_dlg->hide();
    m_Register_dlg->show();
}



void Xiaobing_Chat_Client::initUi()
{
    //登录窗口初始化
    m_Login_dlg=new LoginDialog(this);
    // connect(m_Login_dlg,&LoginDialog::Converttoregistration_signals,this,&Xiaobing_Chat_Client::ConverttoregistrationSlots);
    //这两个标志用于在Qt中创建无边框的窗口。Qt::CustomizeWindowHint用于指示Qt不应用默认窗口标题栏，Qt::FramelessWindowHint用于创建一个没有边框的窗口。
    m_Login_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);//让登录窗口镶嵌到主窗口
   //使用setCentralWidget可能会把之前的删掉
    setCentralWidget(m_Login_dlg);
    m_Login_dlg->show();

    //连接登录界面注册信号
       connect(m_Login_dlg, &LoginDialog::Converttoregistration_signals, this, &Xiaobing_Chat_Client::SlotSwitchReg);
//       //连接登录界面忘记密码信号
//       connect(m_Login_dlg, &LoginDialog::switchReset, this, &Xiaobing_Chat_Client::SlotSwitchReset);

    //注册窗口初始化
    m_Register_dlg=new register_Dialog;
    m_Register_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);//让登录窗口镶嵌到主窗口
    //setCentralWidget(m_Register_dlg);

}
void Xiaobing_Chat_Client::SlotSwitchReg()
{
    m_Register_dlg = new register_Dialog(this);
    m_Register_dlg->hide();

     m_Register_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);//让登录窗口镶嵌到主窗口

     //连接注册界面返回登录信号
    connect(m_Register_dlg, &register_Dialog::sigSwitchLogin, this, &Xiaobing_Chat_Client::SlotSwitchLogin);
    setCentralWidget(m_Register_dlg);
    m_Login_dlg->hide();
    m_Register_dlg->show();
}
//从注册界面返回登录界面
void Xiaobing_Chat_Client::SlotSwitchLogin()
{
    //登录窗口初始化
    m_Login_dlg=new LoginDialog(this);
     //connect(m_Login_dlg,&LoginDialog::Converttoregistration_signals,this,&Xiaobing_Chat_Client::ConverttoregistrationSlots);
    //这两个标志用于在Qt中创建无边框的窗口。Qt::CustomizeWindowHint用于指示Qt不应用默认窗口标题栏，Qt::FramelessWindowHint用于创建一个没有边框的窗口。
    m_Login_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);//让登录窗口镶嵌到主窗口
   //使用setCentralWidget可能会把之前的删掉
    setCentralWidget(m_Login_dlg);

   m_Register_dlg->hide();
    m_Login_dlg->show();
    //连接登录界面注册信号
    connect(m_Login_dlg, &LoginDialog::Converttoregistration_signals, this, &Xiaobing_Chat_Client::SlotSwitchReg);
//    //连接登录界面忘记密码信号
//    connect(m_Login_dlg, &LoginDialog::switchReset, this, &Xiaobing_Chat_Client::SlotSwitchReset);
}
