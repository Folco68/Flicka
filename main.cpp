#include "FileDrop/DropWindow.hpp"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication Application(argc, argv);
    DropWindow   DropWindow;
    DropWindow.show();
    return Application.exec();
}
