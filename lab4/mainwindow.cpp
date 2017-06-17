#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "lift.h"
#include "doors.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lft.set_log(ui->text);
    lft.set_labels(ui->stage_doors, ui->stage_lift, ui->table);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_floor1_clicked()
{
    //поменять цвет кнопки или текста
    ui->text->append("Нажата кнопка вызова на первом этаже....");
    lft.get_order(1);

}

void MainWindow::on_floor2_clicked()
{
    ui->text->append("Нажата кнопка вызова на втором этаже....");
    lft.get_order(2);
}

void MainWindow::on_floor3_clicked()
{
    ui->text->append("Нажата кнопка вызова на третьем этаже....");
    lft.get_order(3);
}

void MainWindow::on_floor4_clicked()
{
    ui->text->append("Нажата кнопка вызова на четвертом этаже....");
    lft.get_order(4);
}

void MainWindow::on_floor5_clicked()
{
    ui->text->append("Нажата кнопка вызова на пятом этаже....");
    lft.get_order(5);
}


void MainWindow::on_b1_clicked()
{
    ui->text->append("Пассажир в лифте желает на первый этаж....");
    lft.get_order(1);
}

void MainWindow::on_b2_clicked()
{
    ui->text->append("Пассажир в лифте желает на второй этаж....");
    lft.get_order(2);
}

void MainWindow::on_b3_clicked()
{
    ui->text->append("Пассажир в лифте желает на третий этаж....");
    lft.get_order(3);
}

void MainWindow::on_b4_clicked()
{
    ui->text->append("Пассажир в лифте желает на четвертый этаж....");
    lft.get_order(4);
}

void MainWindow::on_b5_clicked()
{
    ui->text->append("Пассажир в лифте желает на пятый этаж....");
    lft.get_order(5);
}
