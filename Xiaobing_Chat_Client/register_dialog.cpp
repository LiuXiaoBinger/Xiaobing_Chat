#include "register_dialog.h"
#include "ui_register_dialog.h"
#include "globa.h"
#include "QRegularExpression"
#include "httpcontroller.h"

register_Dialog::register_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::register_Dialog),_countdown(5)
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
    //注册
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
    //注册用户回包逻辑
    _handle_Fun.insert(ReqId::ID_REG_USER, [this](QJsonObject jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCESS){
            showTip(tr("参数错误"),false);
            return;
        }
        auto email = jsonObj["email"].toString();
        showTip(tr("用户注册成功"), true);
        qDebug()<< "email is " << email ;
        qDebug()<< "user uuid is " <<  jsonObj["uuid"].toString();
           ChangeTipPage();
    });
}
void register_Dialog::ChangeTipPage()
{
    _countdown_timer->stop();
    ui->stackedWidget->setCurrentWidget(ui->page_2);

    // 启动定时器，设置间隔为1000毫秒（1秒）
    _countdown_timer->start(1000);
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
void register_Dialog::AddTipErr(TipErr te, QString tips)
{
    _tip_errs[te] = tips;
    showTip(tips, false);
}

void register_Dialog::DelTipErr(TipErr te)
{
    _tip_errs.remove(te);
    if(_tip_errs.empty()){
      ui->m_err_tip->clear();
      return;
    }

    showTip(_tip_errs.first(), false);
}
void register_Dialog::initConnont()
{
    connect(ui->m_get_code,&QPushButton::clicked,this,&register_Dialog::on_get_code_slot_m);
    //链接网络登录  slot_reg_mod_finish
    connect(httpController::Get_M_ptr().get(),&httpController::sig_reg_mod_finish,this
            ,&register_Dialog::slot_reg_mod_finish);

    ui->m_err_tip->clear();

    connect(ui->m_user_edit,&QLineEdit::editingFinished,this,[this](){
        checkUserValid();
    });

    connect(ui->m_email_edit, &QLineEdit::editingFinished, this, [this](){
        checkEmailValid();
    });

    connect(ui->m_pass_edit, &QLineEdit::editingFinished, this, [this](){
        checkPassValid();
    });

    connect(ui->m_confirm_edit, &QLineEdit::editingFinished, this, [this](){
        checkConfirmValid();
    });

    connect(ui->m_varify_edit, &QLineEdit::editingFinished, this, [this](){
            checkVarifyValid();
    });


    //设置浮动显示手形状
    ui->m_pass_visible->setCursor(Qt::PointingHandCursor);
    ui->m_confirm_visible->setCursor(Qt::PointingHandCursor);

    ui->m_pass_visible->SetState("unvisible","unvisible_hover","","visible",
                                "visible_hover","");

    ui->m_confirm_visible->SetState("unvisible","unvisible_hover","","visible",
                                    "visible_hover","");
    //连接点击事件

    connect(ui->m_pass_visible, &ClickedLabel::clicked, this, [this]() {
        auto state = ui->m_pass_visible->GetCurState();
        if(state == ClickLbState::Normal){
            ui->m_pass_edit->setEchoMode(QLineEdit::Password);
        }else{
                ui->m_pass_edit->setEchoMode(QLineEdit::Normal);
        }
        qDebug() << "Label was clicked!";
    });

    connect(ui->m_confirm_visible, &ClickedLabel::clicked, this, [this]() {
        auto state = ui->m_confirm_visible->GetCurState();
        if(state == ClickLbState::Normal){
            ui->m_confirm_edit->setEchoMode(QLineEdit::Password);
        }else{
                ui->m_confirm_edit->setEchoMode(QLineEdit::Normal);
        }
        qDebug() << "Label was clicked!";
    });
    // 创建定时器
    _countdown_timer = new QTimer(this);
    // 连接信号和槽
    connect(_countdown_timer, &QTimer::timeout, [this](){
        if(_countdown==0){
            _countdown_timer->stop();
            emit sigSwitchLogin();
            return;
        }
        _countdown--;
        auto str = QString("注册成功，%1 s后返回登录").arg(_countdown);
        ui->m_tip_lb->setText(str);
    });
}
bool register_Dialog::checkConfirmValid()
{
    auto pass = ui->m_pass_edit->text();
    auto confirm = ui->m_confirm_edit->text();

    if(confirm.length() < 6 || confirm.length() > 15 ){
        //提示长度不准确
        AddTipErr(TipErr::TIP_CONFIRM_ERR, tr("密码长度应为6~15"));
        return false;
    }

    // 创建一个正则表达式对象，按照上述密码要求
    // 这个正则表达式解释：
    // ^[a-zA-Z0-9!@#$%^&*]{6,15}$ 密码长度至少6，可以是字母、数字和特定的特殊字符
    QRegularExpression regExp("^[a-zA-Z0-9!@#$%^&*]{6,15}$");
    bool match = regExp.match(confirm).hasMatch();
    if(!match){
        //提示字符非法
        AddTipErr(TipErr::TIP_CONFIRM_ERR, tr("不能包含非法字符"));
        return false;
    }

    DelTipErr(TipErr::TIP_CONFIRM_ERR);

    if(pass != confirm){
        //提示密码不匹配
        AddTipErr(TipErr::TIP_PWD_CONFIRM, tr("确认密码和密码不匹配"));
        return false;
    }else{
       DelTipErr(TipErr::TIP_PWD_CONFIRM);
    }
    return true;
}

bool register_Dialog::checkUserValid()
{
    if(ui->m_user_edit->text() == ""){
        AddTipErr(TipErr::TIP_USER_ERR, tr("用户名不能为空"));
        return false;
    }

    DelTipErr(TipErr::TIP_USER_ERR);
    return true;
}

bool register_Dialog::checkPassValid()
{
    auto pass = ui->m_pass_edit->text();
    auto confirm = ui->m_confirm_edit->text();

    if(pass.length() < 6 || pass.length()>15){
        //提示长度不准确
        AddTipErr(TipErr::TIP_PWD_ERR, tr("密码长度应为6~15"));
        return false;
    }

    // 创建一个正则表达式对象，按照上述密码要求
    // 这个正则表达式解释：
    // ^[a-zA-Z0-9!@#$%^&*]{6,15}$ 密码长度至少6，可以是字母、数字和特定的特殊字符
    QRegularExpression regExp("^[a-zA-Z0-9!@#$%^&*]{6,15}$");
    bool match = regExp.match(pass).hasMatch();
    if(!match){
        //提示字符非法
        AddTipErr(TipErr::TIP_PWD_ERR, tr("不能包含非法字符"));
        return false;;
    }

    DelTipErr(TipErr::TIP_PWD_ERR);

    if(pass != confirm){
        //提示密码不匹配
        AddTipErr(TipErr::TIP_PWD_CONFIRM, tr("密码和确认密码不匹配"));
        return false;
    }else{
       DelTipErr(TipErr::TIP_PWD_CONFIRM);
    }
    return true;
}

bool register_Dialog::checkEmailValid()
{
    //验证邮箱的地址正则表达式
    auto email = ui->m_email_edit->text();
    // 邮箱地址的正则表达式
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch(); // 执行正则表达式匹配
    if(!match){
        //提示邮箱不正确
        AddTipErr(TipErr::TIP_EMAIL_ERR, tr("邮箱地址不正确"));
        return false;
    }

    DelTipErr(TipErr::TIP_EMAIL_ERR);
    return true;
}

bool register_Dialog::checkVarifyValid()
{
    auto pass = ui->m_varify_edit->text();
    if(pass.isEmpty()){
        AddTipErr(TipErr::TIP_VARIFY_ERR, tr("验证码不能为空"));
        return false;
    }

    DelTipErr(TipErr::TIP_VARIFY_ERR);
    return true;
}
void register_Dialog::on_m_sure_btn_clicked()
{
    bool valid = checkUserValid();
        if(!valid){
            return;
        }

        valid = checkEmailValid();
        if(!valid){
            return;
        }

        valid = checkPassValid();
        if(!valid){
            return;
        }

        valid = checkVarifyValid();
        if(!valid){
            return;
        }
        //发送http请求注册用户
        QJsonObject json_obj;
        json_obj["user"] = ui->m_user_edit->text();
        json_obj["email"] = ui->m_email_edit->text();
        json_obj["passwd"] = xorString(ui->m_pass_edit->text());
        json_obj["confirm"] = ui->m_confirm_edit->text();
        json_obj["varifycode"] = ui->m_varify_edit->text();
        httpController::Get_M_ptr()->PostHttpReq(QUrl(gate_url_prefix+"/user_register"),
                     json_obj, ReqId::ID_REG_USER,Modules::REGISTERMOD);
}

void register_Dialog::on_m_return_btn_clicked()
{
    _countdown_timer->stop();
       emit sigSwitchLogin();
}

void register_Dialog::on_m_cancel_btn_clicked()
{
    _countdown_timer->stop();
        emit sigSwitchLogin();
}
