#ifndef HTTPCONTROLLER_H
#define HTTPCONTROLLER_H
/******************************************************************************
 *
 * @file       httpcontroller.h
 * @brief      单列http管理类
 *
 * @author     刘小饼儿
 * @date       2024/05/29/h/mm
 * @history
 *****************************************************************************/
#include "singleton.h"
#include <QString>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>
#include "globa.h"
#include <memory>

//CRPT
class httpController :public QObject,
        public Singleton<httpController>,
        public std::enable_shared_from_this<httpController>

{
    Q_OBJECT

public:

    ~httpController();
    void PostHttpReq(QUrl url,QJsonObject json,ReqId reQ_id,Modules mod);
private:
    friend class Singleton<httpController>;//让基类可以访问
    httpController();
    QNetworkAccessManager m_Manager;


public slots:
    void slot_http_finish(ReqId id, QString res, ErrorCodes err, Modules mod);
signals:
    void sig_http_finish(ReqId id, QString res, ErrorCodes err, Modules mod);
    //注册模块http相关请求完成发送此信号
    void sig_reg_mod_finish(ReqId id, QString res, ErrorCodes err);
    void sig_reset_mod_finish(ReqId id, QString res, ErrorCodes err);
    void sig_login_mod_finish(ReqId id, QString res, ErrorCodes err);
};

#endif // HTTPCONTROLLER_H
