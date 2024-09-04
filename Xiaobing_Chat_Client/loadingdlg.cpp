#include "loadingdlg.h"
#include "ui_loadingdlg.h"
#include <QLabel>
#include <QMovie>
#include <QGraphicsOpacityEffect>
#include <QGuiApplication>
#include <QScreen>

LoadingDlg::LoadingDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadingDlg)
{
    ui->setupUi(this);

//    Qt::Dialog:
//    指定窗口是一个对话框。对话框通常是模态的（阻止与其他窗口的交互），并且具有特定的外观和行为。
//    Qt::FramelessWindowHint:
//    创建一个无边框的窗口。无边框窗口没有标题栏和边框，通常用于自定义窗口外观。
//    Qt::WindowSystemMenuHint:
//    提供系统菜单提示。对于某些平台，这个标志允许窗口显示系统菜单（通常在窗口的标题栏中）。
//    Qt::WindowStaysOnTopHint:
//    窗口始终保持在其他窗口的顶部。这对于需要始终可见的工具窗口或通知窗口特别有用。
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground); // 设置背景透明
    // 获取屏幕尺寸
    setFixedSize(parent->size()); // 设置对话框为全屏尺寸

    QMovie *movie = new QMovie(":/res/loading.gif"); // 加载动画的资源文件
    ui->loading_lb->setMovie(movie);//movie会跟随界面自动析构
    movie->start();
}

LoadingDlg::~LoadingDlg()
{
    delete ui;
}
