#include "DropLabel.hpp"
#include "../Global.hpp"
#include <QFileInfo>
#include <QMimeData>

DropLabel::DropLabel(QWidget* parent)
    : QLabel(parent)
{
}

void DropLabel::dragEnterEvent(QDragEnterEvent* event)
{
    bool Accept = false;

    // Accept only files
    if (event->mimeData()->hasUrls()) {
        // Don't accept more than 2 files
        int Size = event->mimeData()->urls().size();
        if (Size <= 2) {
            // Accept only files with the right extension
            Accept = true;
            for (int i = 0; i < Size; i++) {
                if (QFileInfo(event->mimeData()->urls().at(i).toLocalFile()).suffix().compare(QString(SOURCE_FILE_EXTENSION), Qt::CaseInsensitive) != 0) {
                    Accept = false;
                }
            }
        }
    }
    event->setAccepted(Accept);
}

void DropLabel::dropEvent(QDropEvent* event)
{
    // Add at least 1 URL, and 2 if a second one is provided
    this->URL.prepend(event->mimeData()->urls().at(0));
    if (event->mimeData()->urls().size() == 2) {
        this->URL.prepend(event->mimeData()->urls().at(1));
    }

    // Can handle only 2 files
    if (URL.size() > 2) {
        this->URL.resize(2);
    }

    // Nonsense to compare a file with itself
    if ((URL.size() == 2) && (URL.at(0) == URL.at(1))) {
        URL.takeFirst();
    }

    // Update label
    setText(URL.at(0).toLocalFile());
    if (URL.size() == 2) {
        setText(QString("%1\n%2").arg(URL.at(0).toLocalFile(), URL.at(1).toLocalFile()));
    }

    // Emit a signal according to the available URLs
    if (URL.size() == 2) {
        emit filesAvailable();
    }
    else {
        emit filesNotAvailable();
    }
}

QList<QUrl> DropLabel::urls() const
{
    QList<QUrl> Urls;
    Urls << URL.at(0) << URL.at(1);
    return Urls;
}
