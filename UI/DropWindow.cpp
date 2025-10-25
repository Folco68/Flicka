#include "DropWindow.hpp"
#include "../Global.hpp"
#include "CompareWindow.hpp"
#include "DropBox.hpp"
#include "ui_DropWindow.h"
#include <QFileInfo>
#include <QMessageBox>

DropWindow::DropWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::DropWindow)
{
    ui->setupUi(this);
    ui->GroupDrop->setTitle(QString("Drop here the %1 files you want to compare").arg(SOURCE_FILE_EXTENSION));
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
    // One or two files were dropped
    // By Drag'n Drop design, if two files were dropped, their URLs are different
    int     Count = files.size();
    QString Text1 = ui->LabelFilename1->text();
    QString Text2 = ui->LabelFilename2->text();
    QString Filename1;
    QString Filename2;

    switch (Count) {
        case 2:
            // No need to check if there is a duplication, because the two files will replace the current ones
            Filename2 = files.at(1);
            ui->LabelFilename2->setText(ui->LabelFilename1->text());
            ui->LabelFilename1->setText(Filename2);

            // Update vars
            Text1 = ui->LabelFilename1->text();
            Text2 = ui->LabelFilename2->text();

        default:
            // Check that we won't end up with twice the same file
            Filename1 = files.at(0);
            if (Filename1 != Text1) {
                ui->LabelFilename2->setText(ui->LabelFilename1->text());
                ui->LabelFilename1->setText(Filename1);
            }
    }

    // Update compare button
    if (!ui->LabelFilename1->text().isEmpty() && !ui->LabelFilename2->text().isEmpty()) {
        ui->ButtonCompare->setEnabled(true);
    }
}

void DropWindow::compare()
{
    hide();
    CompareWindow* CompareWindow = new class CompareWindow(ui->LabelFilename1->text(), ui->LabelFilename2->text(), this);
    CompareWindow->exec();
    delete CompareWindow;
    show();
}
