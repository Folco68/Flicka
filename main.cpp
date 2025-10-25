#include "DropWindow/DropWindow.hpp"
#include <QApplication>
#include <QGuiApplication>

int main(int argc, char* argv[])
{
    QApplication Application(argc, argv);
    Application.setWindowIcon(QIcon(":/Icons/IconBase.ico"));
    DropWindow DropWindow;
    DropWindow.show();
    return Application.exec();
}
