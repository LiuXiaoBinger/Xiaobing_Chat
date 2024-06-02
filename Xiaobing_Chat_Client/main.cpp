#include "xiaobing_chat_client.h"
#include <QFile>
#include <QApplication>
#include "httpcontroller.h"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QFile qss(":/style/stylesheet.qss");
    if(qss.open(QFile::ReadOnly))
    {
        qDebug("qss,success");
        QString style = QLatin1String(qss.readAll());
                a.setStyleSheet(style);
                qss.close();
    }else{
        qDebug("qss,failed");
    }
    //加载config.ini
    // 获取当前应用程序的路径
    QString app_path=QCoreApplication::applicationDirPath();
    //因为系统不同<"/","\">需要对文件路径进行拼接
    QString config_fifleName="config.ini";
    QString config_path=QDir::toNativeSeparators(app_path+QDir::separator()+config_fifleName);
    QSettings configsettings(config_path,QSettings::IniFormat);
    QString gate_host = configsettings.value("GateServer/host").toString();
    QString gate_port = configsettings.value("GateServer/port").toString();
    gate_url_prefix = "http://"+gate_host+":"+gate_port;
    Xiaobing_Chat_Client w;
    w.show();
    return a.exec();
}
