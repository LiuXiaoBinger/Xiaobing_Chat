#ifndef CTIMERBTN_H
#define CTIMERBTN_H

#include <QPushButton>
#include <QTimer>
class CTimerBtn: public QPushButton
{
public:
    CTimerBtn(QWidget *parent = nullptr);
    ~ CTimerBtn();

    // 重写mouseReleaseEvent
    virtual void mouseReleaseEvent(QMouseEvent *e) override;
private:
    QTimer  *btn_timer;
    int _counter;
};

#endif // CTIMERBTN_H
