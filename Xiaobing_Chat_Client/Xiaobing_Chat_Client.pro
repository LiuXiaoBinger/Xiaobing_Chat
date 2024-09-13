QT       += core gui network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

RC_ICONS = icon.ico
DESTDIR = ./bin
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ChatView.cpp \
    MessageTextEdit.cpp \
    PictureBubble.cpp \
    TextBubble.cpp \
    adduseritem.cpp \
    applyfriendpage.cpp \
    bubbleframe.cpp \
    chatdialog.cpp \
    chatitembase.cpp \
    chatpage.cpp \
    chatuserlist.cpp \
    chatuserwid.cpp \
    clickedbtn.cpp \
    clickedlabel.cpp \
    ctimerbtn.cpp \
    customizeedit.cpp \
    findsuccessdlg.cpp \
    friendinfopage.cpp \
    global.cpp \
    httpcontroller.cpp \
    listitembase.cpp \
    loadingdlg.cpp \
    logindialog.cpp \
    main.cpp \
    register_dialog.cpp \
    resetdialog.cpp \
    searchlist.cpp \
    statewidget.cpp \
    tcpmgr.cpp \
    userdata.cpp \
    usermgr.cpp \
    xiaobing_chat_client.cpp

HEADERS += \
    ChatView.h \
    MessageTextEdit.h \
    PictureBubble.h \
    TextBubble.h \
    adduseritem.h \
    applyfriendpage.h \
    bubbleframe.h \
    chatdialog.h \
    chatitembase.h \
    chatpage.h \
    chatuserlist.h \
    chatuserwid.h \
    clickedbtn.h \
    clickedlabel.h \
    ctimerbtn.h \
    customizeedit.h \
    findsuccessdlg.h \
    friendinfopage.h \
    globa.h \
    httpcontroller.h \
    listitembase.h \
    loadingdlg.h \
    logindialog.h \
    register_dialog.h \
    resetdialog.h \
    searchlist.h \
    singleton.h \
    statewidget.h \
    tcpmgr.h \
    userdata.h \
    usermgr.h \
    xiaobing_chat_client.h

FORMS += \
    adduseritem.ui \
    applyfriendpage.ui \
    chatdialog.ui \
    chatpage.ui \
    chatuserwid.ui \
    findsuccessdlg.ui \
    friendinfopage.ui \
    loadingdlg.ui \
    logindialog.ui \
    register_dialog.ui \
    resetdialog.ui \
    xiaobing_chat_client.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rc.qrc
DISTFILES += \
    config.ini
CONFIG(debug, debug|release) {
        #debug
    message("debug mode")
    #指定要拷贝的文件目录为工程目录下release目录下的所有dll、lib文件，例如工程目录在D:\QT\Test
    #PWD就为D:/QT/Test，DllFile = D:/QT/Test/release/*.dll
    TargetConfig = $${PWD}/config.ini
    #将输入目录中的"/"替换为"\"
    TargetConfig = $$replace(TargetConfig, /, \\)
    #将输出目录中的"/"替换为"\"
    OutputDir =  $${OUT_PWD}/$${DESTDIR}
    OutputDir = $$replace(OutputDir, /, \\)
    //执行copy命令
    QMAKE_POST_LINK += copy /Y \"$$TargetConfig\" \"$$OutputDir\" &

    # 首先，定义static文件夹的路径
    StaticDir = $${PWD}/static
    # 将路径中的"/"替换为"\"
    StaticDir = $$replace(StaticDir, /, \\)
    #message($${StaticDir})
    # 使用xcopy命令拷贝文件夹，/E表示拷贝子目录及其内容，包括空目录。/I表示如果目标不存在则创建目录。/Y表示覆盖现有文件而不提示。
     QMAKE_POST_LINK += xcopy /Y /E /I \"$$StaticDir\" \"$$OutputDir\\static\\\"
}else{
      #release
    message("release mode")
    #指定要拷贝的文件目录为工程目录下release目录下的所有dll、lib文件，例如工程目录在D:\QT\Test
    #PWD就为D:/QT/Test，DllFile = D:/QT/Test/release/*.dll
    TargetConfig = $${PWD}/config.ini
    #将输入目录中的"/"替换为"\"
    TargetConfig = $$replace(TargetConfig, /, \\)
    #将输出目录中的"/"替换为"\"
    OutputDir =  $${OUT_PWD}/$${DESTDIR}
    OutputDir = $$replace(OutputDir, /, \\)
    //执行copy命令
    QMAKE_POST_LINK += copy /Y \"$$TargetConfig\" \"$$OutputDir\"

    # 首先，定义static文件夹的路径
    StaticDir = $${PWD}/static
    # 将路径中的"/"替换为"\"
    StaticDir = $$replace(StaticDir, /, \\)
    #message($${StaticDir})
    # 使用xcopy命令拷贝文件夹，/E表示拷贝子目录及其内容，包括空目录。/I表示如果目标不存在则创建目录。/Y表示覆盖现有文件而不提示。
     QMAKE_POST_LINK += xcopy /Y /E /I \"$$StaticDir\" \"$$OutputDir\\static\\\"
}

win32-msvc*:QMAKE_CXXFLAGS += /wd"4819" /utf-8
