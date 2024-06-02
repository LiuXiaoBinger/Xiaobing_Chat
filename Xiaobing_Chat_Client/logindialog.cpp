#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    //初始化信号槽链接
    initConnont();

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::initConnont()
{
    connect(ui->reg_btn,&QPushButton::clicked,this,&LoginDialog::Converttoregistration_signals);
}
