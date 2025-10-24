#ifndef DROPLABEL_HPP
#define DROPLABEL_HPP

#include <QDragEnterEvent>
#include <QDropEvent>
#include <QLabel>
#include <QList>
#include <QUrl>

class DropLabel: public QLabel
{
    Q_OBJECT

  public:
    DropLabel(QWidget* parent);
    void        dragEnterEvent(QDragEnterEvent* event) override;
    void        dropEvent(QDropEvent* event) override;
    QList<QUrl> urls() const;

  private:
    QList<QUrl> URL;

  signals:
    void filesAvailable();
    void filesNotAvailable();
};

#endif // DROPLABEL_HPP
