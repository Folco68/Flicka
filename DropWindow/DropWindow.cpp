#include "DropWindow.hpp"
#include "../Compare/CompareWindow.hpp"
#include "../Global.hpp"
#include "DropBox.hpp"
#include "ui_DropWindow.h"
#include <QFileInfo>
#include <QMessageBox>

DropWindow::DropWindow(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::DropWindow)
{
    ui->setupUi(this);
    ui->LabelMessage->setText(QString("Drop here the %1 files you want to compare").arg(SOURCE_FILE_EXTENSION));
    ui->LabelFilename1->clear();
    ui->LabelFilename2->clear();
    setWindowTitle(QString("%1 - Files selection").arg(APPLICATION_NAME));

    // Connections
    connect(ui->GroupDrop, &DropBox::filesDropped, this, [this](QList<QString> files) { filesDropped(files); });
    connect(ui->ButtonCompare, &QPushButton::clicked, this, [this]() { compare(); });
}

DropWindow::~DropWindow()
{
    delete ui;
}

void DropWindow::filesDropped(QList<QString> files)
{
}

void DropWindow::compare()
{
    hide();
    CompareWindow* CompareWindow = new class CompareWindow(this);
    CompareWindow->exec();
    delete CompareWindow;
    show();
}
