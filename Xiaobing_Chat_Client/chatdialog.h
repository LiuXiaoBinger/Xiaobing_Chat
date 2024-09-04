#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include "globa.h"
namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();
public slots:
    void slot_loading_chat_user();
private:
    void addChatUserList();
    Ui::ChatDialog *ui;
    bool _b_loading;
    //QList<StateWidget*> _lb_list;
    void ShowSearch(bool bsearch = false);
    ChatUIMode _mode;
    ChatUIMode _state;
    QWidget* _last_widget;
    //todo...
   // QMap<int, QListWidgetItem*> _chat_items_added;
    int _cur_chat_uid;
};

#endif // CHATDIALOG_H
