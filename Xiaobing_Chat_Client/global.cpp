#include"globa.h"
//在代码中使用自定义属性时，最好repolish下重载下以求得到此时此刻正确的属性值
std::function<void(QWidget*)> repolish=[](QWidget*ptr){
    ptr->style()->unpolish(ptr);
    ptr->style()->polish(ptr);
};
std::function<QString(QString)> xorString = [](QString input){
    QString result = input; // 复制原始字符串，以便进行修改
    int length = input.length(); // 获取字符串的长度
    ushort xor_code = length % 255;
    for (int i = 0; i < length; ++i) {
        // 对每个字符进行异或操作
        // 注意：这里假设字符都是ASCII，因此直接转换为QChar
        result[i] = QChar(static_cast<ushort>(input[i].unicode() ^ xor_code));
    }
    return result;
};
QString gate_url_prefix = "";
