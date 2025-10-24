#ifndef DROPWINDOW_HPP
#define DROPWINDOW_HPP

#include <QList>
#include <QString>
#include <QWidget>

namespace Ui {
class DropWindow;
}

class DropWindow: public QWidget
{
    Q_OBJECT

  public:
    explicit DropWindow(QWidget* parent = nullptr);
    ~DropWindow();

  private:
    Ui::DropWindow* ui;

    void filesDropped(QList<QString> files);
    void compare();
};

#endif // DROPWINDOW_HPP
