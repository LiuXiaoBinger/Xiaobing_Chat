#include"globa.h"
//在代码中使用自定义属性时，最好repolish下重载下以求得到此时此刻正确的属性值
std::function<void(QWidget*)> repolish=[](QWidget*ptr){
    ptr->style()->unpolish(ptr);
    ptr->style()->polish(ptr);
};

QString gate_url_prefix = "";
