#include "logindialog.h"
#include "ui_logindialog.h"
#include <QDebug>
#include "httpcontroller.h"

#include <QRegExp>
#include <QRegularExpression>
#include <QPainter>
#include "logindialog.h"
#include"tcpmgr.h"
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->m_forget_label->SetState("normal","hover","","selected","selected_hover","");
    ui->m_forget_label->setCursor(Qt::PointingHandCursor);
    //初始化信号槽链接
    initConnont();
    initHead();
    initFun_Hand();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::initConnont()
{
    connect(ui->m_reg_btn,&QPushButton::clicked,this,&LoginDialog::Converttoregistration_signals);
    connect(ui->m_forget_label, &ClickedLabel::clicked, this, &LoginDialog::slot_forget_pwd);
    //连接登录回包信号
    connect(httpController::Get_M_ptr().get(), &httpController::sig_login_mod_finish, this,
            &LoginDialog::slot_login_mod_finish);
    connect(this,&LoginDialog::sig_connect_tcp,TcpMgr::Get_M_ptr().get(),&TcpMgr::slot_tcp_connect);
     connect(TcpMgr::Get_M_ptr().get(),&TcpMgr::sig_con_success,this,&LoginDialog::slot_tcp_con_finish);
}

void LoginDialog::slot_forget_pwd()
{
    qDebug()<<"slot forget pwd";
    emit switchReset();
}

void LoginDialog::initHead()
{
    //加载图片，后期连接本地数据库，让用户可以自行选择登录头像
     QPixmap originalPixmap(":/res/head_2.jpg");
    // 设置图片自动缩放
     qDebug()<<originalPixmap.size()<<ui->m_head_label->size();
     originalPixmap = originalPixmap.scaled(ui->m_head_label->size(),
             Qt::KeepAspectRatio, Qt::SmoothTransformation);

     // 创建一个和原始图片相同大小的QPixmap，用于绘制圆角图片
     QPixmap roundedPixmap(originalPixmap.size());
     roundedPixmap.fill(Qt::transparent); // 用透明色填充

     QPainter painter(&roundedPixmap);
     painter.setRenderHint(QPainter::Antialiasing); // 设置抗锯齿，使圆角更平滑
     painter.setRenderHint(QPainter::SmoothPixmapTransform);

     // 使用QPainterPath设置圆角
     QPainterPath path;
     path.addRoundedRect(0, 0, originalPixmap.width(), originalPixmap.height(), 50, 50); // 最后两个参数分别是x和y方向的圆角半径
     painter.setClipPath(path);

     // 将原始图片绘制到roundedPixmap上
     painter.drawPixmap(0, 0, originalPixmap);

     // 设置绘制好的圆角图片到QLabel上
     ui->m_head_label->setPixmap(roundedPixmap);
}
void LoginDialog::showTip(QString str, bool b_ok)
{
    if(b_ok){
         ui->m_err_tip->setProperty("state","normal");
    }else{
        ui->m_err_tip->setProperty("state","err");
    }

    ui->m_err_tip->setText(str);

    repolish(ui->m_err_tip);
}

bool LoginDialog::checkUserValid(){

    auto email = ui->m_email_edit->text();
    if(email.isEmpty()){
        qDebug() << "email empty " ;
        AddTipErr(TipErr::TIP_EMAIL_ERR, tr("邮箱不能为空"));
        return false;
    }
    DelTipErr(TipErr::TIP_EMAIL_ERR);
    return true;
}

bool LoginDialog::checkPwdValid(){
    auto pwd = ui->m_pass_edit->text();
    if(pwd.length() < 6 || pwd.length() > 15){
        qDebug() << "Pass length invalid";
        //提示长度不准确
        AddTipErr(TipErr::TIP_PWD_ERR, tr("密码长度应为6~15"));
        return false;
    }

    // 创建一个正则表达式对象，按照上述密码要求
    // 这个正则表达式解释：
    // ^[a-zA-Z0-9!@#$%^&*]{6,15}$ 密码长度至少6，可以是字母、数字和特定的特殊字符
    QRegularExpression regExp("^[a-zA-Z0-9!@#$%^&*]{6,15}$");
    bool match = regExp.match(pwd).hasMatch();
    if(!match){
        //提示字符非法
        AddTipErr(TipErr::TIP_PWD_ERR, tr("不能包含非法字符且长度为(6~15)"));
        return false;;
    }

    DelTipErr(TipErr::TIP_PWD_ERR);

    return true;
}
void LoginDialog::AddTipErr(TipErr te,QString tips){
    _tip_errs[te] = tips;
    showTip(tips, false);
}
void LoginDialog::DelTipErr(TipErr te){
    _tip_errs.remove(te);
    if(_tip_errs.empty()){
      ui->m_err_tip->clear();
      return;
    }

    showTip(_tip_errs.first(), false);
}
bool LoginDialog::enableBtn(bool enabled)
{
    ui->m_login_btn->setEnabled(enabled);
    ui->m_reg_btn->setEnabled(enabled);
    return true;
}

void LoginDialog::initFun_Hand()
{
    //注册获取登录回包,链接tcp服务端
    m_Funhands.insert(ReqId::ID_LOGIN_USER,[this](QJsonObject jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCESS){
            showTip(tr("参数错误"),false);
            enableBtn(true);
            return;
        }
        auto email = jsonObj["email"].toString();

        //发送信号通知tcpMgr发送长链接
        ServerInfo si;
        si.Uid = jsonObj["uid"].toInt();
        si.Host = jsonObj["host"].toString();
        si.Port = jsonObj["port"].toString();
        si.Token = jsonObj["token"].toString();

        _uid = si.Uid;
        _token = si.Token;
        qDebug()<< "email is " << email << " uid is " << si.Uid <<" host is "
                << si.Host << " Port is " << si.Port << " Token is " << si.Token;
        emit sig_connect_tcp(si);
    });
}
void LoginDialog::on_m_login_btn_clicked()
{
    qDebug()<<"login btn clicked";
    if(checkUserValid() == false){
        return;
    }

    if(checkPwdValid() == false){
        return ;
    }

    enableBtn(false);
    auto email = ui->m_email_edit->text();
    auto pwd = ui->m_pass_edit->text();
    //发送http请求登录
    QJsonObject json_obj;
    json_obj["email"] = email;
    json_obj["passwd"] = xorString(pwd);
    httpController::Get_M_ptr()->PostHttpReq(QUrl(gate_url_prefix+"/user_login"),
                                             json_obj, ReqId::ID_LOGIN_USER,Modules::LOGINMOD);
}

void LoginDialog::slot_login_mod_finish(ReqId id, QString res, ErrorCodes err)
{
    if(err != ErrorCodes::SUCCESS){
        showTip(tr("网络请求错误"),false);
        return;
    }

    // 解析 JSON 字符串,res需转化为QByteArray
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    //json解析错误
    if(jsonDoc.isNull()){
        showTip(tr("json解析错误"),false);
        return;
    }

    //json解析错误
    if(!jsonDoc.isObject()){
        showTip(tr("json解析错误"),false);
        return;
    }


    //调用对应的逻辑,根据id回调。
    m_Funhands[id](jsonDoc.object());

    return;
}

void LoginDialog::slot_tcp_con_finish(bool bsuccess)
{
    if(bsuccess){
          showTip(tr("聊天服务连接成功，正在登录..."),true);
          QJsonObject jsonObj;
          jsonObj["uid"] = _uid;
          jsonObj["token"] = _token;

          QJsonDocument doc(jsonObj);
          QString jsonString = doc.toJson(QJsonDocument::Indented);

          //发送tcp请求给chat server
          TcpMgr::Get_M_ptr()->sig_send_data(ReqId::ID_CHAT_LOGIN, jsonString);

       }else{
          showTip(tr("网络异常"),false);
          enableBtn(true);
       }
}
