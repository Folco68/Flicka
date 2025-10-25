#include "CompareWindow.hpp"
#include "../Global.hpp"
#include "ui_CompareWindow.h"

CompareWindow::CompareWindow(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::CompareWindow)
{
    ui->setupUi(this);
    setWindowTitle(QString("%1 - Compare").arg(APPLICATION_NAME));
}

CompareWindow::~CompareWindow()
{
    delete ui;
}
