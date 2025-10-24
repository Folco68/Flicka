#ifndef COMPAREWINDOW_HPP
#define COMPAREWINDOW_HPP

#include <QDialog>

namespace Ui {
class CompareWindow;
}

class CompareWindow: public QDialog
{
    Q_OBJECT

  public:
    explicit CompareWindow(QWidget* parent = nullptr);
    ~CompareWindow();

  private:
    Ui::CompareWindow* ui;
};

#endif // COMPAREWINDOW_HPP
