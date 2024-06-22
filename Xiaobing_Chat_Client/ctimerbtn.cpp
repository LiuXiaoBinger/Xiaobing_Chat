#include "ctimerbtn.h"
#include <QMouseEvent>
#include <QDebug>

CTimerBtn::CTimerBtn(QWidget *ptr):QPushButton(ptr),_counter(10)
{
    btn_timer = new QTimer(this);
        connect(btn_timer, &QTimer::timeout, [this](){
            _counter--;
            if(_counter <= 0)
            {
                btn_timer->stop();
                _counter = 10;
                this->setText("获取");
                this->setEnabled(true);
                return;
            }
            this->setText(QString::number(_counter));
        });
}

CTimerBtn::~CTimerBtn()
{
    btn_timer->stop();
}

void CTimerBtn::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
           // 在这里处理鼠标左键释放事件
           qDebug() << "MyButton was released!";
           this->setEnabled(false);
            this->setText(QString::number(_counter));
           btn_timer->start(1000);
           emit clicked();
       }
       // 调用基类的mouseReleaseEvent以确保正常的事件处理（如点击效果）
       QPushButton::mouseReleaseEvent(e);
}
