#include "httpcontroller.h"

httpController::~httpController()
{

}

httpController::httpController()
{
    //连接http请求和完成信号，信号槽机制保证队列消费
    connect(this, &httpController::sig_http_finish, this, &httpController::slot_http_finish);
}

void httpController::PostHttpReq(QUrl url, QJsonObject json, ReqId reQ_id, Modules mod)
{
    QByteArray data=QJsonDocument(json).toJson();
    QNetworkRequest request(url);
    //设置传输类型json，xml
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    //设置传输的类型数据的长度
    request.setHeader(QNetworkRequest::ContentLengthHeader,QByteArray::number(data.length()));
    //使shared_ptr更安全
    auto ptr=shared_from_this();
    QNetworkReply * reply = m_Manager.post(request, data);
    reply->error();
    //设置信号和槽等待发送完成
    //为什么不直接传this指针，防止httpController这个对象被提前删除，使用shared_from_this创建一个shared_ptr防止对象提前被删除，所产生的程序崩溃问题
    QObject::connect(reply, &QNetworkReply::finished, [reply, ptr, reQ_id, mod](){
        //处理错误的情况
        if(reply->error() != QNetworkReply::NoError){
            qDebug() << reply->errorString();
            //发送信号通知完成
            emit ptr->sig_http_finish(reQ_id, "", ErrorCodes::ERR_NETWORK, mod);
            reply->deleteLater();
            return;
        }

        //无错误则读回请求
        QString res = reply->readAll();

        //发送信号通知完成
        emit ptr->sig_http_finish(reQ_id, res, ErrorCodes::SUCCESS,mod);
        reply->deleteLater();
        return;
    });
}


void httpController::slot_http_finish(ReqId id, QString res, ErrorCodes err, Modules mod)
{
    if(mod == Modules::REGISTERMOD){
        //发送信号通知指定模块http响应结束
        emit sig_reg_mod_finish(id, res, err);
    }

    if(mod == Modules::RESETMOD){
        //发送信号通知指定模块http响应结束
        emit sig_reset_mod_finish(id, res, err);
    }

    if(mod == Modules::LOGINMOD){
        emit sig_login_mod_finish(id, res, err);
    }
}












































