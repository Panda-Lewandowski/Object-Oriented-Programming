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
    void on_floor1_clicked();

    void on_floor2_clicked();

    void on_floor3_clicked();

    void on_floor_group_clicked();

    void on_floor4_clicked();

    void on_pushButton_5_clicked();

    void on_floor5_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
