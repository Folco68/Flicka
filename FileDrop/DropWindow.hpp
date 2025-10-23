#ifndef DROPWINDOW_HPP
#define DROPWINDOW_HPP

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

    void compare() const;
};

#endif // DROPWINDOW_HPP
