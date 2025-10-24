#include "Dropbox.hpp"
#include "../Global.hpp"
#include <QFileInfo>
#include <QMimeData>
#include <QUrl>

DropBox::DropBox(QWidget* parent)
    : QGroupBox(parent)
{
}

void DropBox::dragEnterEvent(QDragEnterEvent* event)
{
    bool Accept = false;
    if (event->mimeData()->hasUrls()) {
        // Create some vars to inspect the candidate URL(s)
        int       Count = event->mimeData()->urls().size();
        QString   Filename1;
        QString   Filename2;
        QFileInfo FileInfo1;
        QFileInfo FileInfo2;
        QString   Suffix1;
        QString   Suffix2;

        // Proceed according to the number of provided URL
        Accept = true;
        switch (Count) {
            case 2:
                Filename2 = event->mimeData()->urls().at(1).toLocalFile();
                FileInfo2.setFile(Filename2);
                Suffix2 = FileInfo2.suffix();
                Accept  = Suffix2.compare(SOURCE_FILE_EXTENSION, Qt::CaseInsensitive) == 0;

            default:
                Filename1 = event->mimeData()->urls().at(0).toLocalFile();
                FileInfo1.setFile(Filename1);
                Suffix1  = FileInfo1.suffix();
                Accept  &= Suffix1.compare(SOURCE_FILE_EXTENSION, Qt::CaseInsensitive) == 0;
        }
    }
    event->setAccepted(Accept);
}

void DropBox::dropEvent(QDropEvent* event)
{
    QList<QString> Files;
    QList<QUrl>    Urls = event->mimeData()->urls();
    while (!Urls.isEmpty()) {
        Files << Urls.takeFirst().toLocalFile();
    }
    emit filesDropped(Files);
}
