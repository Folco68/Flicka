#include "DropWindow.hpp"
#include "DropLabel.hpp"
#include "ui_DropWindow.h"
#include <QFileInfo>

DropWindow::DropWindow(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::DropWindow)
{
    ui->setupUi(this);
    adjustSize();

    // Connections
    connect(ui->LabelDrop, &DropLabel::filesAvailable, this, [this] { ui->ButtonCompare->setEnabled(true); });
    connect(ui->LabelDrop, &DropLabel::filesNotAvailable, this, [this]() { ui->ButtonCompare->setEnabled(false); });
    connect(ui->ButtonCompare, &QPushButton::clicked, this, [this]() { compare(); });
}

DropWindow::~DropWindow()
{
    delete ui;
}

void DropWindow::compare() const
{
    // Safety check: both files must exist and have the right type
    QList<QUrl> Urls = ui->LabelDrop->urls();
    QFileInfo   File1(Urls.at(0).toLocalFile());
    QFileInfo   File2(Urls.at(1).toLocalFile());
}
