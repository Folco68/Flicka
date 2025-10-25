#ifndef COMPAREWINDOW_HPP
#define COMPAREWINDOW_HPP

#include <QDialog>
#include <QListWidget>
#include <QString>

namespace Ui {
class CompareWindow;
}

class CompareWindow: public QDialog
{
    Q_OBJECT

  public:
    explicit CompareWindow(QString filename1, QString filename2, QWidget* parent = nullptr);
    ~CompareWindow();

  private:
    Ui::CompareWindow* ui;
    QString            File1;
    QString            File2;

    void loadFiles();
    void loadFile(QString filename, QListWidget* list);
};

#endif // COMPAREWINDOW_HPP
