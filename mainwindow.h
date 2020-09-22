#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_calculateButton_clicked();

    void on_setUnsetButton_clicked();

    void on_setZeroButton_clicked();

    void on_swapButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
