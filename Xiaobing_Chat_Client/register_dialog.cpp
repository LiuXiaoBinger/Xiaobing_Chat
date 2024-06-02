#include "register_dialog.h"
#include "ui_register_dialog.h"
#include "globa.h"
#include "QRegularExpression"
#include "httpcontroller.h"

register_Dialog::register_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::register_Dialog)
{
    ui->setupUi(this);
    initUi();
    initConnont();
    init_handle_Fun();
}

register_Dialog::~register_Dialog()
{
    delete ui;
}
void register_Dialog::showTip(QString str, bool b_ok)
{
    if(b_ok){
        ui->m_err_tip->setProperty("state","normal");
    }else{
        ui->m_err_tip->setProperty("state","err");
    }

    ui->m_err_tip->setText(str);

    repolish(ui->m_err_tip);
}

void register_Dialog::init_handle_Fun()
{
    _handle_Fun.insert(ReqId::ID_GET_VARIFY_CODE,[this](QJsonObject jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCESS){
            showTip(tr("参数错误"),false);
            return;
        }
        auto email = jsonObj["email"].toString();
        showTip(tr("验证码已发送到邮箱，注意查收"), true);
        qDebug()<< "email is " << email ;
    });
}

void register_Dialog::on_get_code_slot_m()
{
    //验证邮箱的地址正则表达式
    auto email = ui->m_email_edit->text();
    // 邮箱地址的正则表达式
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch(); // 执行正则表达式匹配
    if(match){
        //发送http请求获取验证码
        QJsonObject json_Obj;
        json_Obj["email"]=email;
        httpController::Get_M_ptr()->PostHttpReq(
                    QUrl(QUrl(gate_url_prefix+"/get_varifycode")),json_Obj,ReqId::ID_GET_VARIFY_CODE,Modules::REGISTERMOD);
    }else{
        //提示邮箱不正确
        showTip(tr("邮箱地址不正确"),false);
    }
}

void register_Dialog::slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err)
{
    if(err!=ErrorCodes::SUCCESS){
        showTip("网络请求错误",false);
        return;
    }
    //解析Json字符串，res需要转换成QByteArray
    QJsonDocument JsonDoc=QJsonDocument::fromJson(res.toUtf8());
    //Json解析错误
    if(JsonDoc.isNull()){
        showTip("Json解析错误",false);
        return;
    }
    //Json解析错误,是否可以转换成json对象
    if(!JsonDoc.isObject()){
        showTip("Json解析错误",false);
        return;
    }
    QJsonObject jsonObj = JsonDoc.object();
    if(_handle_Fun.find(id)!=_handle_Fun.end())
    {
        _handle_Fun[id](jsonObj);
    }

    //调用对应的逻辑
    return;

}

void register_Dialog::initUi()
{
    ui->m_pass_edit->setEchoMode(QLineEdit::Password);
    ui->m_confirm_edit->setEchoMode(QLineEdit::Password);

    ui->m_err_tip->setProperty("state","normal");
    repolish(ui->m_err_tip);
}

void register_Dialog::initConnont()
{
    connect(ui->m_get_code,&QPushButton::clicked,this,&register_Dialog::on_get_code_slot_m);
    //链接网络登录  slot_reg_mod_finish
    connect(httpController::Get_M_ptr().get(),&httpController::sig_reg_mod_finish,this
            ,&register_Dialog::slot_reg_mod_finish);
}
