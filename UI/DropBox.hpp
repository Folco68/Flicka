#ifndef DROPBOX_HPP
#define DROPBOX_HPP

#include <QDragEnterEvent>
#include <QDropEvent>
#include <QGroupBox>
#include <QList>
#include <QString>
#include <QWidget>

class DropBox: public QGroupBox
{
    Q_OBJECT

  public:
    DropBox(QWidget* parent);
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dropEvent(QDropEvent* event) override;

  signals:
    void filesDropped(QList<QString> files);
};

#endif // DROPBOX_HPP
