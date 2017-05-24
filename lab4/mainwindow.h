#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lift.h"

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

    void on_floor4_clicked();

    void on_floor5_clicked();

    void on_b1_clicked();

    void on_b2_clicked();

    void on_b3_clicked();

    void on_b4_clicked();

    void on_b5_clicked();

private:
    Ui::MainWindow *ui;
    lift lft;
};

#endif // MAINWINDOW_H
