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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_floor1_clicked()
{
    //поменять цвет кнопки или текста
    ui->text->append("Нажата кнопка вызова на первом этаже....");

}

void MainWindow::on_floor2_clicked()
{
    ui->text->append("Нажата кнопка вызова на втором этаже....");
}

void MainWindow::on_floor3_clicked()
{
    ui->text->append("Нажата кнопка вызова на третьем этаже....");
}

void MainWindow::on_floor4_clicked()
{
    ui->text->append("Нажата кнопка вызова на четвертом этаже....");
}

void MainWindow::on_floor5_clicked()
{
    ui->text->append("Нажата кнопка вызова на пятом этаже....");
}
