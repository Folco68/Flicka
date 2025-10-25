#include "CompareWindow.hpp"
#include "../Global.hpp"
#include "ui_CompareWindow.h"
#include <QTimer>

CompareWindow::CompareWindow(QString filename1, QString filename2, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::CompareWindow)
    , File1(filename1)
    , File2(filename2)
{
    ui->setupUi(this);
    setWindowTitle(QString("%1 - Compare").arg(APPLICATION_NAME));
    setWindowFlag(Qt::WindowMinMaxButtonsHint);
    ui->LineEditLeft->setText(this->File1);
    ui->LineEditRight->setText(this->File2);

    // Load the files outside of the constructor
    QTimer::singleShot(0, this, [this]() { loadFiles(); });
}

CompareWindow::~CompareWindow()
{
    delete ui;
}

void CompareWindow::loadFiles()
{
    loadFile(this->File1, ui->TreeLeft);
    loadFile(this->File2, ui->TreeRight);
}

void CompareWindow::loadFile(QString filename, QTreeWidget* tree)
{
}
